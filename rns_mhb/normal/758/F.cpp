#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll pow_mod(ll x, ll y) {
    ll ret = 1;
    while(y > 0) {
        if(y & 1) ret *= x;
        x *= x;
        y >>= 1;
    }
    return ret;
}

int main() {
    ll n, l, r, b, a, c, A, C, ans, i;
    scanf("%I64d%I64d%I64d", &n, &l, &r);
    if(n == 1) {printf("%I64d\n", r - l + 1); return 0;}
    if(n == 2) {printf("%I64d\n", (r - l + 1) * (r - l)); return 0;}
    b = 2;
    while(1) {
        c = 1;
        for(i = 1; i < n; i ++) {
            c = c * b;
            if(c > r) break;
        }
        if(i < n) break;
        b ++;
    }
    ans = 0;
    for(a = 1; a < b; a ++) for(c = a + 1; c < b; c ++) if(__gcd(a, c) == 1) {
        A = pow_mod(a, n - 1);
        C = pow_mod(c, n - 1);
        ans += max(0ll, r / C - (l + A - 1) / A + 1);
    }
    printf("%I64d\n", ans * 2);
    return 0;
}