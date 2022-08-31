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
int h[MX];
int n, k;
int mn, mx;

PI get(int ph, int i) {
    int mn = max(h[i], ph - k + 1);
    int mx = min(h[i] + k - 1, ph + k - 1);
    if (mx < mn) return {-1, -1};
    return {mn, mx};
}

bool solve() {
    mn = h[0];
    mx = h[0];
    REP(i, n-2) {
        PI a = get(mn, i+1);
        PI b = get(mx, i+1);
        if (a.F != -1) {
            if (b.F == -1) {
                mn = a.F;
                mx = a.S;
            }
            else {
                mn = min(a.F, b.F);
                mx = max(a.S, b.S);
            }
        } else if (b.F != -1) {
            mn = b.F; mx = b.S;
        } else {
            return false;
        }
        if (mn > mx) return false;
    }
    // cout << mn << ", " << mx << endl;
    int fh = h[n-1];
    if (fh + k <= mn) return false;
    if (mx + k <= fh) return false;
    return true; 
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>k;
        REP(i, n) {
            cin>>h[i];
        }
        cout<<(solve()?"YES":"NO")<<"\n";
    }
    
    return 0;
}