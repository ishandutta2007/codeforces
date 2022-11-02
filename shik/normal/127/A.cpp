// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int n,k; double x[110],y[110],ans=0;
	scanf("%d%d",&n,&k);
	for ( int i=0; i<n; i++ ) scanf("%lf%lf",x+i,y+i);
	for ( int i=1; i<n; i++ ) ans+=hypot(x[i]-x[i-1],y[i]-y[i-1]);
	printf("%f\n",ans*k/50);
	return 0;
}