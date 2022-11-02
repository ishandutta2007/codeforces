// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,rem=1,ans=0;
	pair<int,int> p[1010];
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) scanf("%d%d",&p[i].second,&p[i].first);
	sort(p,p+n);
	for ( int i=n-1; i>=0&&rem>0; i-- ) {
		ans+=p[i].second;
		rem+=p[i].first-1;
	}
	printf("%d\n",ans);
	return 0;
}