// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 100010
int a[N],b[N],c[N],d[N];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
    for ( int i=1; i<=n; i++ ) c[a[i]]++;
    int x=0,y=0,z=0;
    for ( int i=1; i<=n; i++ ) {
        if ( x==a[i] ) b[y]++;
        if ( y==a[i] ) d[y]++,z++;
        else { x=y; y=a[i]; }
    }
    int sml=n,ans=-1;
    for ( int i=1; i<=m; i++ ) {
        int now=n-c[i]-1-b[i]-z+d[i];
        if ( now<sml ) sml=now,ans=i;
    }
    printf("%d\n",ans);
    return 0;
}