#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

typedef long long LL;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;

template<class T> bool tmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool tmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define SZ(x) (int)(x).size()
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define TRAV(a,x) for (auto& a : x)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 300005;
int a[MX];
int n, m, k, x, y;

void solve() {
    vector<int> ok(n+1, 0);
    vector<VI> pos(n+1);
    REP(i, n) pos[a[i]].PB(i);
    int l = 0, r = n - 1;
    int c = 1, d = n;
    while (l <= r) {
        int sz = SZ(pos[c]);
        if (sz) ok[d] = 1;
        else break;
        if (sz > 1) break;
        if (a[l] == c) ++l;
        else if (a[r] == c) --r;
        else break;
        ++c; --d;
    }
    bool all = true;
    REP(i, n) if (!SZ(pos[i+1])) all = false;
    if (all) ok[1] = 1;
    REP(i, n) cout << ok[i+1];
    cout << "\n";
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>a[i];
        }
        solve();
    }
    
    return 0;
}