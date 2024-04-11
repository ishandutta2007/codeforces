#include <cstdio>

typedef long long ll;

const ll Mod = 1000000007ll;

ll N, M, G;
ll f[200005];
ll ans;

ll sqr(ll a) {
    return (a*a) % Mod;
}

ll power(ll b, ll e) {
    if (e == 0ll) return 1ll;
    else if (e % 2ll) return (power(b, e-1ll) * b) % Mod;
    else return sqr(power(b, e/2ll));
}

int main()
{
    scanf("%I64d%I64d%I64d", &N, &M, &G);

    f[0] = 1ll; for (ll i = 1ll; i < 200003ll; i++) f[i] = (f[i-1ll] * ll(i)) % Mod;

    if (M == 0ll) {
        if ((N % 2ll) == (1ll-G)) ans = 1ll;
    }
    else {
        for (ll i = 0ll; i <= N && i+1ll < N+M; i++) {
            if ((i % 2ll) == G) {
                ll num = f[(N-i) + (M-1ll)];
                ll den = (f[N-i] * f[M-1ll]) % Mod;
                ll deninv = power(den, Mod-2ll);
                ans = (ans + ((num * deninv) % Mod)) % Mod;
            }
        }
        if (M == 1ll && (N % 2ll) == (1ll-G)) ans = (ans + 1ll) % Mod;
    }

    printf("%I64d\n", ans);
}