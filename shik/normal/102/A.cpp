// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 110
using namespace std;
int w[N],e[N][N];
int main()
{
	int n,m,a,b,ans=-1;
	scanf("%d%d",&n,&m);
	for ( int i=1; i<=n; i++ ) scanf("%d",w+i);
	while ( m-- ) {
		scanf("%d%d",&a,&b);
		e[a][b]=e[b][a]=1;
	}
	for ( int i=1; i<=n; i++ )
		for ( int j=i+1; j<=n; j++ ) if ( e[i][j] )
			for ( int k=j+1; k<=n; k++ )
				if ( e[i][k] && e[j][k] ) {
					int now=w[i]+w[j]+w[k];
					if ( ans==-1 || now<ans ) ans=now;
				}
	printf("%d\n",ans);
	return 0;
}
// XD