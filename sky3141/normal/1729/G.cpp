#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 500 + 9, mod = 1000000007;

LL f[MAXN][MAXN];
bool g[MAXN][MAXN];
bool can[MAXN][MAXN];
// LL tmp[MAXN];

void solve()
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = " " + s;
    vector<int> a;
    for (int i = 1; i <= n + 1 - m; ++i)
    {
        if (s.substr(i, m) == t)
            a.push_back(i);
    }
    int dn = a.size();
    int tn = max(n, m) + 1;
    for (int i = 0; i <= tn; ++i)
    {
        for (int j = 0; j <= tn; ++j)
        {
            f[i][j] = 0;
            g[i][j] = false;
            can[i][j] = true;
        }
    }
    for (int i = 0; i < dn; ++i)
    {
        for (int j = 0; j < dn; ++j)
        {
            if (j >= i || a[i] - a[j] < m)
            {
                can[j][i] = false;
                continue;
            }
            for (int k = j + 1; k < i; ++k)
            {
                if (a[k] >= a[j] + m && a[k] <= a[i] - m)
                {
                    can[j][i] = false;
                    break;
                }
            }
        }
    }
    for (int cur = 0; cur < dn; ++cur)
    {
        for (int i = cur + 1; i >= 1; --i)
        {
            if (i == 1)
            {
                if (a[0] > a[cur] - m)
                {
                    f[i][cur] = 1;
                    g[i][cur] = true;
                }
                continue;
            }
            int l = 0, r = 0;
            LL tmp = 0;
            int t2 = 0;
            for (int j = 0; j <= cur; ++j)
            {
                while (can[r][j])
                {
                    tmp += f[i - 1][r];
                    t2 += g[i - 1][r];
                    ++r;
                }
                while (l < r && !can[l][j])
                {
                    tmp -= f[i - 1][l];
                    t2 -= g[i - 1][l];
                    ++l;
                }
                tmp += mod;
                tmp %= mod;
                f[i][j] = tmp;
                g[i][j] = t2;
            }
        }
    }
    if (dn == 0)
    {
        cout << "0 1\n";
        return;
    }
    for (int i = 1; i <= dn; ++i)
    {
        LL ans = 0;
        bool t = false;
        for (int j = 0; j < dn; ++j)
        {
            if (a[j] > a.back() - m)
            {
                t |= g[i][j];
                ans += f[i][j];
            }
        }
        if (t)
        {
            ans = (ans % mod + mod) % mod;
            cout << i << ' ' << ans << '\n';
            return;
        }
    }
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