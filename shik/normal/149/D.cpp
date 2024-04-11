// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 777
#define MOD 1000000007
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
inline void pl( int &a, int b ) { a=(a+b)%MOD; }
char s[N];
int mat[N],dp[N][N][3][3]; // 0:black, 1:red, 2:blue
int go( int l, int r, int x, int y ) {
	int &ret=dp[l][r][x][y];
	if ( ret!=-1 ) return ret;
	if ( l>r ) return ret=1;
	ret=0;
	if ( mat[l]==r ) {
		for ( int i=1; i<=2; i++ ) if ( x!=i ) pl(ret,go(l+1,r-1,i,0));
		for ( int i=1; i<=2; i++ ) if ( y!=i ) pl(ret,go(l+1,r-1,0,i));
	} else {
		int m=mat[l];
		for ( int i=1; i<=2; i++ ) if ( x!=i ) pl(ret,1LL*go(l+1,m-1,i,0)*go(m+1,r,0,y)%MOD);
		for ( int i=1; i<=2; i++ ) pl(ret,1LL*go(l+1,m-1,0,i)*go(m+1,r,i,y)%MOD);
	}
	return ret;
}
int main()
{
	int n=strlen(gets(s+1)),stk[N],top=-1;
	for ( int i=1; i<=n; i++ ) {
		if ( s[i]=='(' ) stk[++top]=i;
		else {
			mat[i]=stk[top];
			mat[stk[top]]=i;
			top--;
		}
	}
	memset(dp,-1,sizeof(dp));
	printf("%d\n",go(1,n,0,0));
	return 0;
}