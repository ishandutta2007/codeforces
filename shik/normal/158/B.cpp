// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,x,c[5]={},ans=0;
	scanf("%d",&n);
	while ( n-- ) {
		scanf("%d",&x);
		c[x]++;
	}
	ans+=c[4]+c[3];
	c[1]-=c[3];
	ans+=c[2]/2;
	if ( c[2]%2==1 ) ans++,c[1]-=2;
	if ( c[1]>0 ) ans+=(c[1]+3)/4;
	printf("%d\n",ans);
	return 0;
}