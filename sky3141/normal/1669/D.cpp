#include <iostream>
#include <algorithm>

using namespace std;

constexpr int MAXN = 100000 + 9;

int n;
char s[MAXN];

void solve()
{
    cin >> n;
    cin >> s;
    int r = 0, b = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'R')
        {
            ++r;
        }
        else if (s[i] == 'B')
        {
            ++b;
        }
        else
        {
            if (r == 0 && b != 0 || r != 0 && b == 0)
            {
                cout << "NO\n";
                return;
            }
            r = b = 0;
        }
    }
    if (r == 0 && b != 0 || r != 0 && b == 0)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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