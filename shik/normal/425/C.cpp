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
#define K 310
const int INF=1e9;

int n,m,s,e,a[N],b[N];
vector<int> vb[N];
int dp[K];
int main() {
    RI(n,m,s,e);
    REP(i,n) RI(a[i]);
    REP(i,m) RI(b[i]);
    REP(i,m) vb[b[i]].PB(i);
    REP(i,K) dp[i]=INF;
    dp[0]=-1;
    int ans=0;
    REP(i,n) {
        auto &v=vb[a[i]];
        auto last_it=v.end();
        for ( int j=300; j>=0; j-- ) if ( dp[j]<INF ) {
            auto it=upper_bound(v.begin(),last_it,dp[j]);
            if ( it!=v.end() ) dp[j+1]=min(dp[j+1],*it);
            last_it=it;
        }
        REP1(j,ans+1,300) if ( e*j+i+1+dp[j]+1<=s ) ans=j;
    }
    printf("%d\n",ans);
    return 0;
}