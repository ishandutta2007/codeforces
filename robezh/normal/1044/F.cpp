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
#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2


const int N = (int)2e5 + 50, LOGN = 18, INF = (int)1e9;

int n;

vi G[N];
int parent[LOGN][N];
int depth[N];
int in[N], out[N], tim;

void dfs(int v, int p, int d){
    parent[0][v] = p;
    depth[v] = d;
    in[v] = tim++;
    for(int nxt : G[v]){
        if(nxt != p) dfs(nxt, v, d+1);
    }
    out[v] = tim - 1;
}

void init(){
    dfs(0, -1, 0); // rooted at 0
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

int min_dis(int u, int v){
    int ca = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[ca];
}

pii operator + (pii a, pii b) {
    int mn = min(a.first, b.first);
    return {mn, (a.first == mn ? a.second : 0) + (b.first == mn ? b.second : 0)};
}

struct node {
    pii mn;
    int add;

    void add_val(int x) {
        mn.first += x;
        add += x;
    }

    void merge(node &ls, node &rs) {
        mn = ls.mn + rs.mn;
    }
};

struct Tree {
    node dat[4 * N];

    void push_down(int x, int l, int r) {
        if(dat[x].add) {
            if(l < r) {
                dat[ls(x)].add_val(dat[x].add);
                dat[rs(x)].add_val(dat[x].add);
            }
            dat[x].add = 0;
        }
    }

    void init(int x, int l, int r) {
        if(l == r) {
            dat[x].mn = {0, 1};
            dat[x].add = 0;
            return ;
        }
        int mid = (l + r) / 2;
        init(ls(x), l, mid);
        init(rs(x), mid + 1, r);
        dat[x].add = 0;
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

    pii query(int a, int b, int x, int l, int r) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return {INF, 0};
        push_down(x, l, r);
        if(l >= a && r <= b) return dat[x].mn;
        return query(a, b, ls(x), l, mid) + query(a, b, rs(x), mid+1, r);
    }

    void update(int a, int b, int x, int l, int r, int delta) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return ;

        push_down(x, l, r);

        if(l >= a && r <= b) {
            dat[x].add_val(delta);
            return ;
        }
        update(a, b, ls(x), l, mid, delta);
        update(a, b, rs(x), mid+1, r, delta);
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

} tree;



int q;
map<pii, int> has;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    init();
    tree.init(0, 0, n - 1);
    rep(i, 0, q) {
        int u, v; cin >> u >> v; u--, v--;
        if(u > v) swap(u, v);

        int off = has[{u, v}] ? -1 : 1;
        has[{u, v}] = !has[{u, v}];

        if(in[u] > in[v]) swap(u, v);
        if(in[u] <= in[v] && in[v] <= out[u]) {
            // u is an ancestor of v
            int d = depth[v] - depth[u];
            int cu = v;
            rep(b, 0, LOGN) {
                if((d - 1) >> b & 1) cu = parent[b][cu];
            }
            tree.update(in[cu], out[cu], 0, 0, n - 1, off);
            tree.update(in[v], out[v], 0, 0, n - 1, -off);
        } else {
            tree.update(0, n - 1, 0, 0, n - 1, off);
            tree.update(in[u], out[u], 0, 0, n - 1, -off);
            tree.update(in[v], out[v], 0, 0, n - 1, -off);
        }
        cout << (pii{0, 0} + tree.dat[0].mn).second << '\n';
    }
}