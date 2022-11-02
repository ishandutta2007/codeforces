// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
map<int,int> dp;
int go( int n ) {
    if ( dp[n] ) return dp[n];
    dp[n]=n+1;
    for ( int i=2; i*i<=n; i++ ) if ( n%i==0 ) dp[n]=max(dp[n],n+max(go(i),go(n/i)));
    return dp[n];
}
int main()
{
    int n,ans=0;
    scanf("%d",&n);
    for ( int i=2; i*i<=n; i++ ) if ( n%i==0 ) ans=max(ans,n+max(go(i),go(n/i)));
    printf("%d\n",max(ans,n+1));
    return 0;
}