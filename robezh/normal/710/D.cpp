#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a1, b1, a2, b2, L, R;

// want to solve ax + by = 1;
ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll d = a;
    if(b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else {
        x = 1; y = 0;
    }
    return d;
}

ll mod(ll a, ll b){
    return (a % b + b) % b;
}

ll dvd(ll a, ll b) {
    return (a - mod(a, b)) / b;
}


int main() {
    cin >> a1 >> b1 >> a2 >> b2 >> L >> R;
    L = max(L, max(b1, b2));
    if(a1 == a2) {
        if(mod(b1, a1) != mod(b2, a2)) return !printf("0");
        else return !printf("%lld", max(0LL, (dvd((R - max(b1, b2)), a1)) -
            max(-1LL, dvd(((L - 1) - max(b1, b2)), a1))));
    }
    if(a1 == 0 || a2 == 0) {
        if(a1 == 0) swap(a1, a2), swap(b1, b2);
        if((b2 - b1) % a1 == 0 && b2 >= b1 && b2 >= L && b2 <= R) return !printf("1");
        else return !printf("0");
    }

    ll dif = b2 - b1;
    ll x1, x2;
    ll g = extgcd(a1, -a2, x1, x2);
    if(dif % g != 0) return !printf("0");
    if(g < 0) x1 = -x1, x2 = -x2, g = -g;
    ll c0 = dif / g, c1 = a1 / g, c2 = a2 / g;

    x1 *= c0, x2 *= c0;

    ll rb = dvd(dvd((R - b1), a1) - x1, c2);
    ll lb = dvd(dvd((L - 1 - b1), a1) - x1, c2);

    return !printf("%lld", max(0LL, rb - lb));
}