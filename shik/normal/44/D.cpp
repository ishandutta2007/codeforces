// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
double sqr( double x ) { return x*x; }
int n,x[5010],y[5010],z[5010];
double dis( int a, int b ) { return sqrt(sqr(x[a]-x[b])+sqr(y[a]-y[b])+sqr(z[a]-z[b])); }
int main()
{
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) scanf("%d%d%d",x+i,y+i,z+i);
	double ans=1e100;
	for ( int i=1; i<n; i++ )
		for ( int j=i+1; j<n; j++ )
			ans=min(ans,(dis(0,i)+dis(0,j)+dis(i,j))/2);
	printf("%.9f\n",ans);
	return 0;
}