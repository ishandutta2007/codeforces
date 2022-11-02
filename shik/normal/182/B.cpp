// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int d,n,x,ans=0,now=0;
	scanf("%d%d",&d,&n);
	while ( n-- ) {
		now++;
		if ( now>d ) now=1;
		scanf("%d",&x);
		if ( now!=1 ) {
			ans+=d-now+1;
			now=1;
		}
		now=x;
	}
	printf("%d\n",ans);
	return 0;
}