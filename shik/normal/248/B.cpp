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
    int n,r=1;
    scanf("%d",&n);
    if ( n<3 ) return puts("-1"),0;
    if ( n==3 ) return puts("210"),0;
    for ( int i=1; i<n; i++ ) r=r*10%210;
    r=210-r;
    printf("1");
    for ( int i=1; i<n-3; i++ ) printf("0");
    printf("%03d\n",r);
    return 0;
}