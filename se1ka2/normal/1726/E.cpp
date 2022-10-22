#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

long long modpow(long long x, long long n)
{
    long long res = 1;
    long long mul = x;
    while (n)
    {
        if (n % 2)
            res = res * mul % MOD;
        mul = mul * mul % MOD;
        n /= 2;
    }
    return res;
}

struct Combination
{
    int maxn;
    std::vector<long long> fact;
    std::vector<long long> ifact;

    Combination(int maxn) : maxn(maxn)
    {
        fact.resize(maxn + 1);
        ifact.resize(maxn + 1);
        fact[0] = 1;
        for (int i = 1; i <= maxn; i++)
            fact[i] = fact[i - 1] * i % MOD;
        ifact[maxn] = modpow(fact[maxn], MOD - 2);
        for (int i = maxn - 1; i >= 0; i--)
            ifact[i] = ifact[i + 1] * (i + 1) % MOD;
    }

    long long com(int n, int k)
    {
        if (k > n || k < 0)
            return 0;
        return (fact[n] * ifact[k] % MOD) * ifact[n - k] % MOD;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Combination com(n);
        ll f[300005];
        f[0] = f[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            f[i] = (f[i - 1] + f[i - 2] * (i - 1)) % MOD;
        }
        ll g[300005];
        g[1] = 1;
        for (int i = 3; i <= n; i += 2)
        {
            g[i] = g[i - 2] * i % MOD;
        }
        ll h[300005];
        h[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            h[i] = h[i - 1] * 2 % MOD;
        }
        ll ans = 0;
        for (int k = 0; k * 4 <= n; k++)
        {
            if (k == 0)
            {
                ans = (ans + com.com(n - k * 2, k * 2) * f[n - k * 4]) % MOD;
            }
            else
            {
                ans = (ans + com.com(n - k * 2, k * 2) * g[k * 2 - 1] % MOD * h[k] % MOD * f[n - k * 4]) % MOD;
            }
        }
        cout << ans << "\n";
    }
}