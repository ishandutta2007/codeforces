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

const int SZ = 205;
int a[SZ][3];
int ans[SZ];
int n;

bool solve(int i) {
    if (i == n) {
        if (ans[n-1] == ans[0])
            return false;
        return true;
    }
    REP(j, 3) {
        if (i == 0 || (ans[i-1] != a[i][j])) {
            ans[i] = a[i][j];
            if (solve(i+1)) break;
        }
    }
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(j, 3)
            REP(i, n) {
                cin>>a[i][j];
            }
        solve(0);
        REP(i, n) cout << ans[i] << " ";
        cout << "\n";
    }
    
    return 0;
}