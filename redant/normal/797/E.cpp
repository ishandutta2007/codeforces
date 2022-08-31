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

const int MX = 100005;
int a[MX];
const int K = 351;
int res[MX][K];
int n;

void prec() {
    for (int k = K-1; k > 0; k--) {
        for (int p = n; p >= 1; p--) {
            int q = p + a[p] + k;
            if (q > n) res[p][k] = 1;
            else res[p][k] = 1 + res[q][k];
        }
    }
}

int solve(int p, int k) {
    if (k < K) return res[p][k];
    int r = 0;
    while (p <= n) {
        p += a[p] + k;
        r++;
    }
    return r;
}

int main() {
    setIO();
    int t=1; // cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>a[i+1];
        }
        prec();
        int q; cin>>q;
        while(q--) {
            int p,k; cin>>p>>k;
            cout<<solve(p, k)<<"\n";
        }
    }
    
    return 0;
}