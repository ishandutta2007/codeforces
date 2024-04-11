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

#define N 2014

int n,m;
char mp[N][N];

int smp[N][N];
void build() {
    REP1(i,1,n) REP1(j,1,m) smp[i][j]=smp[i-1][j]+smp[i][j-1]-smp[i-1][j-1]+(mp[i][j]=='#');
}
bool chk( int x1, int y1, int x2, int y2 ) {
    return smp[x2][y2]-smp[x1-1][y2]-smp[x2][y1-1]+smp[x1-1][y1-1]==0;
}

LL solve_0() {
    LL ans=0;
    REP1(i,2,n-1) if ( chk(i,1,i,m) ) ans++;
    REP1(j,2,m-1) if ( chk(1,j,n,j) ) ans++;
    //printf("0: %lld\n",ans);
    return ans;
}

LL solve_1() {
    LL ans=0;
    REP1(i,2,n-1) REP1(j,2,m-1) {
        bool l=chk(i,1,i,j);
        bool r=chk(i,j,i,m);
        bool u=chk(1,j,i,j);
        bool d=chk(i,j,n,j);
        if ( l&&u ) ans++;
        if ( l&&d ) ans++;
        if ( r&&u ) ans++;
        if ( r&&d ) ans++;
    }
    //printf("1: %lld\n",ans);
    return ans;
}

LL solve_2_row() {
    LL ans=0;
    REP1(i,2,n-1) {
        static bool u[N],d[N];
        REP1(j,2,m-1) u[j]=chk(1,j,i,j);
        REP1(j,2,m-1) d[j]=chk(i,j,n,j);
        int cu=0,cd=0;
        REP1(j,2,m-1) {
            if ( mp[i][j]=='#' ) cu=cd=0;
            else {
                if ( u[j] ) ans+=cu+cd-u[j-1];
                if ( d[j] ) ans+=cu+cd-d[j-1];
                cu+=u[j];
                cd+=d[j];
            }
            //printf("%d,%d: u=%d, d=%d, cu=%d, cd=%d, %lld\n",i,j,(int)u[j],(int)d[j],cu,cd,ans);
        }
    }
    return ans;
}

LL solve_2() {
    LL ans=0;
    ans+=solve_2_row();
    static char _mp[N][N];
    REP1(i,1,n) REP1(j,1,m) _mp[i][j]=mp[i][j];
    REP1(i,1,n) REP1(j,1,m) mp[j][n-i+1]=_mp[i][j];
    swap(n,m);
    build();
    ans+=solve_2_row();
    //REP1(i,1,n) REP1(j,1,m) printf("%c%c",mp[i][j],j==m?'\n':' ');
    //printf("2: %lld\n",ans);
    return ans;
}

int main() {
    RI(n,m);
    REP1(i,1,n) scanf("%s",mp[i]+1);
    build();
    LL ans=0;
    ans+=solve_0();
    ans+=solve_1();
    ans+=solve_2();
    printf("%lld\n",ans);
    return 0;
}