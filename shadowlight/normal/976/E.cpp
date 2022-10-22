#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
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
    ll n, a, b;
    cin >> n >> a >> b;
    vector <pair <ll, ll> > d(n);
    set <pair <ll, ll> > q;
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        cin >> d[i].first >> d[i].second;
        sum += d[i].second;
        q.insert({d[i].first - d[i].second, i});
    }
    set <ll> good;
    ll good_up = 0;
    for (ll i = 0; i < b - 1; i++) {
        if (!q.size()) break;
        ll it = q.rbegin()->second;
        if (q.rbegin()->first <= 0) break;
        good_up += q.rbegin()->first;
        good.insert(q.rbegin()->second);
        q.erase(*q.rbegin());
    }
    ll res = sum + good_up;
    ll mt = (1LL << a);
    if (!b) {
        cout << sum;
        return 0;
    }
    for (ll i = 0; i < n; i++) {
        pair <ll, ll> p = {d[i].first - d[i].second, i};
        ll add = 0;
        if (good.find(i) != good.end()) {
            add -= p.first;
            if (q.size() && q.rbegin()->first > 0) {
                add += q.rbegin()->first;
            }
        }
        //cout << add << "\n";
        res = max(res, sum + good_up + mt * d[i].first - d[i].second + add);
    }
    cout << res;
}