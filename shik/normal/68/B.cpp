// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 10010
using namespace std;
int n,k;
double a[N],r;
double cal( double x ) { return x-r*x; }
bool chk( double M ) {
	double cnt=0;
	for ( int i=0; i<n; i++ )
		if ( a[i]>M ) cnt+=cal(a[i]-M);
		else cnt-=M-a[i];
	return cnt>=0;
}
int main()
{
	double L,M,R;
	scanf("%d%d",&n,&k); r=k/100.0;
	for ( int i=0; i<n; i++ ) scanf("%lf",a+i);
	L=0; R=1000;
	while ( L+1e-10<R ) {
		M=(L+R)/2;
		if ( chk(M) ) L=M;
		else R=M;
	}
	printf("%.10f\n",(L+R)/2);
	return 0;
}