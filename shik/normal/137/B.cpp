// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,cnt[5010]={},x;
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) {
		scanf("%d",&x);
		cnt[x]++;
	}
	int ans=0;
	for ( int i=1; i<=n; i++ ) if ( cnt[i]>1 ) ans+=cnt[i]-1;
	for ( int i=n+1; i<=5000; i++ ) ans+=cnt[i];
	printf("%d\n",ans);
	return 0;
}