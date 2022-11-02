// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
const double eps=1e-9;
int main()
{
	double v1,v2,t,f,c,x=0;
	int ans=0;
	scanf("%lf%lf%lf%lf%lf",&v1,&v2,&t,&f,&c);
	if ( v1>=v2 ) { puts("0"); return 0; }
	x+=t*v1;
	while ( x+eps<c ) {
		double dt=x/(v2-v1);
		if ( x+dt*v1+eps>=c ) break;
		ans++;
		x+=dt*v1;
		x+=x/v2*v1;
		x+=f*v1;
	}
	printf("%d\n",ans);
	return 0;
}