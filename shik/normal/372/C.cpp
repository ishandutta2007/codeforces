// TwT514 {{{
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <bitset>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#define SZ(x) ((int)(x).size())
#define FOR(i,c) for (__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define REP(i,n) for (int i=0; i<(int)(n); i++)
#define REP1(i,a,b) for (int i=(int)(a); i<=(int)(b); i++)
#define ALL(x) (x).begin(),(x).end()
#define MS0(x,n) memset((x),0,(n)*sizeof(*x))
#define MS1(x,n) memset((x),-1,(n)*sizeof(*x))
#define MP make_pair
#define PB push_back
#define RI(a) scanf("%d",&(a))
#define RII(a,b) scanf("%d%d",&(a),&(b))
#define RIII(a,b,c) scanf("%d%d%d",&(a),&(b),&(c))
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
// }}}

#define N 150010
#define M 310
int a[M],b[M],t[M];
LL dp[2][N];
int main() {
    int n,m,d;
    RIII(n,m,d);
    REP1(i,1,m) RIII(a[i],b[i],t[i]);
    REP1(i,1,n) dp[0][i]=b[1]-abs(a[1]-i);
    int u=0;
    REP1(i,2,m) {
        static int q[N],ql,qr;
        ql=qr=0;
        auto add = [&]( int x ) {
            while ( ql!=qr && dp[u][q[qr-1]]<=dp[u][x] ) qr--;
            q[qr++]=x;
        };
        int dt=min((LL)d*(t[i]-t[i-1]),(LL)n);
        REP1(j,1,dt) add(j);
        REP1(j,1,n) {
            if ( j+dt<=n ) add(j+dt);
            if ( q[ql]<j-dt ) ql++;
            dp[u^1][j]=dp[u][q[ql]]+b[i]-abs(a[i]-j);
        }
        u^=1;
    }
    LL ans=dp[u][1];
    REP1(i,1,n) ans=max(ans,dp[u][i]);
    cout << ans << endl;
    return 0;
}