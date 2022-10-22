#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll MOD = 998244353;

long long modpow(long long x, long long n)
{
    long long res = 1, r = x;
    while (n)
    {
        if (n & 1)
        {
            res = res * r % MOD;
        }
        r = r * r % MOD;
        n >>= 1;
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
        {
            fact[i] = fact[i - 1] * i % MOD;
        }
        ifact[maxn] = modpow(fact[maxn], MOD - 2);
        for (int i = maxn - 1; i >= 0; i--)
        {
            ifact[i] = ifact[i + 1] * (i + 1) % MOD;
        }
    }

    long long com(int n, int k)
    {
        if (k > n || k < 0)
        {
            return 0;
        }
        return (fact[n] * ifact[k] % MOD) * ifact[n - k] % MOD;
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        ll a[100005];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int l = 0, r = n;
        int cl = 0, cr = 0;
        while(l < n && a[l] == 0)
        {
            cl++;
            l++;
        }
        if(l == n)
        {
            ll ans = 1;
            for(int i = 0; i < n - 1; i++)
            {
                ans = ans * 2 % MOD;
            }
            cout << ans << endl;
            continue;
        }
        while(a[r - 1] == 0)
        {
            cr++;
            r--;
        }
        vector<P> v;
        ll sl = 0, sr = 0;
        while(l < r)
        {
            if(sl <= sr)
            {
                sl += a[l++];
            }
            else
            {
                sr += a[--r];
            }
            if(sl == sr)
            {
                int dl = 0, dr = 0;
                while(l < r && a[l] == 0)
                {
                    l++;
                    dl++;
                }
                if(l == r)
                {
                    v.push_back(P(dl, -1));
                    break;
                }
                while(a[r - 1] == 0)
                {
                    r--;
                    dr++;
                }
                v.push_back(P(dl, dr));
            }
        }
        Combination com(n + 1);
        ll ans = 1;
        for(int i = 1; i <= min(cl, cr); i++)
        {
            ans = (ans + com.com(cl, i) * com.com(cr, i)) % MOD;
        }
        for(P p : v)
        {
            if(p.second == -1)
            {
                for(int i = 0; i <= p.first; i++)
                {
                    ans = ans * 2 % MOD;
                }
            }
            else
            {
                ll d = 0;
                for(int i = 0; i <= min(p.first, p.second) + 1; i++)
                {
                    d = (d + com.com(p.first + 1, i) * com.com(p.second + 1, i)) % MOD;
                }
                ans = ans * d % MOD;
            }
        }
        cout << ans << endl;
    }
}