// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,x,c[110]={};
	scanf("%d",&n);
	while ( n-- ) {
		scanf("%d",&x);
		c[x]++;
	}
	int ans=0;
	for ( int i=0; i<110; i++ ) ans+=c[i]/2;
	printf("%d\n",ans/2);
	return 0;
}