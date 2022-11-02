// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int vis[N],dep[N],fa[N],ans,in[N],val[N];
vector<int> e[N];
void get( int p, int q ) {
	ans++;
	while ( p!=q ) {
		in[p]=q;
		p=fa[p];
	}
	in[p]=q;
}
bool chk( int p, int q ) {
	int cnt=0;
	while ( p!=q ) {
		if ( SZ(e[p])>2 ) cnt++;
		p=fa[p];
	}
	if ( SZ(e[p])>2 ) cnt++;
	return cnt>=2;
}
void dfs( int p, int f, int lv ) {
	vis[p]=1;
	fa[p]=f;
	dep[p]=lv;
	FOR(it,e[p]) if ( !vis[*it] ) dfs(*it,p,lv+1);
	FOR(it,e[p]) if ( *it!=f && dep[*it]<dep[p] ) get(p,*it);
	int now=0;
	FOR(it,e[p]) if ( dep[*it]>dep[p] && (!in[*it] || !in[p] || in[*it]!=in[p]) ) {
		if ( val[*it]==0 ) ans++;
		now++;
	}
	ans-=now/2;
	val[p]=now%2;
	FOR(it,e[p]) if ( *it!=f && dep[*it]<dep[p] && chk(p,*it) ) ans--;
}
int main()
{
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	for ( int i=0; i<m; i++ ) {
		scanf("%d%d",&a,&b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	dfs(1,0,1);
	printf("%d %d\n",ans,m);
	return 0;
}