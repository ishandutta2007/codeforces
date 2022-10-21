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
typedef pair<int, pii> P;

const int N = (int)3e5 + 50;

struct edge {
    int to, id;
};


int n, m, x;
int f[N];
ll a[N];
vector<edge> G[N];
int vis[N];

int find(int i) {return f[i] == i ? i : f[i] = find(f[i]);}

int unite(int u, int v) {
    u = find(u), v = find(v);
    if(sz(G[u]) > sz(G[v])) swap(u, v);
    a[v] += a[u] - x;
    for (auto e : G[u]) G[v].push_back(e);
    f[u] = v;
    return v;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> x;
    ll sum = 0;
    rep(i, 0, n) cin >> a[i], sum += a[i];
    if(sum < 1LL * x * (n - 1)) {
        return cout << "NO\n", 0;
    }
    iota(f, f + n, 0);
    rep(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        if(find(u) != find(v)) {
            f[find(u)] = find(v);
            G[u].push_back({v, i});
            G[v].push_back({u, i});
        }
    }
    queue<int> que;
    iota(f, f + n, 0);
    rep(i, 0, n) if(a[i] >= x) que.push(i);
    vi res;
    while(!que.empty()) {
        int v = que.front(); que.pop();
        if(v != find(v) || a[v] < x) continue;
        while(!G[v].empty() && find(G[v].back().to) == v) G[v].pop_back();
        if(!G[v].empty()) {
            auto e = G[v].back(); G[v].pop_back();
            int rt = unite(e.to, v);
            res.push_back(e.id);
            vis[e.id] = 1;
            if(a[rt] >= x) que.push(rt);
        }
    }
    rep(i, 0, n) {
        for (auto e : G[i]) {
            if(!vis[e.id]) {
                vis[e.id] = true;
                res.push_back(e.id);
            }
        }
    }
    cout << "YES\n";
    for (auto v : res) cout << v + 1 << '\n';


}