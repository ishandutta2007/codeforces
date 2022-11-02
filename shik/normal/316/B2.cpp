// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 1010
int fa[N],lv[N];
bool gg[N],leaf[N],dp[N];
int main()
{
    int n,x;
    scanf("%d%d",&n,&x);
    for ( int i=1; i<=n; i++ ) scanf("%d",fa+i);
    for ( int i=1; i<=n; i++ ) leaf[i]=1;
    for ( int i=1; i<=n; i++ ) leaf[fa[i]]=0;
    gg[x]=1;
    for ( int i=0; i<n; i++ ) for ( int j=1; j<=n; j++ ) if ( gg[fa[j]] ) gg[j]=1;
    for ( int i=0; i<n; i++ ) for ( int j=1; j<=n; j++ ) lv[j]=lv[fa[j]]+1;
    dp[0]=1;
    for ( int i=1; i<=n; i++ ) if ( leaf[i] && !gg[i] )
        for ( int j=n; j>=lv[i]; j-- ) dp[j]|=dp[j-lv[i]];
    for ( int i=0; i<=n; i++ ) if ( dp[i] ) printf("%d\n",i+lv[x]);
    return 0;
}