// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 110
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,e[N][N],v[N],sol[N],sn,tmp[N],tn;
bool dfs( int p, int x ) {
	tmp[tn++]=p;
	v[p]=x;
	for ( int i=1; i<=n; i++ ) if ( e[p][i]!=-1 ) {
		if ( v[i]==-1 ) {
			if ( !dfs(i,e[p][i]^x^1) ) return 0;
		} else if ( (x^v[i]^e[p][i])!=1 ) return 0;
	}
	return 1;
}
bool go( int p, int x ) {
	tn=0;
	if ( dfs(p,x) ) return 1;
	for ( int i=0; i<tn; i++ ) v[tmp[i]]=-1;
	return 0;
}
int main()
{
	memset(e,-1,sizeof(e));
	memset(v,-1,sizeof(v));
	int m,a,b,c;
	scanf("%d%d",&n,&m);
	while ( m-- ) {
		scanf("%d%d%d",&a,&b,&c);
		e[a][b]=e[b][a]=c;
	}
	for ( int i=1; i<=n; i++ ) if ( v[i]==-1 ) {
		if ( go(i,0) ) v[i]=0;
		else if ( go(i,1) ) v[i]=1;
		else return puts("Impossible"),0;
	}
	for ( int i=1; i<=n; i++ ) if ( v[i] ) sol[sn++]=i;
	printf("%d\n",sn);
	for ( int i=0; i<sn; i++ ) printf("%d%c",sol[i],i==sn-1?'\n':' ');
	return 0;
}