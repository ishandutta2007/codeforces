// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 2010
#define MOD 1000000007
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char a[N],b[N];
int dp[100010][2];
int main()
{
    gets(a); gets(b);
    int n=strlen(a),m;
    scanf("%d",&m);
    dp[0][strcmp(a,b)!=0]=1;
    int cnt=0;
    for ( int i=0; i<n; i++ ) a[i+n]=a[i];
    for ( int i=0; i<n; i++ ) if ( strncmp(a+i,b,n)==0 ) cnt++;
    for ( int i=0; i<m; i++ ) {
        dp[i+1][0]=(1LL*dp[i][0]*(cnt-1)+1LL*dp[i][1]*cnt)%MOD;
        dp[i+1][1]=(1LL*dp[i][0]*(n-cnt)+1LL*dp[i][1]*(n-1-cnt))%MOD;
    }
    printf("%d\n",dp[m][0]);
    return 0;
}