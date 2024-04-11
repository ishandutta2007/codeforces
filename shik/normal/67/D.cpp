// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1000010
using namespace std;
int x[N],y[N],px[N],py[N],LIS[N]={-1};
bool cp( int a, int b ) { return px[a]>px[b]; }
int main()
{
	int n,i,len=0;
	scanf("%d",&n);
	for ( i=0; i<n; i++ ) scanf("%d",x+i);
	for ( i=0; i<n; i++ ) scanf("%d",y+i);
	for ( i=0; i<n; i++ ) px[x[i]]=py[y[i]]=i;
	sort(y,y+n,cp);
	for ( i=0; i<n; i++ ) {
		int now=py[y[i]];
		if ( now>LIS[len] ) LIS[++len]=now;
		else *lower_bound(LIS,LIS+len,now)=now;
	}
	printf("%d\n",len);
	return 0;
}