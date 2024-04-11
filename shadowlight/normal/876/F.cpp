#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;
const ll LOGN = 32;

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
    ll n;
    cin >> n;
    vector <pair <ll, ll> > a;
    a.resize(n);
    vector <vector <ll> > pos(LOGN);
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a[i] = {x, i};
        for (ll j = 0; j < LOGN; j++) {
            if ((x & (1 << j)) == 0) continue;
            pos[j].push_back(i);
        }
    }
    vector <pair <ll, ll> > segs(n, {0, n - 1});
    for (ll i = 0; i < LOGN; i++) {
        ll pr = -1;
        pos[i].push_back(n);
        for (ll x : pos[i]) {
            for (ll j = pr + 1; j < x; j++) {
                segs[j].first = max(segs[j].first, pr + 1);
                segs[j].second = min(segs[j].second, x - 1);
            }
            pr = x;
        }
    }
    sort(a.rbegin(), a.rend());
    set <ll> q;
    ll res = 0;
    for (ll i = 0; i < n; i++) {
        ll x = a[i].first, p = a[i].second;
        ll l = segs[p].first, r = segs[p].second;
        auto it = q.upper_bound(p);
        if (it != q.end()) {
            r = min(r, *it - 1);
        }
        if (it != q.begin()) {
            it--;
            l = max(l, *it + 1);
        }
        //cout << x << " " << l << " " << r << "\n";
        res += (ll) (r - p + 1) * (ll) (p - l + 1) - 1;
        q.insert(p);
    }
    cout << n * (n - 1) / 2 - res;
}