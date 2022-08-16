#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;

template<class T> bool tmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool tmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define PB(x) push_back(x)
#define SZ(x) (int)(x).size()
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define TRAV(a,x) for (auto& a : x)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 2003;
VI nodes[MX];
int par[MX];
int lvl[MX];
int n, mx;

int main() {
    setIO();
    cin>>n;
    REP(i, n+1) par[i] = -1;
    cout << "? 1" << endl;
    REP(i, n) {
        int x; cin >> x;
        tmax(mx, x);
        if (x == 1) par[i+1] = 1;
        nodes[x].PB(i+1);
        lvl[i+1] = x;
    }
    int sz[2] = {0};
    REP(i, mx+1) sz[i%2]+=SZ(nodes[i]);
    int st = sz[0] > sz[1] ? 1 : 0;
    if (st == 0) st = 2;
    for (int l = st; l <= mx; l += 2) {
        TRAV(u, nodes[l]) {
            cout << "? " << u << endl;
            REP(i, n) {
                int d; cin >> d;
                if (d == 1) {
                    int v = i + 1;
                    if (lvl[v] == l-1) par[u] = v;
                    else par[v] = u;
                }
            }
        }
    }
    cout << "!\n";
    for (int u = 2; u <= n; u++)
        cout << u << " " << par[u] << "\n";
    cout << endl;
    return 0;
}