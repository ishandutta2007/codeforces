// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 5010
using namespace std;
char tbl[N][N];
int n,e[N][N];
int vis[N],dad[N],in[N];
void get( int p, int q ) {
	int sol[N],t=0;
	while ( q!=p ) {
		sol[t++]=q;
		q=dad[q];
	}
	sol[t++]=p;
	while ( e[sol[t-1]][sol[t-3]] ) {
		sol[t-2]=sol[t-1];
		t--;
	}
	printf("%d %d %d\n",sol[t-1],sol[t-2],sol[t-3]);
}
bool go( int p, int f ) {
	in[p]=1;
	dad[p]=f;
	vis[p]=1;
	for ( int i=1; i<=n; i++ ) {
		if ( !e[p][i] ) continue;
		if ( in[i] ) {
			get(i,p);
			return 1;
		}
		if ( !vis[i] && go(i,p) ) return 1;
	}
	in[p]=0;
	return 0;
}
int main()
{
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) scanf("%s",tbl[i]+1);
	for ( int i=1; i<=n; i++ )
		for ( int j=1; j<=n; j++ )
			e[i][j]=(tbl[i][j]-'0');
	for ( int i=1; i<=n; i++ )
		if ( go(i,0) ) return 0;
	puts("-1");
	return 0;
}