#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n % 2)
        {
            cout << 1 << " ";
            for (int i = n - 2; i >= 2; i--)
            {
                cout << i << " ";
            }
            cout << n - 1 << " " << n << endl;
        }
        else
        {
            for (int i = n - 2; i >= 1; i--)
            {
                cout << i << " ";
            }
            cout << n - 1 << " " << n << endl;
        }
    }
}