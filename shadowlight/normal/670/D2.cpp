#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 2e9 + 7;
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
    ll n, k;
    cin >> n >> k;
    vector <ll> a(n), b(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
    }
    ll l = 0, r = INF;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        ll all = 0;
        for (ll i = 0; i < n; i++) {
            ll x = a[i] * mid;
            if (x > b[i]) {
                all += x - b[i];
            }
            if (all > k) break;
        }
        if (all > k) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << l;
}