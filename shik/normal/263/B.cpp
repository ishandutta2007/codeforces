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
    int n,k,a[51]={};
    scanf("%d%d",&n,&k);
    for ( int i=0; i<n; i++ ) scanf("%d",a+i);
    sort(a,a+n);
    if ( k>n || (k<n&&a[n-k]==a[n-k-1]) ) puts("-1");
    else printf("%d %d\n",a[n-k],a[n-k]);
    return 0;
}