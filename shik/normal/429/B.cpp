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

#define N 1010
int n,m,a[N][N],dp1[N][N],dp2[N][N],dp3[N][N],dp4[N][N];
int main() {
    RI(n,m);
    REP1(i,1,n) REP1(j,1,m) RI(a[i][j]);
    REP1(i,1,n) REP1(j,1,m) dp1[i][j]=a[i][j]+max(dp1[i][j-1],dp1[i-1][j]);
    for ( int i=n; i>=1; i-- ) REP1(j,1,m) dp2[i][j]=a[i][j]+max(dp2[i][j-1],dp2[i+1][j]);
    for ( int i=n; i>=1; i-- ) for ( int j=m; j>=1; j-- ) dp3[i][j]=a[i][j]+max(dp3[i][j+1],dp3[i+1][j]);
    REP1(i,1,n) for ( int j=m; j>=1; j-- ) dp4[i][j]=a[i][j]+max(dp4[i][j+1],dp4[i-1][j]);
    int ans=0;
    REP1(i,2,n-1) REP1(j,2,m-1) {
        ans=max(ans,dp1[i-1][j]+dp2[i][j-1]+dp3[i+1][j]+dp4[i][j+1]);
        ans=max(ans,dp1[i][j-1]+dp2[i+1][j]+dp3[i][j+1]+dp4[i-1][j]);
    }
    printf("%d\n",ans);
    return 0;
}