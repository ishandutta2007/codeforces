// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,a[N];
int main()
{
    long long ans=0;
    scanf("%d",&n);
    for ( int i=0; i<n; i++ ) scanf("%d",a+i);
    for ( int i=0,j=(1<<20); i<n-1; i++ ) {
        while ( i+j>=n ) j/=2;
        ans+=a[i];
        a[i+j]+=a[i];
        printf("%I64d\n",ans);
    }
    return 0;
}