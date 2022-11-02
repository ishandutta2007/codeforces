// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
const double eps=1e-12;
int main()
{
	int t1,t2,x1,x2,t0,y1=0,y2=0;
	long double sml=1e100;
	scanf("%d%d%d%d%d",&t1,&t2,&x1,&x2,&t0);
	if ( t0==t2 ) return printf("%d %d\n",t0==t1?x1:0,x2),0;
	for ( int i=1,j=0; i<=x1; i++ ) {
		while ( j<=x2 ) {
			long double now=((long double)i*t1+(long double)j*t2)/(i+j);
			if ( now+eps<t0 ) j++;
			else {
				if ( now<sml+eps ) sml=now,y1=i,y2=j;
				break;
			}
		}
	}
	if ( y1==0 ) y2=x2;
	printf("%d %d\n",y1,y2);
	return 0;
}