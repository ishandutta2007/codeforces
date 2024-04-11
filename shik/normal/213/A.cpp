// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 210
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,c[N],e[N][N],need[N];
int solve( int p ) {
	int ans=n,rem=n,done[N]={},have[N]={};
	while ( rem>0 ) {
		int flg=1;
		while ( flg ) {
			flg=0;
			for ( int i=1; i<=n; i++ ) if ( c[i]==p && !done[i] && have[i]==need[i] ) {
				flg=done[i]=1;
				rem--;
				for ( int j=1; j<=n; j++ ) if ( e[i][j] ) have[j]++;
			}
		}
		if ( rem>0 ) {
			ans++;
			if ( p==3 ) p=1;
			else p++;
		}
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) scanf("%d",c+i);
	for ( int i=1; i<=n; i++ ) {
		int m,x;
		scanf("%d",&m);
		need[i]=m;
		while ( m-- ) {
			scanf("%d",&x);
			e[x][i]=1;
		}
	}
	int ans=(1<<30);
	for ( int i=1; i<=3; i++ ) ans=min(ans,solve(i));
	printf("%d\n",ans);
	return 0;
}