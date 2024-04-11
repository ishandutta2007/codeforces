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
        int a[200005], b[200005];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        bool f = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > b[i] || (a[i] < b[i] && b[i] > b[(i + 1) % n] + 1))
            {
                f = false;
            }
        }
        if (f)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}