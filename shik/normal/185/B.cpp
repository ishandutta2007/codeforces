// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
double lg( double x ) { return x<=0?-1e100:log(x); }
int s,a[3];
double f( double x[3] ) { return a[0]*lg(x[0])+a[1]*lg(x[1])+a[2]*lg(x[2]); }
int main()
{
	scanf("%d%d%d%d",&s,a,a+1,a+2);
	double x[3]={s/3.0,s/3.0,s/3.0},nx[3],d=s/5.14;
	while ( d>1e-14 ) {
		double l[3]={0,-d,d};
		random_shuffle(l,l+3);
		for ( int i=0; i<3; i++ ) nx[i]=x[i]+l[i];
		if ( nx[0]>=0 && nx[1]>=0 && nx[2]>=0 && f(nx)>f(x) ) memcpy(x,nx,sizeof(x));
		d*=0.999;
	}
	printf("%.20f %.20f %.20f\n",x[0],x[1],x[2]);
	return 0;
}