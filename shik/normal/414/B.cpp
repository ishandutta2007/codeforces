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

#define N 2010
const int MOD=1e9+7;

int dp[N][N];
int go( int n, int k ) {
    int &ret=dp[n][k];
    if ( ret!=-1 ) return ret;
    if ( k==1 ) return n;
    ret=0;
    REP1(i,1,n) {
        ret+=go(n/i,k-1);
        if ( ret>=MOD ) ret-=MOD;
    }
    return ret;
}
int main() {
    int n,k;
    RI(n,k);
    memset(dp,-1,sizeof(dp));
    int ans=go(n,k);
    printf("%d\n",ans);
    return 0;
}