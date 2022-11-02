// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int t;
	double a,b;
	scanf("%d",&t);
	while ( t-- ) {
		scanf("%lf%lf",&a,&b);
		printf("%.9f\n",0.5+(a==0||b==0?0.5*(b==0):0.5*(a*a/8-(a-min(4*b,a))*max(0.0,(a/4-b))/2)/(a*b)));
	}
	return 0;
}