// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 50
using namespace std;
int n,m;
char tbl[N][N];
bool input() {
	if ( scanf("%d%d",&n,&m)==EOF ) return 0;
	for ( int i=0; i<n; i++ ) scanf("%s",tbl[i]);
	return 1;
}
int vis[N][N],clr[N][N],used[7][7],dom[130][2],cnt[7],vvv[7][7],ucs;
bool put( int x, int y, int c ) {
	int ret=1;
	if ( ++cnt[c]>2 ) ret=0;
	for ( int i=x; i<=x+1; i++ ) for ( int j=y; j<=y+1; j++ ) {
		clr[i][j]=c;
		int *t=dom[(int)tbl[i][j]];
		if ( t[0]==-1 ) t[0]=c;
		else {
			t[1]=c;
			if ( used[t[0]][t[1]] ) ret=0;
			used[t[0]][t[1]]++;
			used[t[1]][t[0]]++;
		}
	}
	return ret;
}
void rec( int x, int y, int c ) {
	cnt[c]--;
	for ( int i=x; i<=x+1; i++ ) for ( int j=y; j<=y+1; j++ ) {
		int *t=dom[(int)tbl[i][j]];
		if ( t[1]!=-1 ) {
			used[t[0]][t[1]]--;
			used[t[1]][t[0]]--;
			t[1]=-1;
		} else t[0]=-1;
	}
}
int flg;
char sol[N][N];
void output() {
	for ( int i=0; i<n; i++ ) for ( int j=0; j<m; j++ )
		if ( tbl[i][j]=='.' ) sol[i][j]='.';
		else sol[i][j]=clr[i][j]+'0';
}
int go( int x, int y, int t ) {
	if ( y==m ) return go(x+1,0,t);
	if ( x==n ) {
		if ( flg==0 ) output();
		return flg=1;
	}
	if ( tbl[x][y]=='.' || vis[x][y] ) return go(x,y+1,t);
	if ( x==n-1 || y==m-1 || tbl[x+1][y]=='.' || tbl[x][y+1]=='.' || tbl[x+1][y+1]=='.' ) return 0;
	vis[x][y]=vis[x+1][y]=vis[x][y+1]=vis[x+1][y+1]=1;
	int ret=0;
	for ( int i=0; i<=t; i++ ) {
		if ( put(x,y,i) ) ret+=go(x,y+1,(i<t||t==6)?t:t+1);
		rec(x,y,i);
	}
	vis[x][y]=vis[x+1][y]=vis[x][y+1]=vis[x+1][y+1]=0;
	return ret;
}
void solve() {
	memset(dom,-1,sizeof(dom));
	flg=0;
	int ans=go(0,0,0)*5040;
	printf("%d\n",ans);
	for ( int i=0; i<n; i++,puts("") ) for ( int j=0; j<m; j++ ) putchar(sol[i][j]);
}
int main()
{
	while ( input() ) {
		solve();
	}
	return 0;
}