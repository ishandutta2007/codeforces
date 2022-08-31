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

const int MX = 1501;
int a[MX];
unordered_map<int, vector<PI> > mend;
int n;

void solve() {
    int mx = 0, mxs = 0;
    for (int j = 1; j <= n; j++) {
        int s = 0;
        for (int i = j; i > 0; i--) {
            s += a[i];
            mend[s].PB(MP(i, j));
        }
    }

    VPI res;

    ITR(it, mend) {
        VPI cend = it->S;
        VPI cres;
        int r = 0;
        TRAV(pp, cend) {
            if (pp.F > r) {
                cres.PB(pp);
                r = pp.S;
            }
        }
        if (SZ(cres) > SZ(res))
            res = cres;
    }

    cout << SZ(res) << "\n";
    TRAV(pp, res)
        cout << pp.F << " " << pp.S << "\n";
}

int main() {
    setIO();
    cin>>n;
    REP(i, n) {
        cin>>a[i+1];
    }
    solve();    
    return 0;
}