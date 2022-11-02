#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll p = 1000000007;

ll mod_exp(ll x, ll y) {
    ll ret = 1;
    while(y) {
        if(y & 1) ret = (ret * x) % p;
        x = (x * x) % p;
        y >>= 1;
    }
    return ret;
}

ll inv(ll x, ll y) {
    if(x == 1) return 1;
    return ((y * (-inv(y % x, x)) + 1) / x) % p;
}

int main() {
    ll n, m;
    scanf("%I64d%I64d", &n, &m);
    if(m == 1) {printf("%I64d\n", n + 1); return 0;}
    ll mi = inv(m - 1, p), mmn = mod_exp(2 * m - 1, n), mn = mod_exp(m, n);
    printf("%I64d\n", ((mmn + mi * (mmn - mn)) % p + p) % p);
}