// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define N 3010
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
vector<int> e[N];
int vis[N],fa[N],dp[N];
void get( int p, int q ) {
	static int v=0;
	if ( v ) return;
	v=1;
	dp[q]=0;
	for ( int i=p; i!=q; i=fa[i] ) dp[i]=0;
}
void go( int p, int f ) {
	vis[p]=1; fa[p]=f; 
	FOR(it,e[p]) if ( *it!=f ) {
		if ( !vis[*it] ) go(*it,p);
		else get(p,*it);
	}
}
int main()
{
	int n,x,y;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) {
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	memset(dp,-1,sizeof(dp));
	go(1,0);
	queue<int> q;
	for ( int i=1; i<=n; i++ ) if ( dp[i]==0 ) q.push(i);
	while ( !q.empty() ) {
		int p=q.front(); q.pop();
		FOR(it,e[p]) if ( dp[*it]==-1 ) { dp[*it]=dp[p]+1; q.push(*it); }
	}
	for ( int i=1; i<=n; i++ ) printf("%d%c",dp[i],i==n?'\n':' ');
	return 0;
}