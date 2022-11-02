// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 110
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,m,e[N][N],c[N];
void go( int p ) {
	int v[3]={};
	for ( int i=1; i<=n; i++ ) if ( e[p][i] ) v[c[i]]=1;
	for ( int i=1; i<=2; i++ ) if ( !v[i] ) c[p]=i;
	if ( !c[p] ) return;
	for ( int i=1; i<=n; i++ ) if ( e[p][i] && !c[i] ) go(i);
}
int main()
{
	int a,b;
	scanf("%d%d",&n,&m);
	while ( m-- ) {
		scanf("%d%d",&a,&b);
		e[a][b]=e[b][a]=1;
	}
	for ( int i=1; i<=n; i++ ) if ( !c[i] ) go(i);
	int ans=count(c+1,c+n+1,0);
	if ( (n-ans)%2==1 ) ans++;
	printf("%d\n",ans);
	return 0;
}