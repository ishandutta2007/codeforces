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
    int n,a,m,b;
    scanf("%d%d%d",&n,&m,&a);
    for ( int i=1; i<=n; i++ ) scanf("%*d");
    scanf("%d",&b);
    if ( n>m ) puts(a*b>0?"Infinity":"-Infinity");
    else if ( n<m ) puts("0/1");
    else {
        int g=__gcd(a,b);
        a/=g; b/=g;
        if ( b<0 ) a=-a,b=-b;
        printf("%d/%d\n",a,b);
    }
    return 0;
}