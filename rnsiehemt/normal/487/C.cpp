#include <cstdio>

typedef long long ll;

int N;
ll Mod;

ll sqr(ll x) {
    return (x*x)%Mod;
}

ll modexp(ll b, ll e) {
    if (e == 0ll) return 1ll;
    else if (e%2ll) return (b * sqr(modexp(b, e/2ll))) % Mod;
    else return sqr(modexp(b, e/2ll));
}

int main()
{
    scanf("%d", &N);
    Mod = ll(N);
    if (N == 1) printf("YES\n1\n");
    else if (N == 4) printf("YES\n1\n3\n2\n4\n");
    else {
        for (int i = 2; i < N; i++) {
            if (N%i == 0) {
                printf("NO\n");
                return 0;
            }
        }
        printf("YES\n1\n");
        for (int i = 1; i < N-1; i++) {
            printf("%d\n", int((ll(i+1)*modexp(ll(i), Mod-2))%Mod));
        }
        printf("%d\n", N);
    }
}