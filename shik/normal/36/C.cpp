// by shik
#include <cstdio>
#include <algorithm>
#define N 5000
using namespace std;
struct B { double h,r,R; void read(){ scanf("%lf%lf%lf",&h,&r,&R); } } bow[N];
double y[N];
double cal( B a, double x ) {
	//if ( x>=a.R ) return a.h;
	if ( x<=a.r ) return 0;
	return a.h*(x-a.r)/(a.R-a.r);	
}
double put( B a, B b ) {
	double m1,m2;
	m1=(a.R-a.r)/a.h;
	m2=(b.R-b.r)/b.h;
	if ( m1>m2 ) {
		//puts("XD");
		if ( a.R>b.R ) return max(0.0,b.h-cal(a,b.R));	
		else return max(0.0,cal(b,a.R)-a.h);
	} else {
		//puts("QQ");
		return min(cal(b,a.r),b.h);
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,i,j; double ans=0;
	scanf("%d",&n);
	for ( i=1; i<=n; i++ ) bow[i].read();
	//printf("==%f\n",cal(bow[2],80));
	for ( i=1; i<=n; i++ ) {
		for ( j=1; j<i; j++ ) {
			y[i]=max(y[i],y[j]+put(bow[i],bow[j]));
		}
		ans=max(ans,y[i]+bow[i].h);
		//printf("%d: %f\n",i,y[i]);
	}
	printf("%.9f\n",ans);
	return 0;
}