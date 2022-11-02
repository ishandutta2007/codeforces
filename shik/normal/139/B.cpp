// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 514
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int f( int x, int y, int z, int a, int b, int c ) {
	int w=(x+y)*2;
	int t=a/z*b;
	if ( t>0 ) return (w+t-1)/t*c;
	else return 999999999;
}
int main()
{
	int n,m,x[N],y[N],z[N],a[N],b[N],c[N],ans=0;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) scanf("%d%d%d",x+i,y+i,z+i);
	scanf("%d",&m);
	for ( int i=0; i<m; i++ ) scanf("%d%d%d",a+i,b+i,c+i);
	for ( int i=0; i<n; i++ ) {
		int sml=f(x[i],y[i],z[i],a[0],b[0],c[0]);
		for ( int j=0; j<m; j++ ) sml=min(sml,f(x[i],y[i],z[i],a[j],b[j],c[j]));
		ans+=sml;
	}
	printf("%d\n",ans);
	return 0;
}