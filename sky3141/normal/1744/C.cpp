#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    int fg;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'g')
        {
            fg = i;
            break;
        }
    }
    int ans = 0;
    int lst = 2 * n;
    for (int i = n - 1; i >= 0; --i)
    {
        if (s[i] == 'g')
            lst = i;
        if (s[i] == c)
        {
            ans = max(ans, min(lst - i, fg + n - i));
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}