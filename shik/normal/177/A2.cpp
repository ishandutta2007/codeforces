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
    int n,a[110][110];
    scanf("%d",&n);
    for ( int i=0; i<n; i++ ) for ( int j=0; j<n; j++ ) scanf("%d",a[i]+j);
    int ans=0;
    for ( int i=0; i<n; i++ ) ans+=a[i][i];
    for ( int i=0; i<n; i++ ) ans+=a[i][n-i-1];
    for ( int i=0; i<n; i++ ) ans+=a[n/2][i];
    for ( int i=0; i<n; i++ ) ans+=a[i][n/2];
    ans-=3*a[n/2][n/2];
    printf("%d\n",ans);
    return 0;
}