// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m,a,ans=0;
	scanf("%d%d",&n,&m);
	while ( n-- ) {
		scanf("%d",&a);
		if ( 3*m<=a ) ans+=a-3*m;
		else ans+=a%m;
	}
	printf("%d\n",ans);
	return 0;
}