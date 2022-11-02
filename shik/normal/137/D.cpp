// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 510
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
inline bool chkmin( int &a, int b ) {
	if ( b<a ) {
		a=b;
		return 1;
	} else return 0;
}
char s[N];
int dpw[N][N],dp[N][N],pre[N][N];
int w( int l, int r ) {
	int &ret=dpw[l][r];
	if ( ret!=-1 ) return ret;
	if ( l==r ) return ret=0;
	if ( l+1==r ) return ret=(s[l]!=s[r]);
	return ret=w(l+1,r-1)+(s[l]!=s[r]);
}
int go( int n, int m ) {
	int &ret=dp[n][m];
	if ( ret!=-1 ) return ret;
	if ( n==0 ) return ret=0;
	if ( m==1 ) return ret=w(1,n);
	ret=w(1,n);
	pre[n][m]=1;
	for ( int i=1; i<=n; i++ ) if ( chkmin(ret,go(i-1,m-1)+w(i,n)) ) pre[n][m]=i;
	return ret;
}
void gen( int l, int r ) {
	for ( int i=l,j=r; i<=r; i++,j-- ) putchar(s[min(i,j)]);
}
void trace( int n, int m ) {
	int p=pre[n][m];
	if ( m==1 || p==1 ) gen(1,n);
	else {
		trace(p-1,m-1);
		putchar('+');
		gen(p,n);
	}
}
int main()
{
	memset(dpw,-1,sizeof(dpw));
	memset(dp,-1,sizeof(dp));
	int n,m;
	scanf("%s%d",s+1,&m);
	n=strlen(s+1);
	printf("%d\n",go(n,m));
	trace(n,m); puts("");
	return 0;
}