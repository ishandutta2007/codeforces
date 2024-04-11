#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, k, l1, r1, l2, r2;
    cin >> n >> k >> l1 >> r1 >> l2 >> r2;
    ll isec = max(0LL, min(r1, r2) - max(l1, l2));
    ll ini = isec * n;
    if(ini >= k) {
        cout << "0\n";
        return;
    }
    k -= ini;
    ll L = min(l1, l2), R = max(r1, r2);
    ll cost = (l1 - L) + (l2 - L) + (R - r1) + (R - r2);
    ll ext = (R - L) - isec;
    ll ans = 0;
    int tak = 0;
    while(k) {
        if(tak == 0) {
            ans += (cost - ext);
            ans += min(k, ext);
            k -= min(k, ext);
            tak++;
            continue;
        }
        if(k >= ext && tak < n) {
            if(cost >= 2 * ext) {
                ans += 2 * k;
                k = 0;
                continue;
            }
            ans += cost;
            k -= ext;
            tak++;
            continue;
        }
        if(tak == n) {
            ans += 2 * k;
            k = 0;
            continue;
        }
        if((cost - ext) + k >= 2 * k) {
            ans += 2 * k;
            k = 0;
            continue;
        }
        ans += cost - ext + k;
        k = 0;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}