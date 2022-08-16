#include <bits/stdc++.h>
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

const int MX = 505;
int a[MX][MX];
int b[MX][MX];
int n, m;

void solve() {
    int colInd = -1;
    REP(i, m) REP(j, n) 
        if (colInd == -1 && b[i][j] == a[0][0]) {
            colInd = i;
            break;
        }
    map<int, int> inds;
    REP(i, n) inds[b[colInd][i]] = i;
    vector<int> ord(n);
    iota(ALL(ord), 0);
    sort(ALL(ord), [&](int i, int j) {
        return inds[a[i][0]] < inds[a[j][0]];
    });
    REP(i, n) {
        REP(j, m) cout << a[ord[i]][j] << " ";
        cout << "\n";
    }
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>m;
        REP(i, n) REP(j, m) cin>>a[i][j];
        REP(i, m) REP(j, n) cin>>b[i][j];
        solve();
    }
    
    return 0;
}