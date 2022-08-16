#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

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

int n;

int main() {
    setIO();
    cin>>n;
    DSU a(n+1), b(n+1);
    vector<pair<int, int> > res;
    int m1, m2; cin >> m1 >> m2;
    while(m1--) {
        int u, v; cin >> u >> v;
        a.join(u, v);
    } 
    while(m2--) {
        int u, v; cin >> u >> v;
        b.join(u, v);
    }

    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++) {
            if (a.find(i) != a.find(j) && b.find(i) != b.find(j)) {
                a.join(i, j); b.join(i, j);
                res.emplace_back(i, j);
            }
        }

    cout << res.size() << "\n";
    for(auto &x : res)
        cout << x.first << " " << x.second << "\n";

    return 0;
}