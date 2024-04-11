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
    int n;
    scanf("%d",&n);
    if ( n<=2 ) {
        puts("-1");
        return 0;
    }
    for ( int i=n; i>=1; i-- ) printf("%d%c",i,i==1?'\n':' ');
    return 0;
}