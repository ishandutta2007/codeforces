// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 60
using namespace std;
int e[N][N],cnt[N];
int main()
{
	int n,a,b;
	scanf("%d",&n);
	for ( int i=1; i<n*(n-1)/2; i++ ) {
		scanf("%d%d",&a,&b);
		cnt[a]++;
		e[a][b]=1;
	}
	for ( int i=1; i<=n; i++ )
		for ( int j=i+1; j<=n; j++ )
			if ( !e[i][j] && !e[j][i] ) {
				if ( cnt[i]>cnt[j] ) printf("%d %d\n",i,j);
				else printf("%d %d\n",j,i);
				break;
			}
	return 0;
}