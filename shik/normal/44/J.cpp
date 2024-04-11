// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 1010
#define V N*N
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char tbl[N][N],sol[N][N];
int n,m,nv,idx[N][N],vis[V],stk[V],top,scc[V],cho[V],clr[V];
vector<int> e[V],f[V],g[V];
void dfs1( int p ) {
	vis[p]=1;
	FOR(it,e[p]) if ( vis[*it]!=1 ) dfs1(*it);
	stk[top++]=p;
}
void dfs2( int p, int c ) {
	vis[p]=2; scc[p]=c;
	FOR(it,f[p]) if ( vis[*it]!=2 ) dfs2(*it,c);
}
int par( int x ) { return x<nv?x+nv:x-nv; }
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
bool valid( int x, int y ) { return x>=0&&x<n&&y>=0&&y<m; }
int main()
{
	int cb=0,cw=0;
	scanf("%d%d",&n,&m);
	for ( int i=0; i<n; i++ ) scanf("%s",tbl[i]);
	for ( int i=0; i<n; i++ ) for ( int j=0; j<m; j++ ) if ( tbl[i][j]=='b' ) cb++; else if ( tbl[i][j]=='w' ) cw++;
	if ( cw!=cb*2 ) { puts("NO"); return 0; }
	for ( int i=0; i<n; i++ ) for ( int j=0; j<m; j++ ) if ( tbl[i][j]=='b' ) idx[i][j]=nv++;
	for ( int i=0; i<n; i++ ) for ( int j=0; j<m; j++ ) if ( tbl[i][j]=='b' ) {
		int msk=0,p=idx[i][j];
		if ( i-1>=0 && tbl[i-1][j]=='w' && i+1<n && tbl[i+1][j]=='w' ) msk|=1;
		if ( j-1>=0 && tbl[i][j-1]=='w' && j+1<m && tbl[i][j+1]=='w' ) msk|=2;
		if ( msk==0 ) { puts("NO"); return 0; }
		if ( msk==1 ) e[p+nv].push_back(p);
		if ( msk==2 ) e[p].push_back(p+nv);
		if ( msk&1 ) {
			if ( i-2>=0 && tbl[i-2][j]=='b' ) e[p].push_back(idx[i-2][j]+nv);
			if ( i-1>=0 && j-1>=0 && tbl[i-1][j-1]=='b' ) e[p].push_back(idx[i-1][j-1]);
			if ( i-1>=0 && j+1<m && tbl[i-1][j+1]=='b' ) e[p].push_back(idx[i-1][j+1]);
			if ( i+1<n && j-1>=0 && tbl[i+1][j-1]=='b' ) e[p].push_back(idx[i+1][j-1]);
			if ( i+1<n && j+1<m && tbl[i+1][j+1]=='b' ) e[p].push_back(idx[i+1][j+1]);
			if ( i+2<n && tbl[i+2][j]=='b' ) e[p].push_back(idx[i+2][j]+nv);
		}
		if ( msk&2 ) {
			if ( j-2>=0 && tbl[i][j-2]=='b' ) e[p+nv].push_back(idx[i][j-2]);
			if ( i-1>=0 && j-1>=0 && tbl[i-1][j-1]=='b' ) e[p+nv].push_back(idx[i-1][j-1]+nv);
			if ( i+1<n && j-1>=0 && tbl[i+1][j-1]=='b' ) e[p+nv].push_back(idx[i+1][j-1]+nv);
			if ( i-1>=0 && j+1<m && tbl[i-1][j+1]=='b' ) e[p+nv].push_back(idx[i-1][j+1]+nv);
			if ( i+1<n && j+1<m && tbl[i+1][j+1]=='b' ) e[p+nv].push_back(idx[i+1][j+1]+nv);
			if ( j+2<m && tbl[i][j+2]=='b' ) e[p+nv].push_back(idx[i][j+2]);
		}
	}
	for ( int i=0; i<2*nv; i++ ) FOR(it,e[i]) f[*it].push_back(i);
	for ( int i=0; i<2*nv; i++ ) if ( vis[i]!=1 ) dfs1(i);
	int tmp=0;
	for ( int i=top-1; i>=0; i-- ) if ( vis[stk[i]]!=2 ) dfs2(stk[i],++tmp);
	for ( int i=0; i<nv; i++ ) if ( scc[i]==scc[i+nv] ) { puts("NO"); return 0; }
	for ( int i=0; i<top; i++ ) {
		if ( cho[scc[par(stk[i])]] ) continue;
		cho[scc[stk[i]]]=1;
	}
	for ( int i=0; i<n; i++ ) for ( int j=0; j<m; j++ ) if ( tbl[i][j]=='b' ) {
		if ( cho[scc[idx[i][j]]] ) idx[i-1][j]=idx[i+1][j]=idx[i][j];
		else idx[i][j-1]=idx[i][j+1]=idx[i][j];
	}
	for ( int i=0; i<n; i++ ) for ( int j=0; j<m; j++ ) {
		if ( tbl[i][j]=='.' ) sol[i][j]='.';
		else {
			for ( int k=0; k<4; k++ ) {
				int nx=i+dx[k];
				int ny=j+dy[k];
				if ( !valid(nx,ny) || tbl[nx][ny]=='.' || idx[i][j]<=idx[nx][ny] ) continue;
				g[idx[i][j]].push_back(idx[nx][ny]);
			}
		}
	}
	for ( int i=0; i<nv; i++ ) {
		int u[4]={};
		FOR(it,g[i]) u[clr[*it]]=1;
		for ( int j=0; j<4; j++ ) if ( !u[j] ) { clr[i]=j; break; }
	}
	for ( int i=0; i<n; i++ ) for ( int j=0; j<m; j++ ) if ( tbl[i][j]!='.' ) sol[i][j]='a'+clr[idx[i][j]];
	puts("YES");
	for ( int i=0; i<n; i++ ) puts(sol[i]);
	return 0;
}