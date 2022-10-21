#include <bits/stdc++.h>
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
typedef vector<int> vi;

const int N = 100050, INF = (int)1e9;
const int LOGN = 17;
int root = 0;

struct edge {
    int to, cost;
};

int n;
vector<edge> G[N];
int parent[LOGN][N];
int depth[N];
ll dlen[N];
int tin[N], tout[N], tim;
void dfs(int v, int p, int d, ll d2){
    parent[0][v] = p;
    depth[v] = d;
    dlen[v] = d2;
    tin[v] = tim++;
    for(auto &e : G[v]){
        if(e.to != p) dfs(e.to, v, d + 1, d2 + e.cost);
    }
    tout[v] = tim - 1;
}

void init(){
    dfs(root, -1, 0, 0);

    for(int k = 0; k+1 < LOGN; k++){
        for(int v = 0; v < n; v++){
            if(parent[k][v] < 0) parent[k+1][v] = -1;
            else parent[k+1][v] = parent[k][parent[k][v]];
        }
    }
}

int lca(int u, int v){
    if(depth[u] > depth[v]){int tmp = u; u = v; v = tmp;}
    for(int k = 0; k < LOGN; k++){
        if((depth[v] - depth[u]) >> k & 1){
            v = parent[k][v];
        }
    }
    if(u == v) return u;
    for(int k = LOGN - 1; k >= 0; k--){
        if(parent[k][u] != parent[k][v]){
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return parent[0][u];
}

struct vint {
    int x;
};

bool operator < (const vint &x, const vint &y) {
    return tin[x.x] < tin[y.x];
}

struct BIT {
    int bit[N];

    void add(int x, int val) {
        for(int i = x; i < n; i |= i + 1) bit[i] += val;
    }

    ll get(int x) {
        ll res = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
        return res;
    }

    ll get(int l, int r) {
        return get(r) - get(l - 1);
    }
} bit;

set<vint> S;
ll sum = 0;

ll calc(int v) {
    if(S.empty()) return dlen[v];
    if(bit.get(tin[v], tout[v])) return 0;
    int u = v;
    for (int k = LOGN - 1; k >= 0; k--) {
        int nxtv = parent[k][u];
        if(nxtv != -1 && !bit.get(tin[nxtv], tout[nxtv])) u = nxtv;
    }
    return dlen[v] - dlen[parent[0][u]];

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n - 1) {
        int u, v, l; cin >> u >> v >> l; u--, v--;
        G[u].push_back({v, l});
        G[v].push_back({u, l});
    }
    init();
    int q;
    cin >> q;
    while(q--) {
        char c; cin >> c;
        int x;
        if(c == '?') {
            if(S.empty()) {
                cout << 0 << '\n';
            } else {
                int vl = S.begin()->x, vr = S.rbegin()->x;
                cout << sum - dlen[lca(vl, vr)] << '\n';
            }
        } else {
            cin >> x; x--;
            if(c == '+') {
                S.insert({x});
                sum += calc(x);
                bit.add(tin[x], 1);
            } else {
                S.erase({x});
                bit.add(tin[x], -1);
                sum -= calc(x);
            }
        }

    }


}