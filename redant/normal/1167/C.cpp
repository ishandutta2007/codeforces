#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

class DSU {
public:
    vector<int> par;
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

int n, m;

int main() {
    setIO();
    cin>>n>>m;
    DSU dsu(n);
    int u, v;
    while(m--) {
        int k; cin>>k;
        if (k==0) continue;
        cin>>u;
        while(--k) {
            cin>>v;
            dsu.join(u-1, v-1);
        }
    }
    for (int i = 0; i < n; i++)
        cout << dsu.sz[dsu.find(i)] << " ";
    cout << endl;
    return 0;
}