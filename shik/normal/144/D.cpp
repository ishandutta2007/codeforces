// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define N 100010
#define INF 1234567890
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
using namespace std;
typedef pair<int,int> PII;
vector<PII> e[N];
priority_queue<PII> q;
int dis[N];
int main()
{
	int n,m,s,a,b,c,l,ans=0;
	scanf("%d%d%d",&n,&m,&s);
	for ( int i=0; i<m; i++ ) {
		scanf("%d%d%d",&a,&b,&c);
		e[a].push_back(MP(b,c));
		e[b].push_back(MP(a,c));
	}
	scanf("%d",&l);
	fill(dis+1,dis+n+1,INF);
	dis[s]=0; q.push(MP(0,s));
	while ( !q.empty() ) {
		PII p=q.top(); q.pop();
		if ( -p.first!=dis[p.second] ) continue;
		FOR(it,e[p.second]) if ( -p.first+it->second<dis[it->first] ) {
			dis[it->first]=-p.first+it->second;
			q.push(MP(-dis[it->first],it->first));
		}
	}
	for ( int i=1; i<=n; i++ ) if ( dis[i]==l ) ans++;
	for ( int i=1; i<=n; i++ ) if ( dis[i]<l ) FOR(it,e[i]) if ( dis[i]+it->second>l && l-dis[i]<=it->second-(l-dis[it->first]) ) ans++;
	for ( int i=1; i<=n; i++ ) if ( dis[i]<l ) FOR(it,e[i]) if ( dis[i]+it->second>l && i<it->first && l-dis[i]+l-dis[it->first]==it->second ) ans--;
	printf("%d\n",ans);
	return 0;
}