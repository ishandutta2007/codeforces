// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#define N 100010
#define INF (1<<30)
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
using namespace std;
typedef pair<int,int> PII;
struct E {
	int k,c;
	E(){}
	E( int _k, int _c ):k(_k),c(_c){}
};
vector<E> e[N];
priority_queue<PII> q;
set<int> s[N];
int dis[N];
int main()
{
	int n,m,a,b,c;
	scanf("%d%d",&n,&m);
	while ( m-- ) {
		scanf("%d%d%d",&a,&b,&c);
		e[a].push_back(E(b,c));
		e[b].push_back(E(a,c));
	}
	for ( int i=1; i<=n; i++ ) {
		int ns,x;
		scanf("%d",&ns);
		while ( ns-- ) {
			scanf("%d",&x);
			s[i].insert(x);
		}
	}
	for ( int i=1; i<=n; i++ ) dis[i]=INF;
	dis[1]=0; q.push(MP(0,1));
	while ( !q.empty() ) {
		int p=q.top().second;
		int t=-q.top().first;
		q.pop();
		if ( t!=dis[p] ) continue;
		while ( s[p].count(t) ) t++;
		FOR(it,e[p]) if ( t+it->c < dis[it->k] ) {
			dis[it->k]=t+it->c;
			q.push(MP(-dis[it->k],it->k));
		}
	}
	if ( dis[n]==INF ) puts("-1");
	else printf("%d\n",dis[n]);
	return 0;
}