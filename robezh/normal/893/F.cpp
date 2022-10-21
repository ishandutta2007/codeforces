#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

const int N = (int)1e5 + 50, INF = (int)1e9 + 50;
typedef pair<int, int> P;

//Need to initialize before every test case!
int ncnt = 1;
int a[N];

int r;
vector<int> G[N];


struct node{
    int ls, rs, mn;
} ns[N * 30];

int newnode(int val){
    ns[ncnt].ls = ns[ncnt].rs = 0;
    ns[ncnt].mn = val;
    return ncnt++;
}

int newnode(int ls, int rs){
    ns[ncnt].ls = ls;
    ns[ncnt].rs = rs;
    ns[ncnt].mn = min(ls ? ns[ls].mn : INF, rs ? ns[rs].mn : INF);
    return ncnt++;
}

int n, q;
int vs[N];
int tin[N], tout[N];
int dep[N];
vector<int> dps[N];
int pr = 0;

void dfs(int v, int p, int d) {
    tin[v] = pr++;
    dps[d].push_back(v);
    dep[v] = d;
    for(int nxt : G[v]) {
        if(nxt != p) dfs(nxt, v, d + 1);
    }
    tout[v] = pr - 1;
}

int build(int tl = 0, int tr = n-1){
    if(tl == tr) return newnode(INF);
    int mid = (tl + tr) / 2;
    return newnode(build(tl, mid), build(mid + 1, tr));
}

int get_mn(int v, int l, int r, int tl = 0, int tr = n - 1){
    if(tr < l || tl > r) return INF;
    if(l <= tl && tr <= r) return ns[v].mn;
    int tm = (tl + tr) / 2;

    return min(get_mn(ns[v].ls, l, r, tl, tm), get_mn(ns[v].rs, l, r, tm + 1, tr));
}

int update(int v, int pos, int val, int tl = 0, int tr = n-1){
    if(tl == tr) return newnode(val);
    int tm = (tl + tr) / 2;
    if(pos <= tm) return newnode(update(ns[v].ls, pos, val, tl, tm), ns[v].rs);
    else return newnode(ns[v].ls, update(ns[v].rs, pos, val, tm+1, tr));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r; r--;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(r, -1, 0);
    vs[0] = build();
    vs[0] = update(vs[0], tin[r], a[r]);
    for(int i = 1; i < n; i++) {
        vs[i] = vs[i-1];
        for(int v : dps[i]) {
            vs[i] = update(vs[i], tin[v], a[v]);
        }
    }
    int ans = 0;
    cin >> q;
    while(q--) {
        int x, k; cin >> x >> k;
        x = (x + ans) % n + 1, k = (k + ans) % n;
        x--;
        ans = get_mn(vs[min(dep[x] + k, n - 1)], tin[x], tout[x]);
        cout << ans << "\n";
    }
}