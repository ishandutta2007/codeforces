#include <iostream>
#include <algorithm>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9, N = 200000, mod = 998244353;

int n, m;
int cnt[MAXN], s[MAXN];
int t[MAXN];
int fac[MAXN], facinv[MAXN];

int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (LL) res * a % mod;
        a = (LL) a * a % mod;
        b >>= 1;
    }
    return res;
}

inline int inv(int x)
{
    return qpow(x, mod - 2);
}

void init()
{
    fac[0] = 1;
    for (int i = 1; i <= N; ++i)
    {
        fac[i] = (LL)fac[i - 1] * i % mod;
    }
    facinv[N] = inv(fac[N]);
    for (int i = N; i >= 1; --i)
    {
        facinv[i - 1] = (LL) facinv[i] * i % mod;
    }
}

inline int lowbit(int x)
{
    return x & (-x);
}

void change(int pos, int val)
{
    for (int i = pos; i <= N; i += lowbit(i))
    {
        s[i] += val;
    }
}

int query(int pos)
{
    int res = 0;
    for (int i = pos; i; i -= lowbit(i))
    {
        res += s[i];
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        ++cnt[tmp];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> t[i];
    }
    for (int i = 1; i <= N; ++i)
    {
        change(i, cnt[i]);
    }
    init();
    LL ans = 0;
    LL cur = fac[n];
    for (int i = 1; i <= N; ++i)
    {
        cur = cur * facinv[cnt[i]] % mod;
    }
    for (int i = 0; i < n && i < m; ++i)
    {
        cur = cur * inv(n - i) % mod;
        ans += cur * query(t[i] - 1);
        ans %= mod;
        if (cnt[t[i]] == 0)
            break;
        cur = cur * cnt[t[i]] % mod;
        change(t[i], -1);
        --cnt[t[i]];
    }
    if (m > n)
    {
        bool flag = true;
        for (int i = 1; i <= N; ++i)
        {
            if (cnt[i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            ans = (ans + 1) % mod;
        }
    }
    cout << ans << '\n';

    return 0;
}