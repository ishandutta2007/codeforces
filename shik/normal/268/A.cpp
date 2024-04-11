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
    int n,a[33],b[33];
    scanf("%d",&n);
    for ( int i=0; i<n; i++ ) scanf("%d%d",a+i,b+i);
    int ans=0;
    for ( int i=0; i<n; i++ ) for ( int j=i+1; j<n; j++ ) if ( i!=j ) ans+=(a[i]==b[j])+(a[j]==b[i]);
    printf("%d\n",ans);
    return 0;
}