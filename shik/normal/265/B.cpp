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
    int n,h1=0,h2,ans=0;
    scanf("%d",&n);
    for ( int i=0; i<n; i++ ) {
        scanf("%d",&h2);
        ans+=abs(h2-h1);
        h1=h2;
    }
    printf("%d\n",ans+n+n-1);
    return 0;
}