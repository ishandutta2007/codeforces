#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, p, w, d;
    cin >> n >> p >> w >> d;
    ll g = __gcd(w, d);
    if(p % g) {
        cout << "-1\n";
        return 0;
    }
    w /= g;
    d /= g;
    p /= g;
    for(ll x = 0; x <= d; x++) {
        if(x * w > p)
            break;
        if((p - x*w) % d)
            continue;
        ll y = (p - x*w)/d;
        if(x + y <= n) {
            cout << x << " " << y << " " << n - x - y << '\n';
            return 0;
        }
    }
    for(ll y = 0; y <= w; y++) {
        if(y * d > p)
            break;
        if((p - y*d) % w)
            continue;
        ll x = (p - y*d)/w;
        if(x + y <= n) {
            cout << x << " " << y << " " << n - x - y << '\n';
            return 0;
        }
    }
    cout << "-1\n";
}