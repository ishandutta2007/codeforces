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
    ll n, m;
    cin >> n >> m;
    ll bo, inc, dm;
    cin >> bo >> inc >> dm;
    vector <vector <pair <ll, ll> > > moments(n);
    vector <bool> exist(n, true);
    vector <ll> reg(n, 0);
    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        ll st, mh;
        cin >> mh >> st >> reg[i];
        if (mh <= dm && inc) {
            cout << -1;
            return 0;
        } else if (mh <= dm) {
            cnt++;
            exist[i] = false;
        }
        if (inc && st <= dm && !reg[i]) {
            cout << -1;
            return 0;
        }
        moments[i].push_back({0, st});
    }
    for (ll i = 0; i < m; i++) {
        ll t, e, h;
        cin >> t >> e >> h;
        e--;
        if (inc && !reg[e] && h <= dm) {
            cout << -1;
            return 0;
        }
        moments[e].push_back({t, h});
    }
    vector <pair <ll, ll> > all;
    for (ll i = 0; i < n; i++) {
        if (!exist[i]) continue;
        sort(moments[i].begin(), moments[i].end());
        for (ll j = 0; j < moments[i].size(); j++) {
            ll tm = moments[i][j].first;
            if (dm - moments[i][j].second >= 0) {
                if (!reg[i]) {
                    tm = INF;
                } else {
                    tm += (dm - moments[i][j].second) / reg[i];
                }
                all.push_back({moments[i][j].first, 0});
                if (j != moments[i].size() - 1) {
                    tm = min(tm, moments[i][j + 1].first - 1);
                }
                all.push_back({tm, 1});
            }
            //cout << moments[i][j].first << " " << tm << "\n";
        }
    }
    sort(all.begin(), all.end());
    ll ans = cnt * bo;
    for (ll i = 0; i < (ll) all.size(); i++) {
        if (!all[i].second) {
            cnt++;
        }
        ans = max(ans, (inc * all[i].first + bo) * cnt);
        if (all[i].second) {
            cnt--;
        }
    }
    cout << ans;
}