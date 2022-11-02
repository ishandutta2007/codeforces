// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int x[N],v1[N],v2[N];
vector<int> e[N],f[N];
int main()
{
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	for ( int i=1; i<=n; i++ ) scanf("%d",x+i);
	while ( m-- ) {
		scanf("%d%d",&a,&b);
		e[a].push_back(b);
		f[b].push_back(a);
	}
	queue<int> q;
	for ( int i=1; i<=n; i++ ) if ( x[i]==1 ) v1[i]=1,q.push(i);
	while ( !q.empty() ) {
		int p=q.front(); q.pop();
		FOR(it,e[p]) if ( !v1[*it] ) {
			v1[*it]=1;
			q.push(*it);
		}
	}
	for ( int i=1; i<=n; i++ ) if ( x[i]==2 ) v2[i]=1,q.push(i);
	while ( !q.empty() ) {
		int p=q.front(); q.pop();
		FOR(it,f[p]) if ( !v2[*it] ) {
			v2[*it]=1;
			if ( x[*it]!=1 ) q.push(*it);
		}
	}
	for ( int i=1; i<=n; i++ ) printf("%d\n",v1[i]&v2[i]);
	return 0;
}