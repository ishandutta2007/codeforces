#include <cstdio>

typedef long long ll;

const ll Mod = 1000000009ll;

ll N, M, K;

ll sqr(ll a) {
    return (a*a) % Mod;
}

ll pow(ll b, ll e) {
    if (e == 0ll) return 1ll;
    else if (e % 2ll) return (2ll * pow(b, e-1ll)) % Mod;
    else return sqr(pow(b, e/2ll));
}

int main()
{
    scanf("%I64d%I64d%I64d", &N, &M, &K);
    ll H = (N/K)*(K-1ll) + N-(N/K*K);
    if (M <= H) {
        printf("%I64d\n", M);
        return 0;
    }
    else {
        ll E = M-H;
        ll first = ((pow(2ll, E+1ll)+Mod-2ll) % Mod * K) % Mod;
        ll second = ((N-E*K)/K) * (K-1ll) + N - (N/K*K);
        printf("%I64d\n", (first + second) % Mod);
    }
}