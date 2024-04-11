// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
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
inline void chkmin( LL &a, LL b ) { if ( b<a ) a=b; }

#define N 100
#define M 20

const LL INF=2e18;

struct P {
    int x,k,m,msk;
    void read() {
        RI(x,k,m);
        msk=0;
        REP(i,m) {
            int pid;
            RI(pid);
            msk|=two(pid-1);
        }
    }
} p[N];

int n,m,b;
LL dp[1<<M];
int main() {
    RI(n,m,b);
    REP(i,n) p[i].read();
    sort(p,p+n,[](P x, P y) { return x.k<y.k; });
    fill(dp,dp+two(m),INF);
    dp[0]=0;
    LL ans=INF;
    REP(i,n) {
        REP(j,1<<m) if ( dp[j]!=-1 ) chkmin(dp[j|p[i].msk],dp[j]+p[i].x);
        chkmin(ans,dp[two(m)-1]+(LL)p[i].k*b);
    }
    if ( ans==INF ) puts("-1");
    else cout<<ans<<endl;
    return 0;
}