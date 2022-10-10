#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;
    if(k > n + m - 2) {
        cout << "-1\n";
        return 0;
    }
    ll ans = 0;
    for(ll s = 1; s * s <= 4LL * n; s++) {
        if(s > n)
            continue;
        ll t = k + 2 - s;
        if(t < 1 || t > m)
            continue;
        ans = max(ans, (n/s) * (m/t));
    }
    for(ll r = 1; r * r <= 4LL * n; r++) {
        ll s = n / r;
        if(s > n || s < 1)
            continue;
        ll t = k + 2 - s;
        if(t > m)
            continue;
        if(t < 1) {
            s -= (1 - t);
            t = 1;
        }
        ans = max(ans, (n/s) * (m/t));
    }
    cout << ans << '\n';
}