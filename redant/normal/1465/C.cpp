#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 100005;
int n, m;
int row[MX], col[MX];
int got[MX];

class DSU {
    vector<int> par;
    public:
    vector<int> sz;
    int n;

    DSU(int _n): n(_n) {
        par.resize(n);
        sz.resize(n, 1);
        iota(par.begin(), par.end(), 0);
    }

    inline int find(int u) {
        return u^par[u] ? (par[u] = find(par[u])) : u;
    }

    bool join (int u, int v) {
        if ((u = find(u)) == (v = find(v)))
            return false;
        if (sz[v] < sz[u]) swap(u, v);
        par[u] = v;
        sz[v] += sz[u];
        return true;
    }
};


int solve() {
    DSU dsu(n+1);
    map<int, int> cols;
    REP(i, m) cols[col[i]] = row[i];
    REP(i, m) 
        if (cols[row[i]] && row[i] != cols[row[i]]) {
            dsu.join(row[i], cols[row[i]]);
        }
    int r = 0;
    set<int> free;
    REP(i, m) {
        if (!cols[row[i]]) {
            free.insert(dsu.find(row[i]));
        }
    }
    REP(i, m) {
        if (row[i] == col[i]) continue;
        int pi = dsu.find(row[i]);
        if (pi == row[i]) {
            int s = dsu.sz[pi];
            r += free.count(pi) ? s : (1 + s);
        }
    }
    return r;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>m;
        REP(i, m) {
            cin>>row[i]>>col[i];
        }
        int r = solve();
        REP(i, m) swap(row[i], col[i]);
        r = min(r, solve());
        cout<<r<<"\n";
    }
    
    return 0;
}