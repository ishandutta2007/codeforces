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

#define N 100010
const int MOD=1e9+7;

int n,clr[N];
vector<int> e[N];

bool vis[N];
int dp[N][2];
void go( int p ) {
    if ( clr[p]==1 ) {
        dp[p][0]=0;
        dp[p][1]=1;
        return;
    }
    vis[p]=1;
    FOR(it,e[p]) go(*it);
    int m=SZ(e[p]);
    vector<int> s(m+1);
    s[m]=1;
    for ( int i=m-1; i>=0; i-- ) s[i]=1LL*s[i+1]*(dp[e[p][i]][0]+dp[e[p][i]][1])%MOD;
    dp[p][0]=s[0];
    LL now=1,val=0;
    REP(i,m) {
        val+=now*s[i+1]%MOD*dp[e[p][i]][1]%MOD;
        now=now*(dp[e[p][i]][0]+dp[e[p][i]][1])%MOD;
    }
    dp[p][1]=val%MOD;
}

int main() {
    RI(n);
    REP1(i,1,n-1) {
        int p;
        RI(p);
        e[p].PB(i);
    }
    REP(i,n) RI(clr[i]);
    LL ans=1;
    REP(i,n) if ( !vis[i] && clr[i]==0 ) {
        go(i);
        if ( i==0 ) ans=ans*dp[i][1]%MOD;
        else ans=ans*(dp[i][0]+dp[i][1])%MOD;
    }
    cout<<ans<<endl;
    return 0;
}