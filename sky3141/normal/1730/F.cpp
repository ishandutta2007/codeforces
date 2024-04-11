#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 5000 + 9, K = 8, INF = 1000000000;

int n, k;
int f[N][1 << K];
int p[N];
int fwt[N];

inline int lowbit(int x)
{
    return x & (-x);
}

void add(int pos, int val)
{
    while (pos <= n)
    {
        fwt[pos] += val;
        pos += lowbit(pos);
    }
}

int query(int pos)
{
    int res = 0;
    while (pos)
    {
        res += fwt[pos];
        pos -= lowbit(pos);
    }
    return res;
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        p[x] = i;
    }
    memset(f, 0x3f, sizeof(f));
    f[0][0] = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < (1 << min(k, n - i - 1)); ++j)
        {
            for (int t = 0; t < min(k, n - i - 1); ++t)
            {
                if (~j & (1 << t))
                {
                    int cnt = query(n) - query(p[i + 2 + t]);
                    for (int x = 0; x < k; ++x)
                    {
                        if (j & (1 << x) && p[i + 2 + x] > p[i + 2 + t])
                            ++cnt;
                    }
                    f[i][j | (1 << t)] = min(f[i][j | (1 << t)], f[i][j] + cnt);
                }
            }
            {
                int cnt = query(n) - query(p[i + 1]);
                for (int x = 0; x < k; ++x)
                {
                    if (j & (1 << x) && p[i + 2 + x] > p[i + 1])
                        ++cnt;
                }
                int t = j;
                int c = 0;
                while (t & 1)
                {
                    t >>= 1;
                    ++c;
                }
                f[i + c + 1][t >> 1] = min(f[i + c + 1][t >> 1], f[i][j] + cnt);
            }
        }
        add(p[i + 1], 1);
    }
    // for (int i = 0; i <= n; ++i)
    // {
    //     for (int j = 0; j < (1 << k); ++j)
    //     {
    //         cout << "f[" << i << "][" << j << "] = " << f[i][j] << endl;
    //     }
    //     cout << endl;
    // }
    cout << f[n][0] << '\n';
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