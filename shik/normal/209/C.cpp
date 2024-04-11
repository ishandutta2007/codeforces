// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 1000010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n;
vector<int> e[N];
bool input() {
	int m,a,b;
	if ( scanf("%d%d",&n,&m)==EOF ) return 0;
	for ( int i=1; i<=n; i++ ) e[i].clear();
	while ( m-- ) {
		scanf("%d%d",&a,&b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	return 1;
}
bool vis[N];
bool BFS( int p ) {
	static int q[N],fr,bk;
	bool ret=1;
	fr=bk=0; q[bk++]=p; vis[p]=1;
	while ( fr!=bk ) {
		p=q[fr++];
		ret&=SZ(e[p])%2==0;
		FOR(it,e[p]) if ( !vis[*it] ) {
			vis[*it]=1;
			q[bk++]=*it;
		}
	}
	return ret;
}
int con,odd,ec;
void solve() {
	con=odd=ec=0;
	memset(vis+1,n,0);
	for ( int i=1; i<=n; i++ ) if ( !vis[i] && (i==1||SZ(e[i])>0) ) {
		con++;
		ec+=BFS(i);
	}
	for ( int i=1; i<=n; i++ ) if ( SZ(e[i])%2==1 ) odd++;
	int ans=0;
	if ( ec==con && con>1 ) con--,ec-=2,odd+=2,ans++;
	if ( con>1 ) con-=ec,ans+=ec;
	ans+=max(con-1,odd/2);
	printf("%d\n",ans);
}
int main()
{
	while ( input() ) {
		solve();
	}
	return 0;
}
// dont care about isolated vertex
// add minimum number of edges such that euler circuit exists
// we want to reduce the number of components and odd degree vertice, call C and O
// -1,-2
// -0,-2
// -1,-0
// -1,+2, only appear in O == 0