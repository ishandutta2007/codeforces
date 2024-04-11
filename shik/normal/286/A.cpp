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
    if ( n%4==2 || n%4==3 ) return puts("-1"),0;
    for ( int i=1; i<=n; i++ ) {
        if ( i==n-i+1 ) printf("%d",i);
        else if ( i<=n/2 ) {
            printf("%d %d",i+1,n-i+1);
            i++;
        } else {
            printf("%d %d",n-i,i);
            i++;
        }
        putchar(i==n?'\n':' ');
    }
    return 0;
}