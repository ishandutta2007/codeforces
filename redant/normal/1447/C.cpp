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

const int MX = 200005;
int a[MX];
int n;
LL W;

void solve() {
    LL mn = (W + 1) / 2, mx = W;
    VPI w(n);
    REP(i, n) w[i].F = a[i], w[i].S=i+1;
    sort(ALL(w));
    LL cw = w[n-1].F;
    int i = 0, j = n-1;
    while (i <= j) {
        // cout << i << ", " << j << " : cw = " << cw << endl;
        if (cw >= mn && cw <= mx) {
            cout << (i+1) << "\n";
            REP(k, i) cout << w[k].S << " ";
            cout << w[j].S << "\n";
            return;
        }

        if (cw < mn) {
            cw += w[i++].F;
        } else {
            cw -= w[j--].F;
            cw += w[j].F;
        }
    }
    cout << "-1\n";
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>W;
        REP(i, n) {
            cin>>a[i];
        }
        solve();
        // cout << endl;
    }    
    return 0;
}