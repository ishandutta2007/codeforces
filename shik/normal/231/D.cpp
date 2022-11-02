// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int x,y,z,x1,y1,z1,a[7],ans=0;
	scanf("%d%d%d%d%d%d",&x,&y,&z,&x1,&y1,&z1);
	for ( int i=1; i<=6; i++ ) scanf("%d",a+i);
	if ( y<0 ) ans+=a[1];
	if ( y>y1 ) ans+=a[2];
	if ( z<0 ) ans+=a[3];
	if ( z>z1 ) ans+=a[4];
	if ( x<0 ) ans+=a[5];
	if ( x>x1 ) ans+=a[6];
	printf("%d\n",ans);
	return 0;
}