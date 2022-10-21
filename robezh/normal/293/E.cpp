#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int N = 100050, INF = (int)1e9;
int n,l,w;
ll res = 0;

struct edge{
    int to, cost;
    bool operator < (const edge &o) const{
        return to < o.to;
    }
};

set<edge> G[N];
int depth[N], par[N], sub[N], dis[N];

struct BIT{
    int n;
    vector<int> bit;
    BIT(int _n){
        n = _n;
        bit.resize(n, 0);
    }

    void add(int x, int val) {
        for(int i = x; i < n; i |= i + 1) bit[i] += val;
    }

    ll get(int x) {
        ll res = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
        return res;
    }

};

int dfs1(int v, int p){
    sub[v] = 1;
    for(auto e: G[v])
        if(e.to != p)
            sub[v] += dfs1(e.to, v);
    return sub[v];
}

int dfs2(int v, int p, int nn){
    for(auto e: G[v]){
        if(e.to != p && sub[e.to] > nn/2) return dfs2(e.to, v, nn);
    }
    return v;
}

int dfs3(int v, int p, int len, int wei, vector<P> &ps){
    int mx = len;
    ps.push_back({wei, len});
    for(auto e : G[v]) {
        if(e.to == p) continue;
        mx = max(mx, dfs3(e.to, v, len + 1, wei + e.cost, ps));
    }
    return mx;
}

ll get_res(int v, int p, int len, int wei) {
    vector<P> ps;
    ll ret = 0;
    int mx = dfs3(v, p, len, wei, ps);
    sort(ps.begin(), ps.end());
    BIT bit = BIT(mx + 1);
    int r = 0;
    for(int i = ps.size() - 1; i >= 0; i--) {
        while(r < ps.size() && ps[r].first + ps[i].first <= w){
            bit.add(ps[r].second, 1);
            r++;
        }
        ret += bit.get(min(l - ps[i].second, mx));
    }
    return ret;
}

void decompose(int v, int p){
    dfs1(v, -1);
    int centroid = dfs2(v, -1, sub[v]);
    par[centroid] = p;

    res += get_res(centroid, -1, 0, 0);

    for(auto e: G[centroid]){
        res -= get_res(e.to, centroid, 1, e.cost);
        G[e.to].erase({centroid, -1});
        decompose(e.to, centroid);
    }
    G[centroid].clear();
}


int main(){
    scanf("%d%d%d", &n, &l, &w);
    for(int i = 1; i < n; i++){
        int a, w;
        scanf("%d%d", &a, &w);
        a--;
        G[i].insert({a, w});
        G[a].insert({i, w});
    }
    decompose(0, -1);
    cout << (res - n) / 2 << endl;



}