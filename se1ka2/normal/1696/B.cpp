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
        int a[200005];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int l = 0;
        while (l < n && a[l] == 0)
        {
            l++;
        }
        int r = n;
        while (r > 0 && a[r - 1] == 0)
        {
            r--;
        }
        if (r < l)
        {
            cout << 0 << endl;
            continue;
        }
        bool f = true;
        for (int i = l; i < r; i++)
        {
            if (a[i] == 0)
            {
                f = false;
            }
        }
        if (f)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 2 << endl;
        }
    }
}