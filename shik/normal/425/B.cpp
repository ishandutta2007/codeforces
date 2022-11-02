// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
// }}}

inline int two( int x ) { return 1<<x; }
inline int bit( int x, int i ) { return (x>>i)&1; }

#define N 110
#define INF 514

int n,m,k,a[N][N];

int solve() {
    VI vx,vy;
    REP1(i,1,n) REP1(j,1,m) if ( a[i][j] ) {
        vx.PB(i);
        vy.PB(j);
    }
    sort(ALL(vx)); vx.erase(unique(ALL(vx)),vx.end());
    sort(ALL(vy)); vy.erase(unique(ALL(vy)),vy.end());
    if ( SZ(vx)<=k ) {
        int ret=INF;
        REP(msk,two(SZ(vx))) {
            int now=0;
            REP1(j,1,m) {
                int cnt=0;
                REP(i,SZ(vx)) if ( a[vx[i]][j]!=bit(msk,i) ) cnt++;
                now+=min(cnt,n-cnt);
                if ( now>k || now>ret ) break;
            }
            if ( now<=k ) ret=min(ret,now);
        }
        return ret;
    } else if ( SZ(vy)<=k ) {
        int ret=INF;
        REP(msk,two(SZ(vy))) {
            int now=0;
            REP1(j,1,n) {
                int cnt=0;
                REP(i,SZ(vy)) if ( a[j][vy[i]]!=bit(msk,i) ) cnt++;
                now+=min(cnt,m-cnt);
                if ( now>k || now>ret ) break;
            }
            if ( now<=k ) ret=min(ret,now);
        }
        return ret;

    } else {
        return INF;
    }
}

int main() {
    RI(n,m,k);
    REP1(i,1,n) REP1(j,1,m) RI(a[i][j]);
    REP1(i,1,n) if ( a[i][1] )
        REP1(j,1,m) a[i][j]^=1;
    REP1(i,1,m) if ( a[1][i] )
        REP1(j,1,n) a[j][i]^=1;
    int ans=solve();
    k--;
    REP1(i,2,n) REP1(j,2,m) a[i][j]^=1;
    ans=min(ans,solve()+1);
    k++;
    if ( ans<=k ) printf("%d\n",ans);
    else puts("-1");
    return 0;
}