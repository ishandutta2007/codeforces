// shik {{{
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(c) begin(c),end(c)
#define REP(i,n) for ( int i=0; i<(int)(n); i++ )
#define REP1(i,a,b) for ( int i=(int)(a); i<=(int)(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
// }}}

#define N 1010
const int MOD=1e9+7;

int n,p[N],dp[N];
int main() {
    RI(n);
    REP1(i,1,n) RI(p[i]);
    dp[1]=2;
    REP1(i,2,n) {
        dp[i]=2;
        REP1(j,p[i],i-1) {
            dp[i]+=dp[j];
            if ( dp[i]>=MOD ) dp[i]-=MOD;
        }
    }
    int ans=0;
    REP1(i,1,n) {
        ans+=dp[i];
        if ( ans>=MOD ) ans-=MOD;
    }
    printf("%d\n",ans);
    return 0;
}