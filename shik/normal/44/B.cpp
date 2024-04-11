// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,a,b,c,ans=0;
	scanf("%d%d%d%d",&n,&a,&b,&c); n*=2;
	for ( int i=0; i<=b; i++ ) for ( int j=0; j<=c; j++ ) if ( 0<=n-(2*i+4*j) && n-(2*i+4*j)<=a ) ans++;
	printf("%d\n",ans);
	return 0;
}