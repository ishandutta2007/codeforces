// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,h[210],i,sml=10000,w=0;
	scanf("%d",&n);
	for ( i=1; i<=n; i++ ) scanf("%d",h+i);
	h[n+1]=h[1];
	for ( i=1; i<=n; i++ )
		if ( abs(h[i]-h[i+1])<sml ) {
			sml=abs(h[i]-h[i+1]);
			w=i;
		}
	printf("%d %d\n",w,w==n?1:w+1);
	return 0;
}