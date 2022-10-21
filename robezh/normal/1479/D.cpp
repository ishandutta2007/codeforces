#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = (int)3e5 + 50;
const int LOGN = 19;

vi G[N];
int n, q;
int a[N];
int parent[LOGN][N];
int depth[N];
void dfs(int v, int p, int d){
    parent[0][v] = p;
    depth[v] = d;
    for(int nxt : G[v]){
        if(nxt != p) dfs(nxt, v, d+1);
    }
}

void init(){
    dfs(0, -1, 0);

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

int ncnt = 1;
int zeros[N];

struct node{
    int ls, rs;
    ull sum;
} ns[N * 30];

int newnode(ull val){
    ns[ncnt].ls = ns[ncnt].rs = 0;
    ns[ncnt].sum = val;
    return ncnt++;
}

int newnode(int ls, int rs){
    ns[ncnt].ls = ls;
    ns[ncnt].rs = rs;
    ns[ncnt].sum = (ls ? ns[ls].sum : 0) ^ (rs ? ns[rs].sum : 0);
    return ncnt++;
}

int build(int a[], int tl = 0, int tr = n-1){
    if(tl == tr) return newnode(a[tl]);
    int mid = (tl + tr) / 2;
    return newnode(build(a, tl, mid), build(a, mid + 1, tr));
}

ull get_sum(int v, int l, int r, int tl = 0, int tr = n-1){
    if(tr < l || tl > r) return 0;
    if(l <= tl && tr <= r) return ns[v].sum;
    int tm = (tl + tr) / 2;

    return get_sum(ns[v].ls, l, r, tl, tm) ^ get_sum(ns[v].rs, l, r, tm + 1, tr);
}

int update(int v, int pos, int tl, int tr, ull d){
    if(tl == tr) return newnode(ns[v].sum ^ d);
    int tm = (tl + tr) / 2;
    if(pos <= tm) return newnode(update(ns[v].ls, pos, tl, tm, d), ns[v].rs);
    else return newnode(ns[v].ls, update(ns[v].rs, pos, tm+1, tr, d));
}

int find_point(int v0, int v1, int tl, int tr, int st, ull as, int mpos, ull mval) {
    if(tl == tr) return tl;
    int tm = (tl + tr) / 2;
    ull lsum = as ^ ns[ns[v0].ls].sum ^ ns[ns[v1].ls].sum ^ (mpos <= tm ? mval : 0);
    if(tm < st || lsum == 0) {
        return find_point(ns[v0].rs, ns[v1].rs, tm + 1, tr, st, as ^ (ns[ns[v0].ls].sum ^ ns[ns[v1].ls].sum), mpos, mval);
    } else {
        return find_point(ns[v0].ls, ns[v1].ls, tl, tm, st, as, mpos, mval);
    }
}


mt19937_64 rng(233);
ull val[N];
int vs[N];

void solve(int v, int p, ull s) {
    if(p == -1) vs[v] = build(zeros, 0, n - 1);
    else vs[v] = vs[p];
    vs[v] = update(vs[v], a[v], 0, n - 1, val[a[v]]);
    s ^= val[a[v]];
//    cout << v << " " << ns[vs[v]].sum << " " << s << endl;
    assert(ns[vs[v]].sum == s);

    for (int nxt : G[v]) {
        if(nxt == p) continue;
        solve(nxt, v, s);
    }
}

ull eval(int u, int v, int l, int r, int ad) {
    return get_sum(vs[u], l, r, 0, n - 1) ^ get_sum(vs[v], l, r, 0, n - 1) ^ (l <= ad && ad <= r ? val[ad] : 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    rep(i, 0, n) {
        val[i] = rng();
//        cout << i << " " << val[i] << endl;
    }
    rep(i, 0, n) cin >> a[i], a[i]--;
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    init();
    solve(0, -1, 0);
    while(q--) {
        int u, v, l, r; cin >> u >> v >> l >> r;
        u--, v--, l--, r--;
        int ca = lca(u, v);
//        ull sum = get_sum(vs[u], l, r, 0, n - 1) ^ get_sum(vs[v], l, r, 0, n - 1) ^ (l <= a[ca] && a[ca] <= r ? val[a[ca]] : 0);
        ull sum = eval(u, v, l, r, a[ca]);
        if(sum == 0) {
            cout << -1 << '\n';
            continue;
        }
        ull as = get_sum(vs[u], 0, l - 1, 0, n - 1) ^ get_sum(vs[v], 0, l - 1, 0, n - 1) ^ (a[ca] <= l - 1 ? val[a[ca]] : 0);
        cout << find_point(vs[u], vs[v], 0, n - 1, l, as, a[ca], val[a[ca]]) + 1 << '\n';
    }




}