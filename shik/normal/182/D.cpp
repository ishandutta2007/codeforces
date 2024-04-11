// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 100010
char a[N],b[N];
int main()
{
    int n=strlen(gets(a));
    int m=strlen(gets(b));
    int g=__gcd(n,m);
    if ( strncmp(a,b,g) ) return puts("0"),0;
    for ( int i=0; i<n; i++ ) if ( a[i]!=a[i%g] ) return puts("0"),0;
    for ( int i=0; i<m; i++ ) if ( b[i]!=b[i%g] ) return puts("0"),0;
    int ans=0;
    for ( int i=1; i<=g; i++ ) if ( g%i==0 ) {
        bool ok=1;
        for ( int j=i; j<g&&ok; j++ ) if ( a[j]!=a[j%i] ) ok=0;
        if ( ok ) ans++;
    }
    printf("%d\n",ans);
    return 0;
}