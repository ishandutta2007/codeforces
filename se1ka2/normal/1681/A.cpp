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
        int a[52];
        int l = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            l = max(l, a[i]);
        }
        int m;
        cin >> m;
        int b[52];
        int r = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
            r = max(r, b[i]);
        }
        if (l >= r)
        {
            cout << "Alice" << endl;
        }
        else
        {
            cout << "Bob" << endl;
        }
        if (l <= r)
        {
            cout << "Bob" << endl;
        }
        else
        {
            cout << "Alice" << endl;
        }
    }
}