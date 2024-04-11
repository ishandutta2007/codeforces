// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,k,a[100000];
int main()
{
    scanf("%d%d",&n,&k);
    for ( int i=0; i<n; i++ ) scanf("%d",a+i);
    for ( int i=0; i<n&&a[i]<=0&&k>0; i++,k-- ) a[i]*=-1;
    sort(a,a+n);
    if ( k%2 ) a[0]*=-1;
    int s=0;
    for ( int i=0; i<n; i++ ) s+=a[i];
    printf("%d\n",s);
    return 0;
}