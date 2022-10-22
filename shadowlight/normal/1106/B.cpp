#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-6;

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
    ll n, m;
    cin >> n >> m;
    vector <ll> a(n), c(n);
    vector <pair <ll, ll> > all;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> c[i];
        all.push_back({c[i], i});
    }
    sort(all.begin(), all.end());
    ll last = 0;
    ll res = 0;
    for (ll i = 0; i < m; i++) {
        ll t, d;
        cin >> t >> d;
        t--;
        ll now = 0;
        ll x = min(d, a[t]);
        a[t] -= x;
        d -= x;
        now += x * c[t];
        while (last < n && d) {
            ll pos = all[last].second;
            ll x = min(d, a[pos]);
            d -= x;
            a[pos] -= x;
            now += x * c[pos];
            if (!d) break;
            last++;
        }
        if (!d) {
            cout << now << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
}