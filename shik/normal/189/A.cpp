// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
    int n,a[3],dp[4010];
    scanf("%d%d%d%d",&n,a+0,a+1,a+2);
    dp[0]=0;
    for ( int i=1; i<=n; i++ ) {
        dp[i]=-100000;
        for ( int j=0; j<3; j++ ) if ( i>=a[j] ) dp[i]=max(dp[i],dp[i-a[j]]+1);
    }
    printf("%d\n",dp[n]);
    return 0;
}