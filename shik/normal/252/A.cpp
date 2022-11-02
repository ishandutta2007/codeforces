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
    int n,a[110];
    scanf("%d",&n);
    for ( int i=0; i<n; i++ ) scanf("%d",a+i);
    int ans=0;
    for ( int i=0; i<n; i++ ) {
        int s=0;
        for ( int j=i; j<n; j++ ) ans=max(ans,s^=a[j]);
    }
    printf("%d\n",ans);
    return 0;
}