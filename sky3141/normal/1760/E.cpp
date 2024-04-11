#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), s(n + 1);
    LL ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        if (a[i] == 0)
            ans += s[i];
    }
    LL pans = ans;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 0)
        {
            ans = max(ans, pans - s[i] + (n - i) - (s[n] - s[i]));
        }
        else
        {
            ans = max(ans, pans + s[i - 1] - (n - i) + (s[n] - s[i]));
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