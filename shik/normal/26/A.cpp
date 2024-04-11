// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,cnt[3010]={},i,j,ans=0;
	scanf("%d",&n);
	for ( i=2; i<=n; i++ ) {
		if ( cnt[i] ) continue;
		for ( j=i; j<=n; j+=i ) cnt[j]++;
	}
	for ( j=1; j<=n; j++ )
		if ( cnt[j]==2 ) ans++;
	printf("%d\n",ans);
	return 0;
}