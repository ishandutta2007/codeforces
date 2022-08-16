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

const int MAXX = 1000006;
const int SZ = 2005;
int a[SZ], b[SZ];
int c[SZ], d[SZ];
int n, m;
int maxy[MAXX+1];

int solve() {
    REP(i, n) REP(j, m)
        if (a[i] <= c[j] && b[i] <= d[j]) {
            int &r = maxy[c[j]-a[i]];
            r = max(r, d[j] - b[i] + 1);
        }
    int r = 2 * MAXX, mxy = 0;
    for (int dx = MAXX; dx >= 0; dx--) {
        mxy = max(mxy, maxy[dx]);
        r = min(r, dx + mxy);
    }
    return r;
}

int main() {
    setIO();
        cin>>n>>m;
        REP(i, n) {
            cin>>a[i]>>b[i];
        }
        REP(i, m) {
            cin>>c[i]>>d[i];
        }
        cout<<solve()<<"\n";
    
    return 0;
}