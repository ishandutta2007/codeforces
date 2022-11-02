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
    int n,k;
    scanf("%d%d",&n,&k);
    if ( k>n ) return puts("-1"),0;
    if ( n==1 ) return puts("a"),0;
    if ( k==1 ) return puts("-1"),0;
    printf("ab");
    n-=2; k-=2;
    for ( int i=0; i<n-k; i++ ) putchar("ab"[i%2]);
    for ( int i=0; i<k; i++ ) putchar('c'+i);
    puts("");
    return 0;
}