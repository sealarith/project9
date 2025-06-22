//factorizing polynomial
#include <iostream> 
#include <fstream>
#include <cstdlib>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

int main()
{
    int num1, num2, num3, num4; 
    cout << "\nKeep a space between each numbers.\n";
    cout << "Enter the 4 number: ";
    cin >> num1 >> num2 >> num3 >> num4;
    cout << "\nPolynomial Entered: ";
    cout << num1 << "x^3 ";
    cout << showpos << num2 << "x^2 ";
    cout << num3 << "x ";
    cout << num4 << endl;
    int result, a = 0, b = 0, c;
    ofstream outFile;
    outFile.open("Account.txt");
    int arr2[20];
    double PossibleRationalRoots[20];
    stack<int>firstStack;
    cout << "p = ";
    for (int u = 1; u <= abs(num4); u++)
    {
        result = num4 % u; 
        if (result == 0 )
        {
            cout << u << " ";
            firstStack.push(u);
            cout << u * (-1) << " ";
            //firstStack.push(-u);          // we don't need this cuz when we do p / q we need only 1 to get all possibility roots
            a++;
            outFile << u << " ";
            outFile << u * (-1) << " ";
        }
    }
    //outFile << endl << a * 2;
    outFile << endl;
    cout << endl;
    int j = 0;
    cout << "q = ";
    for (int i = 1; i <= abs(num1); i++)
    {
        result = num1 % i;
        if (result == 0 )
        {
            cout << i << " ";
            arr2[j] = i;
            cout << i * (-1) << " ";
            j++;
            arr2[j] = -i;
            b++;
            j++;
            outFile << i << " ";
            outFile << i * (-1) << " ";
        }
    }
    /*Stack deosn't work because once the stack is empty we can use it again to divde with other numbers
    can I use 1 stack and 1 array ? */
    cout << "\n";
    int w = 0;
    while (!firstStack.empty())
    {
        int p = firstStack.top();
        //cout << p << " ";
        int k = 0;
        while (arr2[k] != 0)
        {
            int q = arr2[k];
            //cout << q << " ";
            double root = static_cast<double> (p) / q;
            PossibleRationalRoots[w] = root;
            //cout << endl << "-> " << PossibleRationalRoots[w] << endl; 
            k++;
            w++;
        }
        firstStack.pop();
    }
    cout << "\n";
    double array[20] = {0};
    for (int i = 0; i < 20; i++)
    {
        //cout << PossibleRationalRoots[i] << " ";
        double total = 0;
        total = ((num1 * (pow(PossibleRationalRoots[i], 3))) + (num2 * (pow(PossibleRationalRoots[i], 2))) + (num3 * (pow(PossibleRationalRoots[i], 1))) + num4);
        if (total == 0)
        {
            //cout << PossibleRationalRoots[i] << " ";
            array[i] = PossibleRationalRoots[i];
        }
    }
    cout << "please convert the decimal to fraction.\n";
    cout << "use these solution to solve for the factors: \n";
    int k = 0;
    for (int i = 0; i < 20; i++)
    {
        if (array[i] != 0.0)
        {
            cout << showpos;                        //this enable showing sign for positive numbers
            cout << "x = " << array[i] << endl;
        }
        else
        {
            k++;
        }
    }
    if (k == 20)
    {
        cout << "\nNo rational roots found. The polynomial may not factor over the rationals.\n";
        cout << "You may need to use other methods like completing the square, the quadratic formula (if degree 2), or numerical/root approximation techniques.\n";
    }

    

    //outFile << endl << b * 2;
    outFile.close();
    cout << "\n";
    /*
    ifstream inFile;
    inFile.open("Account.txt");
    if (!inFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    string line; // Declare 'line' as std::string

    while (getline(inFile, line)) // Correct usage of std::getline
    {
        cout << line << endl;
    }*/







    return 0;
}