// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 110
using namespace std;
int main()
{
	int n;
	double v,a[N],b[N],r=1e100,s=0;
	scanf("%d%lf",&n,&v);
	for ( int i=0; i<n; i++ ) scanf("%lf",a+i);
	for ( int i=0; i<n; i++ ) scanf("%lf",b+i);
	for ( int i=0; i<n; i++ ) r=min(r,b[i]/a[i]);
	for ( int i=0; i<n; i++ ) s+=a[i]*r;
	printf("%.9f\n",min(s,v));
	return 0;
}