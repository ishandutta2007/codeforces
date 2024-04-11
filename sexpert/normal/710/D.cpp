#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll euclid(ll a, ll b, ll &x, ll &y) {
    if (b) { ll d = euclid(b, a % b, y, x);
        return y -= a/b * x, d; }
    return x = 1, y = 0, a;
}

pair<ll, ll> crt(ll a, ll m, ll b, ll n) {
    if (n > m) swap(a, b), swap(m, n);
    ll x, y, g = euclid(m, n, x, y);
    if((a - b) % g != 0)
        return {-1, -1};
    x = (b - a) % n * x % n / g * m + a;
    return {m * n/g, x < 0 ? x + m*n/g : x};
}

ll mod(ll a, ll b) {
    a = a % b;
    return (a + b) % b;
}

int main() {
    ll a1, b1, a2, b2, L, R;
    cin >> a1 >> b1 >> a2 >> b2 >> L >> R;
    auto p = crt((b1%a1 + a1)%a1, a1, (b2%a2 + a2)%a2, a2);
    ll m = p.first, b = p.second;
    if(m == -1) {
        cout << "0\n";
        return 0;
    }
    b %= m;
    b = (b + m) % m;
    ll la = R;
    if(mod(la - b, m) != 0)
        la -= mod(la - b, m);
    ll fi = L;
    fi = max(fi, b1);
    fi = max(fi, b2);
    if(mod(fi - b, m) != 0)
        fi += m - mod(fi - b, m);
    if(fi > la) {
        cout << "0\n";
        return 0;
    }
    cout << (la - fi)/m + 1 << '\n';
}