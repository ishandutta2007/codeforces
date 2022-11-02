// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 210
#define MOD 1000000007
char s[N];
int n,two[N];
int mul( int a, int b ) { return 1LL*a*b%MOD; }
int go( int p ) {
    if ( p==n ) return 0;
    int c=go(p+1);
    int ans=mul(2,c);
    if ( s[p]=='1' ) ans+=two[2*(n-p-1)];
    ans%=MOD;
    return ans;
}
int main()
{
    for ( int i=two[0]=1; i<N; i++ ) two[i]=mul(2,two[i-1]);
    n=strlen(gets(s));
    int ans=go(0);
    printf("%d\n",ans);
    return 0;
}