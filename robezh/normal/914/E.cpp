#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50, PW = (int)1050000;

int n;
int cnt[PW];
set<int> G[N];
string str;
int msk[N];
ll res[N], dp[N];
int sub[N], par[N];

void calc_mask(int v, int p, int mask) {
    mask ^= (1 << (str[v] - 'a'));
    msk[v] = mask;
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        calc_mask(nxt, v, mask);
    }
}

int dfs1(int v, int p){
    sub[v] = 1;
    for(int nxt : G[v])
        if(nxt != p)
            sub[v] += dfs1(nxt, v);
    return sub[v];
}

int dfs2(int v, int p, int nn){
    for(int nxt : G[v]){
        if(nxt != p && sub[nxt] > nn/2) return dfs2(nxt, v, nn);
    }
    return v;
}

void add(int v, int p, int delta) {
    cnt[msk[v]] += delta;
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        add(nxt, v, delta);
    }
}

int accumulate(int v, int mask) {
    int res = 0;
    int cmask = msk[v] ^ mask;
    res += cnt[cmask];
    for(int b = 0; b < 20; b++) res += cnt[cmask ^ (1 << b)];
    return res;
}

ll accumulate(int v, int p, int mask) {
    ll cur_res = accumulate(v, mask);
    for(int nxt : G[v]) {
        if(nxt != p) cur_res += accumulate(nxt, v, mask);
    }
    res[v] += cur_res;
    return cur_res;
}

void decompose(int v, int p){
    dfs1(v, -1);
    int centroid = dfs2(v, -1, sub[v]);
    par[centroid] = p;
    calc_mask(centroid, -1, 0);
    add(centroid, -1, 1);
    ll res_cen = 0;
    for(int nxt : G[centroid]) {
        add(nxt, centroid, -1);
        res_cen += accumulate(nxt, centroid, msk[centroid]);
        add(nxt, centroid, 1);
    }
//    cout << v << " " << p << ", rescen: " << res_scen << endl;
    cnt[msk[centroid]]--;
    res_cen = (res_cen + accumulate(centroid, msk[centroid])) / 2 + 1;
    res[centroid] += res_cen;
    cnt[msk[centroid]]++;
    add(centroid, -1, -1);

    for(int nxt : G[centroid]){
        G[nxt].erase(centroid);
        decompose(nxt, centroid);
    }
    G[centroid].clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].insert(v);
        G[v].insert(u);
    }
    cin >> str;
//    calc_mask(0, -1, 0);
    decompose(0, -1);
    for(int i = 0; i < n; i++) cout << res[i] << " ";


}