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
    ll n;
    cin >> n;
    set <pair <ll, ll> > exist;
    set <pair <ll, ll> > res;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        exist.insert({x, i});
    }
    while (exist.size()) {
        auto p = *exist.begin();
        exist.erase(p);
        if (!exist.size() || exist.begin()->first != p.first) {
            res.insert({p.second, p.first});
        } else {
            auto p1 = *exist.begin();
            exist.erase(exist.begin());
            exist.insert({2 * p1.first, p1.second});
        }
    }
    vector <ll> ans;
    for (auto p : res) {
        ans.push_back(p.second);
    }
    cout << ans.size() << "\n";
    for (ll x : ans) {
        cout << x << " ";
    }
}