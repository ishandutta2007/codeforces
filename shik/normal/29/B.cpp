// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	double l,d,v,g,r,t=0;
	scanf("%lf%lf%lf%lf%lf",&l,&d,&v,&g,&r);
	t+=d/v;
	if ( fmod(t,g+r)>=g ) t+=g+r-fmod(t,g+r);
	t+=(l-d)/v;
	printf("%.9f\n",t);
	return 0;
}