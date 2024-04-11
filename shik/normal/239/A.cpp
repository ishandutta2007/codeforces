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
    int y,k,n;
    scanf("%d%d%d",&y,&k,&n);
    bool ok=0;
    for ( int i=k; i<=n; i+=k ) {
        if ( i<=y ) continue;
        if ( ok ) putchar(' ');
        ok=1;
        printf("%d",i-y);
    }
    if ( !ok ) puts("-1");
    else puts("");
    return 0;
}