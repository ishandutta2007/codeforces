// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 999999999
#define N 10010
#define L 110
#define M 20
using namespace std;
int m,n,l,tmt[N],len[L],w[M][M],dis[N],lst[M],dp[1<<M];
void BFS( int idx, int p ) {
	queue<int> q;
	for ( int i=0; i<=n; i++ ) dis[i]=INF;
	dis[p]=0; q.push(p);
	while ( !q.empty() ) {
		p=q.front(); q.pop();
		for ( int i=0; i<l; i++ )
			for ( int j=-1; j<=1; j+=2 ) {
				int t=p+j*len[i];
				if ( t<0 || t>n || dis[p]+1>=dis[t] ) continue;
				dis[t]=dis[p]+1;
				q.push(t);
			}
	}
	for ( int i=0; i<m; i++ ) w[idx][i]=dis[lst[i]];
}
int main()
{
	int k,i,x,y;
	scanf("%d%d%d",&n,&k,&l);
	for ( i=0; i<k; i++ ) {
		scanf("%d",&x);
		tmt[x-1]^=1;
		tmt[x]^=1;
	}
	for ( i=0; i<l; i++ ) scanf("%d",len+i); 
	for ( i=0; i<=n; i++ )
		if ( tmt[i] ) lst[m++]=i;
	for ( i=0; i<m; i++ ) BFS(i,lst[i]);
	for ( i=1; i<(1<<m); i++ ) {
		dp[i]=INF;
		for ( x=0; x<m && !((i>>x)&1); x++ );
		for ( y=x+1; y<m; y++ ) {
			if ( !((i>>y)&1) ) continue;
			dp[i]=min(dp[i],dp[i-(1<<x)-(1<<y)]+w[x][y]);
		}
	}
	if ( dp[(1<<m)-1]==INF ) puts("-1");
	else printf("%d\n",dp[(1<<m)-1]);
	return 0;
}