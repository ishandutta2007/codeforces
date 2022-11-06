#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

using LL = long long;

constexpr int MAXN = 100000 + 9;

int n, m;
int a[MAXN];
// int s[MAXN];
// int f[MAXN];
LL f[MAXN];

// inline int lowbit(int x)
// {
//     return x & -x;
// }

// void add(int pos, int val)
// {
//     while (pos <= n)
//     {
//         f[pos] += val;
//         pos += lowbit(pos);
//     }
// }

// int query(int pos)
// {
//     int res = 0;
//     while (pos)
//     {
//         res += f[pos];
//         pos -= lowbit(pos);
//     }
//     return res;
// }

// int qlr(int l, int r)
// {
//     return query(r) - query(l - 1);
// }

void solve()
{
    cin >> n >> m;
    LL ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        // s[i] = s[i - 1];
        f[i] = f[i - 1] + 1;
        if (a[i] != a[i - 1])
        {
            // ++s[i];
            f[i] += i - 1;
        }
        ans += f[i];
    }
    // cout << ans << endl;
    for (int i = 0; i < m; ++i)
    {
        int pos, x;
        cin >> pos >> x;
        if (a[pos] == a[pos - 1])
        {
            ans += (LL)(n - pos + 1) * (pos - 1);
        }
        if (a[pos] == a[pos + 1])
        {
            ans += (LL)(n - pos) * pos;
        }
        a[pos] = x;
        if (a[pos] == a[pos - 1])
        {
            ans -= (LL)(n - pos + 1) * (pos - 1);
        }
        if (a[pos] == a[pos + 1])
        {
            ans -= (LL)(n - pos) * pos;
        }
        cout << ans << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}