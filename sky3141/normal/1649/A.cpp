#include <iostream>

using namespace std;

constexpr int MAXN = 100 + 9;

int a[MAXN];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    int s = 0, e = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 0)
        {
            s = i;
            break;
        }
    }
    for (int i = n; i >= 1; --i)
    {
        if (a[i] == 0)
        {
            e = i;
            break;
        }
    }
    if (s == 0)
    {
        cout << "0\n";
    }
    else
    {
        cout << e - s + 2 << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        solve();
    }


    return 0;
}