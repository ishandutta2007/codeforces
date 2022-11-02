#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
#define mod(x) ((x)%Mod)
typedef long long ll;
template <typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
template <typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }

const int MaxN = 4005;
const ll Mod = 1000*1000*1000+7;

void doadd(ll &a, ll b) { a = mod(a+b); }

int N;
ll ep[MaxN][MaxN], dp[MaxN][MaxN], eps[MaxN], dps[MaxN], ans, fact[MaxN], eiv[MaxN];

ll sqr(ll a) {
    return a*a;
}
ll exp(ll b, ll e) {
    if (!e) return 1;
    else if (e%2) return mod(mod(sqr(exp(b, e/2))) * b);
    else return mod(sqr(exp(b, e/2)));
}
ll choose(ll n, ll k) {
    return mod(mod(fact[n] * eiv[n-k]) * eiv[k]);
}

int main()
{
    fact[0] = 1;
    for (int i = 1; i < MaxN; i++) fact[i] = mod(fact[i-1] * i);
    for (int i = 0; i < MaxN; i++) eiv[i] = exp(fact[i], Mod-2);

    //printf("%lld %lld\n", exp(3, 4), exp(4, 3));
    //for (int i = 0; i <= 6; i++) printf("%lld%c\n", choose(6, i), " \n"[i == 6]);
    scanf("%d", &N);
    dp[0][0] = ep[0][0] = 1;
    for (int k = 0; k < N; k++) {
        for (int s = 0; s <= k; s++) {
            doadd(ep[k+1][s], mod(s * ep[k][s]));
            doadd(ep[k+1][s+1], ep[k][s]);
            doadd(eps[k], ep[k][s]);
        }
    }
    /*for (int k = 0; k < N; k++) {
        for (int s = 0; s <= k; s++) {
            printf("%lld%c", dp[k][s], " \n"[s == k]);
        }
    }*/
    /*for (int k = 0; k < N; k++) {
        for (int s = 0; s <= k; s++) {
            printf("%lld%c", ep[k][s], " \n"[s == k]);
        }
    }*/
    //for (int i = 0; i < N; i++)
        //doadd(ans, mod(eps[i] * dps[N - (i+1)]));
    for (int i = 0; i < N; i++) for (int j = i; j <= N-1; j++) {
        //printf("%d %d\n", N - (i+1), j-i);
        doadd(ans, mod(eps[j] * choose(N - (i+1), j-i)));
    }
    printf("%lld\n", ans);
}