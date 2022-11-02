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
vector<int> e[N];
int a[N],b[N];
int main()
{
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	while ( m-- ) {
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
	queue<int> q;
	vector<int> sol;
	for ( int i=1; i<=n; i++ ) if ( a[i]==b[i] ) q.push(i);
	while ( !q.empty() ) {
		int p=q.front(); q.pop();
		if ( a[p]!=b[p] ) continue;
		sol.push_back(p);
		FOR(it,e[p]) if ( ++b[*it]==a[*it] ) q.push(*it);
	}
	printf("%d\n",SZ(sol));
	for ( int i=0; i<SZ(sol); i++ ) printf("%d%c",sol[i],i==SZ(sol)-1?'\n':' ');
	return 0;
}