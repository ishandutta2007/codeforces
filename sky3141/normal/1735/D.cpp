#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 1000 + 9, MAXK = 20 + 9;

int n, k;
int a[MAXN][MAXK];

unsigned hid(int a[])
{
    unsigned res = 0;
    for (int i = 0; i < k; ++i)
    {
        res = res * 3 + a[i];
    }
    return res;
}

unsigned id(int x)
{
    return hid(a[x]);
}

void solve()
{
    cin >> n >> k;
    map<unsigned, int> mp;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            cin >> a[i][j];
        }
        mp[id(i)] = i;
    }
    vector<int> cnt(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int t[MAXK];
            for (int u = 0; u < k; ++u)
            {
                if (a[i][u] == a[j][u])
                {
                    t[u] = a[i][u];
                }
                else
                {
                    t[u] = 3 - a[i][u] - a[j][u];
                }
            }
            auto it = mp.find(hid(t));
            if (it != mp.end())
            {
                ++cnt[i]; ++cnt[j]; ++cnt[it->second];
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cnt[i] /= 3;
    }
    LL ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans += (LL)cnt[i] * (cnt[i] - 1) / 2;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
}