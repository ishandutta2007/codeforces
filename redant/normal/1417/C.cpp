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

const int SZ = 300005;
int a[SZ];
int n, k, x, y;
int m;
VI pos[SZ];

void solve() {
    REP(i, n) pos[i+1].clear();
    REP(i, n) {
        pos[a[i]].PB(i+1);
    }
    REP(i, n) {
        pos[i+1].PB(n+1);
    }

    VI r(n+1, n+1);

    REP(i, n) {
        int mx = pos[i+1][0];
        for (int j = 1; j < pos[i+1].size(); j++)
            mx = max(mx, pos[i+1][j] - pos[i+1][j-1]);
        r[mx] = min(r[mx], i+1);
        // cout << "v = " << (i+1) << ", mx = " << mx << endl;
    }


    REP(i, n) {
        r[i+1] = min(r[i+1], r[i]);
    }

    REP(i, n) {
        cout << (r[i+1]>n?-1:r[i+1]) << " ";
    }
    cout << endl;
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