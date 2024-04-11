#include <iostream>

using namespace std;

int a[55];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    int n, first, last;
    int tmp;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        cin >> n;
        for (int j = 1; j <= n; ++j)
            cin >> a[j];
        if (a[1] == n && a[n] == 1)
        {
            cout << 3 << '\n';
        }
        else if(a[1] == 1 || a[n] == n)
        {
            bool flag = true;
            for (int j = 1; j <= n; ++j)
            {
                if (a[j] != j) flag = false;
            }
            cout << (flag ? 0 : 1) << '\n';
        }
        else
        {
            cout << 2 << '\n';
        }
    }

    return 0;
}