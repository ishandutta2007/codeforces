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
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 5005;
int a[SZ];
int n;

void nope() {
    cout << "NO\n";
    return;
}

void solve() {
    vector<PI> pos(n);
    REP(i, n) pos[i] = MP(a[i], i+1);
    sort(ALL(pos));
    int x = pos[0].F, y = pos[n-1].F;
    if (x == y)
        return nope();
    cout << "YES\n";
    REP(i, n-1) {
        if (pos[i].F != x) {
            cout << pos[0].S << " " << pos[i].S << "\n";
        } else {
            cout << pos[n-1].S << " " << pos[i].S << "\n";
        }
    }
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