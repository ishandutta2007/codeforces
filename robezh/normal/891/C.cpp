#include <bits/stdc++.h>
using namespace std;

const int N = (int)5e5 + 50;
typedef pair<int, int> P;

struct edge {
    int u, v, c;
};

int n, m;
edge E[N];
int cs[N], cn;
vector<edge> Q[N], ori[N];

int res[N];


struct DSU {
    P S[N*2];
    int f[N];
    int sz = 0;

    void init(int n) {
        fill(f, f + n, -1);
    }

    int getroot(int i) {
        while(f[i] >= 0) i = f[i];
        return i;
    }

    bool unite(int i, int j) {
        int ri = getroot(i);
        int rj = getroot(j);
        if(ri == rj) return false;

        if(ri < rj) swap(ri, rj);
        S[sz++] = {ri, f[ri]};
        S[sz++] = {rj, f[rj]};
        f[rj] += f[ri];
        f[ri] = rj;

        return true;
    }

    void roll_back(int la_sz) {
        while(sz > la_sz) {
            sz--;
            f[S[sz].first] = S[sz].second;
        }
    }

} dsu;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c; u--, v--;
        E[i] = {u, v, c};
        cs[i] = c;
    }
    sort(cs, cs + m);
    cn = (int)(unique(cs, cs + m) - cs);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int k;
        cin >> k;
        while(k--) {
            int id; cin >> id; id--;
            int e_id = (int)(lower_bound(cs, cs + cn, E[id].c) - cs);
            Q[e_id].push_back({E[id].u, E[id].v, i});
        }
    }
    for(int i = 0; i < m; i++) {
        int e_id = (int)(lower_bound(cs, cs + cn, E[i].c) - cs);
        ori[e_id].push_back({E[i].u, E[i].v});
    }
    fill(res, res + q, 1);
    dsu.init(n);
    for(int gp = 0; gp < cn; gp++) {
        int la_sz = dsu.sz;
        int r = 0;
        for(int j = 0; j < Q[gp].size(); j = r) {
            while(r < Q[gp].size() && Q[gp][r].c == Q[gp][j].c) r++;
            for(int t = j; t < r; t++) {
//                if(Q[gp][t].c == 1) cout << gp << " " << j << " " << r << endl;
                if(!dsu.unite(Q[gp][t].u, Q[gp][t].v)) {
                    res[Q[gp][t].c] = 0;
                    break;
                }
            }
            dsu.roll_back(la_sz);
        }

        for(edge e : ori[gp]) {
            dsu.unite(e.u, e.v);
        }
    }
    for(int i = 0; i < q; i++) {
        cout << (res[i] ? "YES" : "NO") << '\n';
    }
}