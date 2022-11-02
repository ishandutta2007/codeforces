// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1010
using namespace std;
int n,h[N];
int cal( int x ) {
	int i,r=1;
	for ( i=x; i<n; i++ )
		if ( h[i+1]>h[i] ) break;
	r+=i-x;
	for ( i=x; i>1; i-- )
		if ( h[i-1]>h[i] ) break;
	r+=x-i;
	return r;
}
int main()
{
	int i,ans=0;
	scanf("%d",&n);
	for ( i=1; i<=n; i++ ) scanf("%d",h+i);
	for ( i=1; i<=n; i++ ) ans=max(ans,cal(i));
	printf("%d\n",ans);
	return 0;
}