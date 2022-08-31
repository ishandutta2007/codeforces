#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200100;
const ll MOD = 1e9 + 7;

ll fac[MAXN];
ll ifac[MAXN];

ll mpow (ll b, ll e)
{
    if (e == 0) return 1;
    if (e == 1) return b;
    ll v = mpow (b, e / 2);
    v = (v * v) % MOD;
    if (e & 1) v = (v * b) % MOD;
    return v;
}

ll cho (ll N, ll K)
{
    if (N < K) return 0;
    ll res = fac[N];
    res = (res * ifac[K]) % MOD;
    res = (res * ifac[N-K]) % MOD;
    return res;
}

void gogo()
{
    int N, K;
    cin >> N >> K;

    ll res = 1;
    for (int i = 1; i <= N; i++)
    {
        // (N - (k - 1) * (i - 1)) C i / N C i
        ll v = N - (K - 1) * ((ll) i - 1);
        if (v < i) break;

        ll a1 = cho (v, i);
        ll a2 = cho (N, i);
        a1 = (a1 * mpow (a2, MOD - 2)) % MOD;
        res = (res + a1) % MOD;
    }
    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    fac[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fac[i] = (i * fac[i-1]) % MOD;
    ifac[MAXN-1] = mpow (fac[MAXN-1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--)
        ifac[i] = (i + 1) * (ifac[i+1]) % MOD;

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}