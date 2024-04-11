#include <bits/stdc++.h>
typedef long long ll;
#define sz(x) ((int)((x).size()));
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
#define mod(x) ((x)%Mod)

const ll Mod = 1000000007;
int K;
ll c,s,k,d;

ll sqr(ll a) { return a*a; }
ll modexp(ll b, ll e) {
    if (!e) return 1;
    else if (e%2) return mod(mod(sqr(modexp(b, e/2))) * b);
    else return mod(sqr(modexp(b, e/2)));
}

int main()
{
    //printf("%lld %lld %lld\n", modexp(3, 3), modexp(3, 4), modexp(3, 5));
    scanf("%d", &K);
    d = 1ll;
    for (int i = 0; i < K; i++) {
        scanf("%lld", &c);
        //printf("%lld %lld\n", s, c);
        ll e = 1ll;
        for (ll j = 1; j <= s+c; j++) {
            e = (e*j)%Mod;
            if (j <= s) e = (e*modexp(j, Mod-2))%Mod;
            if (j <= c) e = (e*modexp(j, Mod-2))%Mod;
        }
        ll f = 1ll;
        for (ll j = 1; j <= s+c-1; j++) {
            f = (f*j)%Mod;
            if (j <= s-1) f = (f*modexp(j, Mod-2))%Mod;
            if (j <= c) f = (f*modexp(j, Mod-2))%Mod;
        }
        if (i) d = d*((e+Mod-f)%Mod) % Mod;
        //printf("%lld %lld %lld\n", e, f, d);
        s += c;
    }
    printf("%lld\n", d);
}