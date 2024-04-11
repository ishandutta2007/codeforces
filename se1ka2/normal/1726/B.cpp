#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        if (n > m || (!(n % 2) && m % 2))
        {
            cout << "No" << endl;
        }
        else if(n % 2)
        {
            cout << "Yes" << endl;
            for (int i = 0; i < n - 1; i++)
            {
                cout << 1 << " ";
            }
            cout << m - (n - 1) << endl;
        }
        else
        {
            cout << "Yes" << endl;
            for(int i = 0; i < n - 2; i++)
            {
                cout << 1 << " ";
            }
            cout << (m - (n - 2)) / 2 << " " << (m - (n - 2)) / 2 << endl;
        }
    }
}