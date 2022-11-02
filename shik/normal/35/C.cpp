// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m,k,x[10],y[10],big=-1,ax=0,ay=0;
	scanf("%d%d%d",&n,&m,&k);
	for ( int i=0; i<k; i++ ) scanf("%d%d",x+i,y+i);
	for ( int i=1; i<=n; i++ ) for ( int j=1; j<=m; j++ ) {
		int sml=abs(i-x[0])+abs(j-y[0]);
		for ( int t=1; t<k; t++ ) sml=min(sml,abs(i-x[t])+abs(j-y[t]));
		if ( sml>big ) big=sml,ax=i,ay=j;
	}
	printf("%d %d\n",ax,ay);
	return 0;
}