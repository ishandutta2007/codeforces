// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 514
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
inline int bit( int x, int i ) { return (x>>i)&1; }
int n,m,sb[N][N],dp[10][N][N];
char s[N][N];
bool blk( int x, int y, int l ) { return sb[x+l][y+l]-sb[x+l][y]-sb[x][y+l]+sb[x][y]==l*l; }
int get( int x, int y, int l ) {
	int ans=0,cnt=0;
	for ( int i=0; i<2; i++ ) for ( int j=0; j<2; j++ ) ans|=(blk(x+i*l/2,y+j*l/2,l/2)<<(cnt++));
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for ( int i=0; i<n; i++ ) scanf("%s",s[i]);
	for ( int i=0; i<n; i++ ) for ( int j=0; j<m; j++ ) sb[i+1][j+1]=(s[i][j]=='*')+sb[i+1][j]+sb[i][j+1]-sb[i][j];
	for ( int i=0; i+2<=n; i++ ) for ( int j=0; j+2<=m; j++ ) dp[1][i][j]=get(i,j,2);
	int ans=0;
	for ( int k=2,l=4; l<=n; k++,l*=2 ) for ( int i=0; i+l<=n; i++ ) for ( int j=0; j+l<=m; j++ ) {
		int c=0,t=get(i,j,l);
		for ( int a=0; a<2; a++ ) for ( int b=0; b<2; b++ ) if ( bit(t,c++)==0 && dp[k-1][i+a*l/2][j+b*l/2]!=t ) t=-1;
		dp[k][i][j]=t;
		if ( t!=-1 ) ans++;
	}
	printf("%d\n",ans);
	return 0;
}