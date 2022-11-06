#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;

int n;
int f[MAXN];
int a[MAXN];

inline int lowbit(int x)
{
    return x & (-x);
}

void add(int pos, int val)
{
    while (pos <= n)
    {
        f[pos] += val;
        pos += lowbit(pos);
    }
}

int query(int pos)
{
    int res = 0;
    while (pos)
    {
        res += f[pos];
        pos -= lowbit(pos);
    }
    return res;
}

void solve()
{
    cin >> n;
    fill(f, f + n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    LL ans = 0;
    for (int i = n; i >= 1; --i)
    {
        ans += query(a[i]);
        add(a[i], 1);
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