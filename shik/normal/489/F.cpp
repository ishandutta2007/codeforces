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

#define N 514
int n,m,mod,c[N];
LL dp[2][N][N];
int main() {
    RI(n,m,mod);
    REP(i,m) {
        char s[N];
        scanf("%s",s);
        REP(j,n) if ( s[j]=='1' ) c[j]++;
    }
    int c0=0,c1=0;
    REP(i,n) {
        if ( c[i]==0 ) c0++;
        if ( c[i]==1 ) c1++;
    }
    int u=0;
    dp[u][c0][c1]=1;
    REP(i,n-m) {
        REP1(j,0,n) REP1(k,0,n-j) {
            LL me=dp[u][j][k]%mod;
            if ( me==0 ) continue;
            if ( j>=2 ) dp[u^1][j-2][k+2]+=me*(j*(j-1)/2)%mod;
            if ( j>=1 && k>=1 ) dp[u^1][j-1][k]+=me*j*k%mod;
            if ( k>=2 ) dp[u^1][j][k-2]+=me*(k*(k-1)/2)%mod;
        }
        u^=1;
    }
    int ans=dp[u][0][0]%mod;
    printf("%d\n",ans);
    return 0;
}