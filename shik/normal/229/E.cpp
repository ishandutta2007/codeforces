// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long double Double;
Double C[N][N];
int n,m,sz[N],pri[N][N],all[N],na,x[N],y[N],sx[N],sy[N];
Double dp[N][N];
bool vis[N][N];
Double go( int p, int q ) {
	Double &r=dp[p][q];
	if ( vis[p][q] ) return r;
	vis[p][q]=1;
	if ( p==m && q==0 ) return r=1;
	int y1=q-sx[p],y2=sy[p];
	r=0;
	if ( y1>y2 ) return r;
	for ( int i=0; i<=y[p] && i<=y1; i++ ) {
		Double p1=C[y[p]][i]*C[y2-y[p]][y1-i]/C[y2][y1];
		Double p2=C[x[p]+y[p]][x[p]+i]/C[sz[p]][x[p]+i];
		Double p3=C[y[p]][i]/C[x[p]+y[p]][x[p]+i];
		r+=p1*p2*p3*go(p+1,q-x[p]-i);
	}
	return r;
}
int main()
{
	for ( int i=0; i<N; i++ ) for ( int j=C[i][0]=1; j<=i; j++ ) C[i][j]=C[i-1][j-1]+C[i-1][j];
	scanf("%d%d",&n,&m);
	for ( int i=0; i<m; i++ ) {
		scanf("%d",sz+i);
		for ( int j=0; j<sz[i]; j++ ) scanf("%d",pri[i]+j);
	}
	for ( int i=0; i<m; i++ ) for ( int j=0; j<sz[i]; j++ ) all[na++]=pri[i][j];
	sort(all,all+na);
	int gap=all[na-n];
	for ( int i=0; i<m; i++ ) for ( int j=0; j<sz[i]; j++ ) {
		if ( pri[i][j]>gap ) x[i]++;
		else if ( pri[i][j]==gap ) y[i]++;
	}
	for ( int i=m-1; i>=0; i-- ) sx[i]=sx[i+1]+x[i];
	for ( int i=m-1; i>=0; i-- ) sy[i]=sy[i+1]+y[i];
	double ans=go(0,n);
	printf("%.12f\n",ans);
	return 0;
}