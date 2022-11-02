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
#define M 10
int n,m,a[N][M],dp[N];

int go( int p ) {
    if ( dp[p] ) return dp[p];
    int mx=1;
    REP1(i,1,n) {
        bool good=1;
        REP(j,m) if ( a[p][j]>=a[i][j] ) good=0;
        if ( good ) mx=max(mx,go(i)+1);
    }
    return dp[p]=mx;
}

int main() {
    RI(n,m);
    REP(i,m) REP1(j,1,n) {
        int x;
        RI(x);
        a[x][i]=j;
    }
    int ans=0;
    REP1(i,1,n) ans=max(ans,go(i));
    printf("%d\n",ans);
    return 0;
}