// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
inline void chkmax( int &a, int b ) { if ( b>a ) a=b; }
#define N 5010
int n,dp[N],c2[N];
LL a[N];
int main()
{
    scanf("%d",&n);
    for ( int i=1; i<=n; i++ ) cin>>a[i];
    for ( int i=1; i<=n; i++ ) while ( a[i]%2==0 ) c2[i]++,a[i]/=2;
    for ( int i=1; i<=n; i++ ) {
        dp[i]=1;
        for ( int j=1; j<i; j++ ) if ( (c2[i]-c2[j]==i-j || c2[i]<i-j) && a[j]%a[i]==0 ) chkmax(dp[i],dp[j]+1);
    }
    int ans=n-*max_element(dp+1,dp+n+1);
    printf("%d\n",ans);
    return 0;
}