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
    char s[33];
    int dp[4][33];
    int n=strlen(gets(s));
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    for ( int i=0; i<3; i++ ) for ( int j=0; j<n; j++ ) if ( dp[i][j]!=-1 ) {
        int x=0;
        for ( int k=j; k<n; k++ ) {
            x=x*10+s[k]-'0';
            if ( x>1000000 || (k>j&&s[j]=='0') ) break;
            dp[i+1][k+1]=max(dp[i+1][k+1],dp[i][j]+x);
        }
    }
    printf("%d\n",dp[3][n]);
    return 0;
}