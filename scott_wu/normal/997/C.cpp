#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const int MAXN = 1000100;

int N;
struct st {
    int pow3;
    int v3;
};
st s[MAXN];

inline ll cpow (ll b, ll v = 1)
{
    ll c = b;
    if (N & (1 << 0))
        v = (v * c) % MOD;
    c = (c * c) % MOD;
    if (N & (1 << 1))
        v = (v * c) % MOD;
    c = (c * c) % MOD;
    if (N & (1 << 2))
        v = (v * c) % MOD;
    c = (c * c) % MOD;
    if (N & (1 << 3))
        v = (v * c) % MOD;
    c = (c * c) % MOD;
    if (N & (1 << 4))
        v = (v * c) % MOD;
    c = (c * c) % MOD;
    if (N & (1 << 5))
        v = (v * c) % MOD;
    c = (c * c) % MOD;
    if (N & (1 << 6))
        v = (v * c) % MOD;
    c = (c * c) % MOD;
    if (N & (1 << 7))
        v = (v * c) % MOD;
    c = (c * c) % MOD;
    if (N & (1 << 8))
        v = (v * c) % MOD;
    c = (c * c) % MOD;
    if (N & (1 << 9))
        v = (v * c) % MOD;
    c = (c * c) % MOD;
    if (N & (1 << 10))
        v = (v * c) % MOD;
    c = (c * c) % MOD;
    if (N & (1 << 11))
        v = (v * c) % MOD;
    c = (c * c) % MOD;
    if (N & (1 << 12))
        v = (v * c) % MOD;
    c = (c * c) % MOD;
    if (N & (1 << 13))
        v = (v * c) % MOD;
    c = (c * c) % MOD;
    if (N & (1 << 14))
        v = (v * c) % MOD;
    c = (c * c) % MOD;
    if (N & (1 << 15))
        v = (v * c) % MOD;
    c = (c * c) % MOD;
    if (N & (1 << 16))
        v = (v * c) % MOD;
    c = (c * c) % MOD;
    if (N & (1 << 17))
        v = (v * c) % MOD;
    c = (c * c) % MOD;
    if (N & (1 << 18))
        v = (v * c) % MOD;
    c = (c * c) % MOD;
    if (N & (1 << 19))
        v = (v * c) % MOD;
    return v;
}

ll inv (ll a, ll m = MOD)
{
    return ((a == 1) ? 1 : (m - inv (m % a, a) * m / a));
}

int main()
{
    cin >> N;
    if (N == 1)
    {
        cout << "3\n";
        return 0;
    }

    s[1].v3 = 1;
    for (int i = 2; i < N; i++)
        s[i].v3 = (s[i-1].v3 * (ll) (i - N - 1)) % MOD;
    ll ff = (s[N-1].v3 + MOD) % MOD;

    ff = inv(ff);
    ff = (ff * -3 * N) % MOD;
    for (int i = N-1; i >= 1; i--)
    {
        s[i].v3 = (s[i].v3 * ff) % MOD;
        ff = (ff * i) % MOD;
    }

    s[0].pow3 = 1;
    for (int i = 1; i <= N; i++)
        s[i].pow3 = (3 * (ll) s[i-1].pow3) % MOD;
    for (int i = 0; i < N; i++)
        s[i].pow3--;

    for (int i = 0; i < 10; i++)
    {
        int c = (N >> (2 * i)) & 3;
        if (i < 9)
        {
            if (c == 0)
            {
                for (int j = 1; j < N; j++)
                {
                    s[j].pow3 = (s[j].pow3 * (ll) s[j].pow3) % MOD;
                    s[j].pow3 = (s[j].pow3 * (ll) s[j].pow3) % MOD;
                }
            }
            else if (c == 1)
            {
                for (int j = 1; j < N; j++)
                {
                    s[j].v3 = (s[j].v3 * (ll) s[j].pow3) % MOD;
                    s[j].pow3 = (s[j].pow3 * (ll) s[j].pow3) % MOD;
                    s[j].pow3 = (s[j].pow3 * (ll) s[j].pow3) % MOD;
                }

            }
            else if (c == 2)
            {
                for (int j = 1; j < N; j++)
                {
                    s[j].pow3 = (s[j].pow3 * (ll) s[j].pow3) % MOD;
                    s[j].v3 = (s[j].v3 * (ll) s[j].pow3) % MOD;
                    s[j].pow3 = (s[j].pow3 * (ll) s[j].pow3) % MOD;
                }
            }
            else
            {
                for (int j = 1; j < N; j++)
                {
                    s[j].v3 = (s[j].v3 * (ll) s[j].pow3) % MOD;
                    s[j].pow3 = (s[j].pow3 * (ll) s[j].pow3) % MOD;
                    s[j].v3 = (s[j].v3 * (ll) s[j].pow3) % MOD;
                    s[j].pow3 = (s[j].pow3 * (ll) s[j].pow3) % MOD;
                }
            }
        }
        else
        {
            if (c == 0)
            {
            }
            else if (c == 1)
            {
                for (int j = 1; j < N; j++)
                {
                    s[j].v3 = (s[j].v3 * (ll) s[j].pow3) % MOD;
                }
            }
            else if (c == 2)
            {
                for (int j = 1; j < N; j++)
                {
                    s[j].pow3 = (s[j].pow3 * (ll) s[j].pow3) % MOD;
                    s[j].v3 = (s[j].v3 * (ll) s[j].pow3) % MOD;
                }
            }
            else
            {
                for (int j = 1; j < N; j++)
                {
                    s[j].v3 = (s[j].v3 * (ll) s[j].pow3) % MOD;
                    s[j].pow3 = (s[j].pow3 * (ll) s[j].pow3) % MOD;
                    s[j].v3 = (s[j].v3 * (ll) s[j].pow3) % MOD;
                }
            }
        }
    }

    ll res = 0;
    for (int i = 1; i < N; i++)
        res += s[i].v3;

    ll p3 = s[N].pow3;
    res -= 3 * cpow(p3 - 1);
    res += 2 * cpow(p3 - 3);
    res = - cpow(p3) - res;

    cout << ((res % MOD) + MOD) % MOD << "\n";
}