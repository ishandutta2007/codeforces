// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 200010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,x[N];
double p1,p2,p3;
bool chk( double d ) {
	int t=0;
	p1=x[0]+d;
	while ( t<n && x[t]<=p1+d ) t++;
	if ( t==n ) t--;
	p2=x[t]+d;
	while ( t<n && x[t]<=p2+d ) t++;
	if ( t==n ) t--;
	p3=x[t]+d;
	while ( t<n && x[t]<=p3+d ) t++;
	return t==n;
}
int main()
{
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) scanf("%d",x+i);
	sort(x,x+n);
	double L=0,R=1e9;
	for ( int i=0; i<100; i++ ) {
		double M=(L+R)/2;
		if ( chk(M) ) R=M;
		else L=M;
	}
	double M=(L+R)/2;
	printf("%.9f\n",M);
	chk(M);
	printf("%.9f %.9f %.9f\n",p1,p2,p3);
	return 0;
}