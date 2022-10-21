#include <bits/stdc++.h>
#include <bits/extc++.h> /** keep-include */
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef vector<int> vi;

const int N = (int)1e5 + 50;
struct edge{int to, cost;};

int n;
vector<edge> G[N];
ll dis[2][N];
ll td[N];

void calc(int v, int p, ll d, ll *dist) {
    dist[v] = d;
    for (auto &e : G[v]) {
        if(e.to != p) calc(e.to, v, d + e.cost, dist);
    }
}

void calc(ll *dist, int s) {
    calc(s, -1, 0, dist);
}

int find_fur(int s) {
    int x = s;
    calc(td, s);
    rep(i, 0, n) {
        if(td[i] > td[x]) x = i;
    }
    cout << endl;
    return x;
}

int r[N];
int idx[N];

template<class T>
using Tree = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag,
        __gnu_pbds::tree_order_statistics_node_update>;

Tree<pll> S[N];

int q;
ll qr[55];
int res[55];

int unite(int u, int v) {
    if(sz(S[u]) > sz(S[v])) swap(u, v);
    for (auto &x : S[u]) {
        S[v].insert(x);
    }
    return v;
}

void dfs(int v, int p, ll d) {
    idx[v] = v;
    S[v].insert({d, v});
    for(auto &e : G[v]) {
        if(e.to != p && r[e.to] == r[v]) {
            dfs(e.to, v, d + e.cost);
            idx[v] = unite(idx[v], idx[e.to]);
        }
    }
    rep(i, 0, q) {
        res[i] = max(res[i], (int)S[idx[v]].order_of_key({qr[i] + d, N}));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n - 1) {
        int u, v, cost; cin >> u >> v >> cost; u--, v--;
        G[u].push_back({v, cost});
        G[v].push_back({u, cost});
    }
    cin >> q;
    rep(i, 0, q) cin >> qr[i];
    int s = find_fur(0), t = find_fur(s);
    calc(dis[0], s);
    calc(dis[1], t);

    int rt[2] = {-1, -1};
    rep(i, 0, n) {
        r[i] = dis[0][i] > dis[1][i];
        if(r[i] == 0) {
            if(rt[0] == -1 || dis[1][i] < dis[1][rt[0]]) rt[0] = i;
        } else {
            if(rt[1] == -1 || dis[0][i] < dis[0][rt[1]]) rt[1] = i;
        }
    }
    ll mnd = min(dis[0][rt[1]], dis[1][rt[0]]);
    dfs(rt[0], -1, 0);
    dfs(rt[1], -1, 0);
    vector<pli> L(all(S[idx[rt[0]]])), R(all(S[idx[rt[1]]]));
    rep(it, 0, q) {
        ll up = qr[it];
        int r0 = 0, r1 = 0;
        while(r0 < sz(L) && dis[1][rt[0]] + L[r0].first <= mnd + up) r0++;
        while(r1 < sz(R) && dis[0][rt[1]] + R[r1].first <= mnd + up) r1++;
        res[it] = max(res[it], r0 + r1);
    }
    rep(i, 0, q) cout << res[i] << '\n';

}