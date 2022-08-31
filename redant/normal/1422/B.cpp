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

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 105;
LL a[SZ][SZ];
int n, m;

LL get(VI &s, int k) {
    LL r = 0;
    REP(i, 4) r+=abs(s[i]-s[k]);
    return r;
}

LL solve() {
    LL r = 0;
    REP(i, n/2) REP(j, m/2) {
        VI s;
        s.PB(a[i][j]);
        s.PB(a[n-1-i][j]);
        s.PB(a[n-1-i][m-1-j]);
        s.PB(a[i][m-1-j]);
        LL rr = get(s, 0);
        REP(k, 3) rr = min(rr, get(s, k+1));
        r += rr;
        // cout << i << ", " << j << " = " << rr << endl;
    }
    if (n&1) {
        REP(j, m/2) 
            r+=abs(a[n/2][m-1-j]-a[n/2][j]);
    }
    if (m&1) {
        REP(i, n/2) 
            r+=abs(a[n-1-i][m/2]-a[i][m/2]);
    }
    return r;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>m;
        REP(i, n) REP(j, m) {
            cin>>a[i][j];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}