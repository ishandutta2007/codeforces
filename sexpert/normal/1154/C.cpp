#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// a - 0 3 6
// b - 1 5
// c - 2 4
ll a, b, c;
map<ll, ll> mp;

bool check(ll m, ll d) {
    ll tot[3] = {0, 0, 0};
    for(ll o = 0; o < 7; o++)
        tot[mp[(d + o)%7]] += (m + 6ll - o)/7ll;
    return (tot[0] <= a && tot[1] <= b && tot[2] <= c);
}

int main() {
    cin >> a >> b >> c;
    ll ans = 0;
    mp[0] = mp[3] = mp[6] = 0;
    mp[1] = mp[5] = 1;
    mp[2] = mp[4] = 2;
    for(ll i = 0; i < 7; i++) {
        ll lo = 0, hi = 1e12;
        while(lo < hi) {
            ll mi = (lo + hi + 1)/2;
            if(check(mi, i))
                lo = mi;
            else
                hi = mi - 1;
        }
        ans = max(ans, lo);
    }
    cout << ans << endl;
}