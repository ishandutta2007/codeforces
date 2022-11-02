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
    int n,a,b;
    scanf("%d",&n);
    while ( n-- ) {
        scanf("%d%d",&a,&b);
        int ans=0;
        while ( a>0 && b>0 ) {
            if ( a<b ) swap(a,b);
            ans+=a/b;
            a%=b;
        }
        printf("%d\n",ans);
    }
    return 0;
}