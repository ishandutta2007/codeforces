// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 5010
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int rk[N],fa[N],cap[N],srt[N],ans[N],pos[N],cnt[N];
bool cp( int a, int b ) { return rk[a]<rk[b]; }
vector<pair<int,int> > e[N];
void go( int p, int f, int c ) {
	fa[p]=f; cap[p]=c;
	FOR(it,e[p]) if ( it->first!=f ) go(it->first,p,it->second);
}
int main()
{
	int n,a,b,c;
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) scanf("%d",rk+i);
	for ( int i=1; i<n; i++ ) {
		scanf("%d%d%d",&a,&b,&c);
		e[a].push_back(make_pair(b,c));
		e[b].push_back(make_pair(a,c));
	}
	go(1,0,0);
	for ( int i=1; i<=n; i++ ) srt[i]=i;
	sort(srt+1,srt+n+1,cp);
	int rem=n,now=0;
	for ( int i=1; i<=n; i++ ) pos[i]=i;
	memset(ans,-1,sizeof(ans)); ans[1]=0;
	while ( rem>0 ) {
		now++;
		memset(cnt,0,sizeof(cnt));
		for ( int ii=1; ii<=n; ii++ ) {
			int i=srt[ii];
			if ( pos[i]==1 || cnt[pos[i]]==cap[pos[i]] ) continue;
			cnt[pos[i]]++;
			pos[i]=fa[pos[i]];
		}
		rem=0;
		for ( int i=1; i<=n; i++ )
			if ( pos[i]!=1 ) rem++;
			else if ( ans[i]==-1 ) ans[i]=now;
	}
	for ( int i=1; i<=n; i++ ) printf("%d%c",ans[i],i==n?'\n':' ');
	return 0;
}