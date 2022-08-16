#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 200005;
int n, m, q;
int rc;
int rdeg[MX];

inline void add(int u, int v, int d) {
    if (u > v) swap(u, v);
    if (rdeg[u] == 0)
        --rc;
    rdeg[u] += d;
    if (rdeg[u] == 0)
        ++rc;
}

int main() {
    setIO();
    cin>>n>>m;
    rc = n;
    REP(i, m) {
        int u, v;
        cin >> u >> v;
        add(u, v, 1);
    }
    
    cin >> q;
    REP(i, q) {
        // REP(j, n) cout << rdeg[j+1] << " ";
        cout << endl;
        int op; cin >> op;
        if (op == 3) {
            cout << rc << "\n";
            continue;
        }
        int u, v;
        cin >> u >> v;
        add(u, v, op == 1 ? 1 : -1);
    }
    
    return 0;
}