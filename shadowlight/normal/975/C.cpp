#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    ll n, q;
    cin >> n >> q;
    vector <ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll it = 0, dmg = 0;
    vector <ll> pref(n + 1, 0);
    for (ll i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }
    for (ll i = 0; i < q; i++) {
        ll k;
        cin >> k;
        ll l = it - 1, r = n;
        while (r - l > 1) {
            ll mid = (l + r) / 2;
            ll val = pref[mid + 1] - pref[it + 1] + a[it] - dmg;
            if (val > k) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (r == n) {
            it = 0, dmg = 0;
        } else if (it == r) {
            dmg += k;
        } else {
            ll val = pref[r] - pref[it + 1] + a[it] - dmg;
            dmg = k - val;
            it = r;
        }
        cout << n - it << "\n";
    }
}