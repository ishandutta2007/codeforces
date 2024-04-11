// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
void d2t( int n, int *x ) {
	while ( n ) {
		*x++=n%3;
		n/=3;
	}
}
int main()
{
	int a,b=0,c,x[50]={},y[50]={},z[50]={};
	scanf("%d%d",&a,&c);
	d2t(a,x); d2t(c,z);
	for ( int i=0; i<50; i++ ) y[i]=(z[i]-x[i]+3)%3;
	for ( int i=49; i>=0; i-- ) b=b*3+y[i];
	printf("%d\n",b);
	return 0;
}