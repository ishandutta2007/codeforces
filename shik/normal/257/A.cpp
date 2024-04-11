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
    int n,m,k,a[55];
    scanf("%d%d%d",&n,&m,&k);
    for ( int i=0; i<n; i++ ) scanf("%d",a+i);
    sort(a,a+n); reverse(a,a+n);
    int ans=0;
    while ( k<m && ans<n ) k=(k-1)+a[ans++];
    if ( k<m ) puts("-1");
    else printf("%d\n",ans);
    return 0;
}