#include <iostream>

using namespace std;

int main()
{
    int n, rem;
    cin >> n;
    rem = (n % 4);
    if(rem == 0)
    {
        cout << 0 << endl;
        cout << n/2 << " ";
        for (int i = 0; i < n/4; i++) {
            cout << 4*i + 1 << " " << 4*i + 4;
            if(i != n/4 - 1) cout << " ";
        }
    }
    if(rem == 1)
    {
        cout << 1 << endl;
        cout << n/2 + 1 << " ";
        cout << 1 << " ";
        for (int i = 0; i < n/4; i++) {
            cout << 4*i + 2 << " " << 4*i + 5;
            if(i != n/4 - 1) cout << " ";
        }
    }
    if(rem == 2)
    {
        cout << 1 << endl;
        cout << n/2 << " ";
        for (int i = 0; i < n/4; i++) {
            cout << 4*i + 1 << " " << 4*i + 4 << " ";
        }
        cout << n;
    }
    if(rem == 3)
    {
        cout << 0 << endl;
        cout << n/2 + 1 << " ";
        cout << 1 << " ";
        for (int i = 0; i < n/4; i++) {
            cout << 4*i + 2 << " " << 4*i + 5 << " ";
        }
        cout << n - 1;
    }
}