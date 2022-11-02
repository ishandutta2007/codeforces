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

#define H 910
#define N 200010
const int MOD=1e9+7;
int dp[2][N];
bool can[2][N];
int main() {
    int n,m;
    RI(n,m);
    dp[0][0]=1;
    can[0][0]=1;
    int h=1,u=0,sh=0;
    while ( 1 ) {
        memset(dp[u^1],0,(n+1)*sizeof(int));
        memset(can[u^1],0,(n+1)*sizeof(bool));
        bool alive=0;
        REP1(i,0,n) if ( can[u][i] ) {
            int me=dp[u][i];
            if ( me>=MOD ) me-=MOD;
            int j=sh-i;
            if ( i+h<=n ) {
                alive=1;
                dp[u^1][i+h]+=me;
                can[u^1][i+h]=1;
            }
            if ( j+h<=m ) {
                alive=1;
                dp[u^1][i]+=me;
                can[u^1][i]=1;
            }
        }
        if ( !alive ) break;
        sh+=h++;
        u^=1;
    }
    LL ans=0;
    REP1(i,0,n) ans+=dp[u][i];
    printf("%d\n",(int)(ans%MOD));
    return 0;
}