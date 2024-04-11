// {{{ by shik
// #include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
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

inline void chkmax( int &a, int b ) {
    if ( b>a ) a=b;
}

#define N 220

bool vis[N][N];
int n,dp[N][N][2];
VI e[N];

void go( int p, int f ) {
    if ( vis[p][f]++ ) return;
    int a=0,b=0;
    for ( auto i:e[p] ) if ( i!=f ) {
        go(i,p);
        auto x=dp[i][p][0]+1;
        if ( x>=a ) {
            b=a;
            a=x;
        } else if ( x>=b ) {
            b=x;
        }
        chkmax(dp[p][f][1],dp[i][p][1]);
    }
    dp[p][f][0]=a;
    chkmax(dp[p][f][1],a+b);
}

int main() {
    RI(n);
    REP(i,n-1) {
        int a,b;
        RI(a,b);
        e[a].PB(b);
        e[b].PB(a);
    }
    int ans=0;
    REP1(i,1,n) for ( auto j:e[i] ) {
        go(i,j);
        go(j,i);
        ans=max(ans,dp[i][j][1]*dp[j][i][1]);
    }
    printf("%d\n",ans);
    return 0;
}