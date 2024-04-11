// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int a,b,n;
	scanf("%d%d%d",&a,&b,&n);
	for ( int i=-1000; i<=1000; i++ )
		if ( fabs(a*pow(i,n)-b)<1e-9 ) {
			printf("%d\n",i);
			return 0;
		}
	puts("No solution");
	return 0;
}