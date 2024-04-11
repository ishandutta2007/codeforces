// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 55
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
inline bool chkmax( LL &a, LL b ) {
	if ( b>a ) return a=b,1;
	else return 0;
}
struct P {
	LL a,b; int id,c;
	void read( int _id ) { id=_id; scanf("%I64d%I64d%d",&a,&b,&c); }
} p[N];
int d;
bool cp( P a, P b ) { return a.c<b.c; }
LL dp[N][N][110];
int p1[N][N][110],p2[N][N][110];
void trace( int a, int b, int c ) {
	if ( b==0 ) return;
	trace(p1[a][b][c],b-1,p2[a][b][c]);
	printf("%d %I64d\n",p[a].id,p[a].a+c);
}
int main()
{
	int n,m,x=0,y=0;
	LL ans=-1;
	scanf("%d%d%d",&n,&m,&d);
	for ( int i=0; i<m; i++ ) p[i].read(i+1);
	sort(p,p+m,cp);
	for ( int i=0; i<m; i++ ) for ( int j=1; j<=n; j++ ) for ( int k=0; k<=p[i].b-p[i].a; k++ ) {
		if ( j==1 ) {
			dp[i][j][k]=p[i].a+k;
			continue;
		}
		dp[i][j][k]=-(1LL<<60);
		LL t1=p[i].a+k-d,t2=(p[i].a+k)%d==0?(p[i].a+k)/d:-1;
		for ( int l=0; l<i&&p[l].c<p[i].c; l++ ) {
			if ( p[l].a<=t1 && t1<=p[l].b && chkmax(dp[i][j][k],dp[l][j-1][t1-p[l].a]+p[i].a+k) ) p1[i][j][k]=l,p2[i][j][k]=t1-p[l].a;
			if ( p[l].a<=t2 && t2<=p[l].b && chkmax(dp[i][j][k],dp[l][j-1][t2-p[l].a]+p[i].a+k) ) p1[i][j][k]=l,p2[i][j][k]=t2-p[l].a;
		}
	}
	for ( int i=0; i<m; i++ ) for ( int j=0; j<=p[i].b-p[i].a; j++ ) if ( chkmax(ans,dp[i][n][j]) ) x=i,y=j;
	if ( ans<0 ) puts("NO");
	else {
		puts("YES");
		trace(x,n,y);
	}
	return 0;
}