// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,x,sml,big,ans=0;
	scanf("%d%d",&n,&x);
	sml=big=x;
	while ( --n ) {
		scanf("%d",&x);
		if ( x<sml ) sml=x,ans++;
		else if ( x>big ) big=x,ans++;
	}
	printf("%d\n",ans);
	return 0;
}