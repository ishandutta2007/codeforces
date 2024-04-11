// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
bool isp( int n ) {
    if ( n<2 ) return 0;
    for ( int i=2; i*i<=n; i++ ) if ( n%i==0 ) return 0;
    return 1;
}
int rev( int n ) {
    int r=0;
    while ( n ) { 
        r=r*10+n%10;
        n/=10;
    }
    return r;
}
bool chk( int n ) {
    return n!=rev(n) && isp(n) && isp(rev(n));
}
int main()
{
    int n,ans=1;
    scanf("%d",&n);
    while ( n-- ) {
        ans++;
        while ( !chk(ans) ) ans++;
    }
    printf("%d\n",ans);
    return 0;
}