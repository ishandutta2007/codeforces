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

inline void chkmin( int &a, int b ) {
    if ( b<a ) a=b;
}

inline void chkmax( int &a, int b ) {
    if ( b>a ) a=b;
}

#define N 2010
#define M 510
#define INF 514514514

char s[N],p[M];
bool good[N];
int fail[M],nx[M][26],dp[2][M][N],sol[N];

int main() {
    scanf("%s%s",s,p);
    int n=strlen(s),m=strlen(p);
    fail[0]=-1;
    for ( int i=0,j=-1; i<m; fail[++i]=++j )
        while ( j>=0 && p[i]!=p[j] ) j=fail[j];
    //REP(i,m+1) printf("%d ",fail[i]); puts("");
    REP(i,m) REP(j,26) {
        char c='a'+j;
        for ( int k=i; k>=0; k=fail[k] ) if ( p[k]==c ) {
            nx[i][j]=k+1;
            break;
        }
        //if ( nx[i][j] ) printf("%d,%c: %d\n",i,c,nx[i][j]);
    }
    REP(i,2) REP(j,M) REP(k,N) dp[i][j][k]=INF;
    int u=0;
    dp[u][0][0]=0;
    int xd=n/m;
    REP(i,n) {
        int c=s[i]-'a';
        REP(j,m) REP1(k,0,xd) dp[u^1][j][k]=INF;
        REP(j,m) REP1(k,0,xd) {
            int me=dp[u][j][k];
            if ( me==INF ) continue;
            if ( nx[j][c]==m ) chkmin(dp[u^1][0][k+1],me);
            else chkmin(dp[u^1][nx[j][c]][k],me);
            chkmin(dp[u^1][j][k],me+1);
        }
        u^=1;
    }
    REP(i,m) REP1(j,0,xd) {
        int lb=dp[u][i][j];
        int ub=n-j*m;
        REP1(k,lb,ub) chkmax(sol[k],j);
    }
    REP1(i,0,n) printf("%d%c",sol[i],i==n?'\n':' ');
    return 0;
}