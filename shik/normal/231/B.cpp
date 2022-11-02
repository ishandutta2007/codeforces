// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,d,l;
	scanf("%d%d%d",&n,&d,&l);
	int big=0,sml=0;
	for ( int i=1; i<=n; i++ ) {
		if ( i&1 ) big+=l,sml++;
		else big--,sml-=l;
	}
	if ( d<sml || d>big ) return puts("-1"),0;
	int sol[110],sgn[110],now=0;
	for ( int i=1; i<=n; i++ ) sol[i]=1;
	for ( int i=1; i<=n; i++ ) sgn[i]=(i%2?1:-1);
	for ( int i=1; i<=n; i++ ) now+=sgn[i]*sol[i];
	for ( int i=1; i<=n; i++ ) while ( sol[i]<l && abs(now+sgn[i]-d)<abs(now-d) ) sol[i]++,now+=sgn[i];
	for ( int i=1; i<=n; i++ ) printf("%d%c",sol[i],i==n?'\n':' ');
	return 0;
}