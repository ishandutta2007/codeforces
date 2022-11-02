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
    int n,k,x,ans=0;
    scanf("%d%d",&n,&k);
    while ( n-- ) {
        scanf("%d",&x);
        int s=0;
        while ( x ) {
            if ( x%10==4 || x%10==7 ) s++;
            x/=10;
        }
        ans+=(s<=k);
    }
    printf("%d\n",ans);
    return 0;
}