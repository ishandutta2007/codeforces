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

const int SZ = 300005;
int a[SZ];
int n, m, k, x, y;

int solve() {
    int mx = 0;
    REP(i, n) mx = max(mx, a[i]);
    REP(i, n) {
        if (a[i] != mx) continue;
        if (i > 0 && a[i-1] != mx)
            return i+1;
        if (i + 1 < n && a[i+1] != mx)
            return i+1;
    }   
    return -1; 
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>a[i];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}