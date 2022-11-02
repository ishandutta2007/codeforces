#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll sqr(ll x, ll y) {
    if(x == 0) return 0;
    ll ret = 4*sqr(x>>1, y);
    if(x&1) ret += 4*(x>>1)+1;
    return ret % y;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    ll p, q, b;
    int n;
    cin >> n;
    while(n --) {
        cin >> p >> q >> b;
        ll d = __gcd(p, q);
        p /= d, q /= d;
        for(int i = 0; i < 6; i ++) b = sqr(b, q);
        if(b == 0) puts("Finite");
        else puts("Infinite");
    }
}