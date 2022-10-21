#include<bits/stdc++.h>
using  namespace std;

typedef long long ll;

int t;
ll l, r;

ll ROOT(ll x) {
    ll y = ll(sqrt(x));
    y += 2;
    while(y * y > x) y --;
    return y;
}

int main() {
    for(scanf("%d", &t); t--; ) {
        scanf("%lld%lld", &l, &r);
        ll x = ROOT(r) - ROOT(l - 1);
        ll y = ROOT(r + 1) - ROOT(l);
        ll z = (ROOT(4 * r + 1) + 1) / 2 - (ROOT(4 * l) + 1) / 2;
        printf("%lld\n", x + y + z);
    }
}