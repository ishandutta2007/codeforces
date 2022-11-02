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
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int a,b;
    scanf("%d%d",&a,&b);
    if ( b>a ) putchar('G'),b--;
    while ( a>0 || b>0 ) {
        if ( a>0 ) putchar('B'),a--;
        if ( b>0 ) putchar('G'),b--;
    }
    puts("");
    return 0;
}