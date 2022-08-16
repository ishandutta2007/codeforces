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

const int MX = 200005;
const int LMX = 20;
PI a[MX];
VPI b;
int mn[MX][LMX];
int res[MX];
int n;

void go() {
    VI ids(n);
    iota(ALL(ids), 0);
    auto cmp = [&](int i, int j) {
        return b[i] < b[j];
    };
    sort(ALL(ids), cmp);

    // mins
    REP(i, n) mn[i][0] = ids[i];
    for (int j = 1, p = 1; 2 * p <= n; j++, p*=2)
        REP(i, n) {
            mn[i][j] = mn[i][j - 1];
            if (i + p < n && b[mn[i][j-1]].S > b[mn[i+p][j-1]].S) {
                mn[i][j] = mn[i+p][j-1];
            }
        }

    auto getMin = [&](int l, int r) {
        assert(l <= r);
        int n = r - l + 1;
        int j = 0, p = 1;
        while (2 * p <= n) p *= 2, j += 1;
        r = r - p + 1;
        if (b[mn[l][j]].S < b[mn[r][j]].S)
            return mn[l][j];
        return mn[r][j];
    };

    REP(i, n) {
        int l = 0, r = n;
        // cout << "i = " << i << endl;
        if (b[ids[0]].F >= a[i].F) {
            r = 0;
        }
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (b[ids[m]].F >= a[i].F)
                r = m;
            else l = m;
        }
        // cout << "l,r = " << l << "," << r << endl;
        if (r == 0) continue;
        int mni = getMin(0, l);
        // cout << "mni = " << mni << endl;
        if (b[mni].F < a[i].F && b[mni].S < a[i].S) {
            res[i] = mni + 1;
            // cout << "res["<<i<<"] = " << (mni + 1) << endl;
        }
        // cout << endl;
    }
}

void solve() {
    fill(res, res+n, -1);
    b.resize(n);
    REP(i, n) b[i] = a[i];
    go();
    REP(i, n) b[i] = {a[i].S, a[i].F};
    go();
    REP(i, n) cout << res[i] << " ";
    cout << "\n";
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>a[i].F>>a[i].S;
        }
        solve();
    }
    
    return 0;
}