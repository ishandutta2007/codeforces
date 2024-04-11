// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps=1e-8;
int main()
{
	int n,v1,v2,ans=0;
	double x[110],gx,gy,sml=1e100;
	scanf("%d%d%d",&n,&v1,&v2);
	for ( int i=1; i<=n; i++ ) scanf("%lf",x+i);
	scanf("%lf%lf",&gx,&gy);
	for ( int i=2; i<=n; i++ ) {
		double t=x[i]/v1+hypot(gx-x[i],gy)/v2;
		if ( t<sml+eps ) {
			sml=t;
			ans=i;
		}
	}
	printf("%d\n",ans);
	return 0;
}