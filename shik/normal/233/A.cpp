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
    if ( n%2==1 ) {
        puts("-1");
        return 0;
    }
    for ( int i=1; i<=n; i+=2 ) printf("%d %d%c",i+1,i,i==n-1?'\n':' ');
    return 0;
}