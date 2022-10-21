#include <bits/stdc++.h>
using namespace std;
#define lson(x) x * 2 + 1
#define rson(x) x * 2 + 2

typedef long long ll;
const int N = 120050;
const ll INF = (ll)1e18;

int n,m,q;
vector<int> G[N];
int chainNo, chainHead[N], chainInd[N], totPos[N], totsize, veridx[N];
int subsize[N], par[N];
int in[N], out[N];
int depth[N];
ll lazy[4 * N], sum[4 * N], ssum[4 * N];

void dfs(int v, int p, int d){
    par[v] = p;
    subsize[v] = 1;
    depth[v] = d;
    for(int &nxt : G[v]){
        if(nxt == p) continue;
        dfs(nxt, v, d+1);
        subsize[v] += subsize[nxt];
        if(subsize[nxt] > subsize[G[v][0]])
            swap(nxt, G[v][0]);
    }
}

void hld(int v, int p){
    if(chainHead[chainNo] == -1) chainHead[chainNo] = v;
    chainInd[v] = chainNo;
    in[v] = totPos[v] = totsize;
    veridx[totsize++] = v;
//    v_cost[totsize ++] = cost;

    for(auto nxt : G[v]){
        if(nxt == p) continue;
        if(nxt != G[v][0]) chainNo ++;
        hld(nxt, v);
    }
    out[v] = totsize - 1;
}

void init(int x, int l, int r) {
    if(l == r){sum[x] = ssum[x] = -1; return ;}
    int mid = (l + r) / 2;
    init(lson(x), l, mid);
    init(rson(x), mid + 1, r);
    sum[x] = sum[lson(x)] + sum[rson(x)];
    ssum[x] = max(ssum[rson(x)], ssum[lson(x)] + sum[rson(x)]);
}

void init_hld(){
    chainNo = totsize = 0;
    fill(chainHead, chainHead + n, -1);
    dfs(0, -1, 0);
    hld(0, -1);
    init(0, 0, n-1);
}

void push_down(int x, int l, int r) {
    if(lazy[x]){
        if(l < r) {
            int mid = (l + r) / 2;
            sum[lson(x)] = - (mid - l + 1);
            ssum[lson(x)] = -1;
            lazy[lson(x)] = 1;
            sum[rson(x)] = - (r - mid);
            ssum[rson(x)] = -1;
            lazy[rson(x)] = 1;
        }
        lazy[x] = 0;
    }
}

pair<ll, ll> query(int l, int r, int x, int tl, int tr) {
    int tm = (tl + tr) / 2;
    if(tr < l || tl > r) return {0, -INF};

    push_down(x, tl, tr);

    if(l <= tl && tr <= r) return {sum[x], ssum[x]};

    auto LHS = query(l, r, lson(x), tl, tm);
    auto RHS = query(l, r, rson(x), tm + 1, tr);

    return {LHS.first + RHS.first, max(LHS.second + RHS.first, RHS.second)};
}

void update_point(int pos, int x, int tl, int tr, ll dif) {
    int tm = (tl + tr) / 2;

    push_down(x, tl, tr);

    if(tl == tr){sum[x] += dif; ssum[x] = sum[x]; return ;}
    if(pos <= tm) update_point(pos, lson(x), tl, tm, dif);
    else update_point(pos, rson(x), tm+1, tr, dif);
    sum[x] = sum[lson(x)] + sum[rson(x)];
    ssum[x] = max(ssum[rson(x)], ssum[lson(x)] + sum[rson(x)]);
}

void update_clear(int l, int r, int x, int tl, int tr) {
    int mid = (tl + tr) / 2;
    if(tr < l || tl > r) return ;

    push_down(x, tl, tr);

    if(tl >= l && tr <= r) {
        sum[x] = -(tr - tl + 1);
        ssum[x] = -1;
        lazy[x] = 1;
        return ;
    }
    update_clear(l, r, lson(x), tl, mid);
    update_clear(l, r, rson(x), mid+1, tr);
    sum[x] = sum[lson(x)] + sum[rson(x)];
    ssum[x] = max(ssum[rson(x)], ssum[lson(x)] + sum[rson(x)]);
}

void update_vertex(int v, ll dif) {
    update_point(in[v], 0, 0, n-1, dif);
}

void clear_sub(int v) {
    update_clear(in[v], out[v], 0, 0, n-1);
}

ll query_to_root(int v) {
    ll res = -INF;
    ll lassum = 0;
    while(chainInd[v] != chainInd[0]) {
        auto p = query(totPos[chainHead[chainInd[v]]], totPos[v], 0, 0, n-1);
        res = max(res, lassum + p.second);
        lassum += p.first;
        v = par[chainHead[chainInd[v]]];
    }
    auto p = query(totPos[0], totPos[v], 0, 0, n-1);
    return max(res, lassum + p.second);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(int i = 1; i < n; i++){
        int a;
        cin >> a; a--;
        G[i].push_back(a);
        G[a].push_back(i);
    }
    init_hld();
    while(q--) {
        int k, v;
        cin >> k >> v; v--;
        if(k == 1) {
            update_vertex(v, 1);
        }
        else if(k == 2) {
            clear_sub(v);
            ll now = query_to_root(v);
            if(now >= 0) update_vertex(v, -(now+1));
        }
        else {
            ll now = query_to_root(v);
            cout << (now >= 0 ? "black" : "white") << "\n";
        }
    }
}