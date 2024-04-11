#include <cstdio>
#include <cstring>

typedef long long ll;

const ll M = 1000000007ll;

int N, K;
char s[100005];
ll ans;

ll add(ll a, ll b) {
    return (a+b)%M;
}

ll mult(ll a, ll b) {
    return (a*b)%M;
}

ll sqr(ll a) {
    return mult(a, a);
}

ll power(ll b, ll e) {
    if (e == 0ll) return 1ll;
    else if (e % 2ll) return mult(sqr(power(b, e/2ll)), b);
    else return sqr(power(b, e/2ll));
}

int main()
{
    scanf("%s %d", s, &K); N = strlen(s);
    
    { // find answer for a single copy string
        ll t = 1ll;
        for (int i = 0; i < N; i++) {
            if (s[i] == '0' || s[i] == '5') ans = add(ans, t);
            t = mult(t, 2ll);
        }
    }

    {
        ll num = add(power(2ll, ll(K)*ll(N)), M-1ll);
        // find modular inverse of denominator with fermat's little theorem and stuff
        // i.e. a^(-1) === a^(M-2) (mod M), M is prime
        ll deninv = power(add(power(2ll, ll(N)), M-1ll), M-2ll);
        ans = mult(ans, mult(num, deninv));
    }

    printf("%I64d\n", ans);
}