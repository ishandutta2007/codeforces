// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long double F( int n ) {
	long double r=1;
	for ( int i=1; i<=n; i++ ) r*=i;
	return r;
}
long double C( int n, int m ) {
	return F(n)/(F(m)*F(n-m));
}
double cal( int a, int x, int n ) {
	double ret=1;
	for ( int i=1; i<=x; i++ ) ret=ret*(a-n-x+i)/(a-x+i);
	return ret;
}
int main()
{
	int n,m,h,s[1010],all=0;
	scanf("%d%d%d",&n,&m,&h);
	for ( int i=1; i<=m; i++ ) scanf("%d",s+i);
	for ( int i=1; i<=m; i++ ) all+=s[i];
	if ( all<n ) {
		puts("-1.0");
		return 0;
	}
	n--;
	s[h]--;
	all--;
	if ( all-s[h]<n ) {
		puts("1.0");
		return 0;
	}
	//printf("%.9f\n",(double)(1-(C(all-s[h],n)/C(all,n))));
	printf("%.9f\n",1-cal(all,s[h],n));
	return 0;
}