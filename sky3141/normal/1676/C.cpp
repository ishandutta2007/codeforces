#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &s : a)
    {
        cin >> s;
    }
    auto df = [m](const string &x, const string &y)
    {
        int res = 0;
        for (int i = 0; i < m; ++i)
        {
            res += abs(x[i] - y[i]);
        }
        return res;
    };
    int ans = 1000000000;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            ans = min(ans, df(a[i], a[j]));
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