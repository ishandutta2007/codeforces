#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

ll n, k;

ll calc(ll l, ll r) {
    ll d = (r - l - 1) / (k - 1);
    ll cnt = d * (d + 1) / 2 * (k - 1) + d;
    cnt += (MAXN - d - 1) * (r - l);
    return cnt % INF;

}

int  main() {
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
    cin >> n >> k;
    vector <pair <ll, ll> > a(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.rbegin(), a.rend());
    set <ll> q;
    q.insert(-1);
    q.insert(n);
    ll res = 0;
    for (ll i = 0; i < n; i++) {
        ll m = a[i].second;
        auto it = q.lower_bound(m);
        ll r = *it;
        it--;
        ll l = *it;
        q.insert(m);
        ll add = (calc(l, m) + calc(m, r) - calc(l, r) + INF) % INF * a[i].first % INF;
        //cout << l << " " << m << " " << r << " " << calc(l, m) << " " << calc(m, r) << " " << calc(l, r) << "\n";
        //cout << add << "\n";
        res = (res + add) % INF;
    }
    cout << res;
}