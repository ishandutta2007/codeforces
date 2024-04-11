// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,m,app[110][130]={},cnt[110]={}; char c;
	scanf("%d%d",&n,&m);
	for ( int i=0; i<n; i++ ) for ( int j=0; j<m; j++ ) {
		scanf(" %c",&c);
		if ( app[j][(int)c] ) continue;
		app[j][(int)c]=1;
		cnt[j]++;
	}
	int ans=1;
	for ( int i=0; i<m; i++ ) ans=1LL*ans*cnt[i]%1000000007;
	printf("%d\n",ans);
	return 0;
}