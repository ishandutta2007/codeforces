// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 110
using namespace std;
int e[N][N],deg[N];
int main()
{
	int n,m,a,b,ans=0;
	scanf("%d%d",&n,&m);
	while ( m-- ) {
		scanf("%d%d",&a,&b);
		e[a][b]=e[b][a]=1;
		deg[a]++; deg[b]++;
	}
	while ( 1 ) {
		int cnt=0,lst[110];
		for ( int i=1; i<=n; i++ ) if ( deg[i]==1 ) lst[cnt++]=i;
		if ( cnt==0 ) break;
		ans++;
		for ( int i=0; i<cnt; i++ ) {
			int p=lst[i];
			deg[p]=0;
			for ( int j=1; j<=n; j++ ) if ( e[p][j] ) {
				e[j][p]=0;
				deg[j]--;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}