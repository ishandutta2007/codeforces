#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e12;
const int MAXN = 1e5 + 5;

struct flight {
    ll time, dep, arr, cost;
    bool operator< (const flight &o) const { return time < o.time; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<flight> flights;
    for(int i = 0; i < m; i++) {
        ll t, d, a, c;
        cin >> t >> d >> a >> c;
        flights.push_back(flight{t, d, a, c});
    }
    sort(flights.begin(), flights.end());
    multiset<ll> arr[MAXN], dep[MAXN];
    for(int i = 1; i <= n; i++)
        arr[i].insert(INF), dep[i].insert(INF);
    ll ans = INF;
    for(int i = 0; i < m; i++) {
        if(flights[i].dep == 0)
            dep[flights[i].arr].insert(flights[i].cost);
    }
    ll amin = (ll)n*INF, dmin = 0;
    for(int i = 1; i <= n; i++)
        dmin += *(dep[i].begin());
    int lp = -1, rp = 0;
    while(++lp < m) {
        auto f = flights[lp];
        ll t = f.time;
        if(f.arr == 0) {
            amin -= *(arr[f.dep].begin());
            arr[f.dep].insert(f.cost);
            amin += *(arr[f.dep].begin());
        }
        while(rp < m && flights[rp].time <= t + k) {
            auto g = flights[rp];
            if(g.dep == 0) {
                dmin -= *(dep[g.arr].begin());
                dep[g.arr].erase(dep[g.arr].find(g.cost));
                dmin += *(dep[g.arr].begin());
            }
            rp++;
        }
        //cout << lp << " " << rp << " " << amin << " " << dmin << endl;
        ans = min(ans, amin + dmin);
    }
    cout << (ans == INF ? -1 : ans) << endl;
}