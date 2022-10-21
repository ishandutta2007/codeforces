#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, int> pli;
const ll INF = (ll)1e18;
const int N = (int)2e5 + 50;

struct edge {
    int to, w;
};

int n, m;
vector<edge> G[N];
ll dis[4 * N];
priority_queue<pli, vector<pli>, greater<> > pque;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, m) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    fill(dis, dis + 4 * n, INF);
    dis[0] = 0;
    pque.push({0, 0});
    while(!pque.empty()) {
        auto p = pque.top(); pque.pop();
        if(dis[p.second] < p.first) continue;
        int v = p.second % n;
        ll d = p.first;
        int mk = p.second / n, m0 = mk % 2, m1 = mk / 2;
        auto check = [&](ll newdis, int v) {
            if(newdis < dis[v]) {
                dis[v] = newdis;
                pque.push({dis[v], v});
            }
        };
        for(auto e : G[v]) {
            check(d + e.w, e.to + mk * n);
            if(!m0) check(d + e.w + e.w, e.to + mk * n + n);
            if(!m1) check(d, e.to + mk * n + 2 * n);
            if(!m0 && !m1) check(d + e.w, e.to + mk * n + 3 * n);
        }
    }
    rep(i, 1, n) cout << dis[i + 3 * n] << " ";
    cout << '\n';


}