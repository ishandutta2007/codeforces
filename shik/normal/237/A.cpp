// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 100010
int n,h[N],m[N];
int main()
{
    scanf("%d",&n);
    for ( int i=0; i<n; i++ ) scanf("%d%d",h+i,m+i);
    int ans=1;
    for ( int i=0,j; i<n; i=j ) {
        for ( j=i; j<n&&h[i]==h[j]&&m[i]==m[j]; j++ );
        ans=max(ans,j-i);
    }
    printf("%d\n",ans);
    return 0;
}