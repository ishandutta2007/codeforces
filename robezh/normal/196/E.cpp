#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, int> pli;
const int N = (int)1e5 + 50;
const ll INF = (ll)1e18;

struct edge {
    int to, cost;
};

struct eg {
    int u, v;
    ll cost;
};

int n, m;
ll dis[N];
int pv[N];
vi ps;
int f[N];
vector<edge> G[N];
vector<eg> es;

int find(int i) {return f[i] == i ? i : f[i] = find(f[i]);}
void unite(int u, int v) {
    f[find(u)] = find(v);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, m) {
        int u, v, c; cin >> u >> v >> c; u--, v--;
        G[u].push_back({v, c});
        G[v].push_back({u, c});
    }
    int k;
    cin >> k;
    rep(i, 0, k) {
        int x; cin >> x; x--;
        ps.push_back(x);
    }
    fill(dis, dis + n, INF);
    priority_queue<pli, vector<pli>, greater<pli>> pque;
    for(int p : ps) {
        dis[p] = 0;
        pv[p] = p;
        pque.push({0,p});
    }
    while(!pque.empty()) {
        auto p = pque.top(); pque.pop();
        if(p.first > dis[p.second]) continue;
        for(auto &e : G[p.second]) {
            if(e.cost + p.first < dis[e.to]) {
                dis[e.to] = e.cost + p.first;
                pv[e.to] = pv[p.second];
                pque.push({dis[e.to], e.to});
            }
        }
    }
    for(int i = 0; i < n; i++) {
//        cout << i << ": " <<  dis[i] << " " << pv[i] << endl;
        for(auto &e : G[i]) {
            if(pv[e.to] != pv[i]) {
                es.push_back({pv[e.to], pv[i], dis[e.to] + dis[i] + e.cost});
//                cout << pv[e.to] << " " << pv[i] << " " << dis[e.to] + dis[i] + e.cost << endl;
            }
        }
    }
    for(int i = 0; i < n; i++) f[i] = i;
    sort(all(es), [](const eg &e1, const eg &e2) {
        return e1.cost < e2.cost;
    });
    ll res = 0;
    for(auto &e : es) {
        if(find(e.u) != find(e.v)) {
            unite(e.u, e.v);
            res += e.cost;
        }
    }
    cout << res + dis[0] << '\n';

}