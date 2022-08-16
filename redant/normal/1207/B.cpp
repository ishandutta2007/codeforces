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

const int SZ = 55;
int r, c;
int a[SZ][SZ], b[SZ][SZ];

bool nope() {
    cout << "-1\n";
    return false;
}

bool solve() {
    VI ans;
    REP(i, r - 1) REP(j, c - 1) {
        if (a[i][j] == 1 && a[i+1][j] == 1 && a[i][j+1] == 1 && a[i+1][j+1] == 1) {
            ans.PB(i+1); ans.PB(j+1);
            REP(ii, 2) REP(jj, 2) b[i+ii][j+jj]=1;
        }
    }
    REP(i, r) REP(j, c)
        if (a[i][j] != b[i][j]) return nope();
    cout << ans.size()/2 << endl;
    REP(i, ((int)ans.size())/2)
        cout << ans[2*i] << " " << ans[2*i+1] << endl;
}

int main() {
    setIO();
    cin>>r>>c;
    REP(i, r) REP(j, c) cin >> a[i][j];
    solve();
    return 0;
}