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
    int n,a[1010];
    scanf("%d",&n);
    for ( int i=0; i<n; i++ ) scanf("%d",a+i);
    sort(a,a+n);
    for ( int i=2; i<n; i++ ) if ( a[i]>0 && a[i]==a[i-1] && a[i-1]==a[i-2] ) return puts("-1"),0;
    int ans=0;
    for ( int i=1; i<n; i++ ) if ( a[i]>0 && a[i]==a[i-1] ) ans++;
    printf("%d\n",ans);
    return 0;
}