// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define N 110
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
long double c[N],dp[N];
int n,d[N],e[N][N],s,v[N];
long double go( int p ) {
	if ( v[p] ) return dp[p];
	v[p]=1;
	if ( p==n ) return dp[p]=0;
	long double r=0,t=0;
	for ( int i=1; i<=n; i++ ) if ( e[p][i] && d[p]-1==d[i] ) {
		t+=c[i];
		r+=c[i]*(go(i)+(p==s||i==s));
	}
	return dp[p]=r/t;
}
int main()
{
	int m,a,b;
	scanf("%d%d",&n,&m);
	while ( m-- ) {
		scanf("%d%d",&a,&b);
		e[a][b]=e[b][a]=1;
	}
	memset(d,-1,sizeof(d));
	queue<int> q;
	q.push(n); d[n]=0; c[n]=1;
	while ( !q.empty() ) {
		int p=q.front(); q.pop();
		for ( int i=1; i<=n; i++ ) if ( e[p][i] && (d[i]==-1 || d[i]==d[p]+1) ) {
			if ( d[i]==-1 ) q.push(i);
			d[i]=d[p]+1;
			c[i]+=c[p];
		}
	}
	long double ans=0;
	for ( int i=1; i<=n; i++ ) {
		s=i; memset(v,0,sizeof(v));
		ans=max(ans,go(1));
	}
	printf("%.9f\n",(double)ans);
	return 0;
}