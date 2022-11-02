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
    int n,x,s=0;
    scanf("%d",&n);
    for ( int i=0; i<n; i++ ) {
        scanf("%d",&x);
        s+=x;
    }
    int ans=0;
    for ( int i=1; i<=5; i++ ) if ( (s+i-1)%(n+1) ) ans++;
    printf("%d\n",ans);
    return 0;
}