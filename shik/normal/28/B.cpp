// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#define N 110
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,s[N],d[N],vis[N];
set<int> s1,s2;
vector<int> e[N];
void go( int p ) {
	vis[p]=1;
	s1.insert(p);
	s2.insert(s[p]);
	FOR(it,e[p]) if ( !vis[*it] ) go(*it);
}
int main()
{
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) scanf("%d",s+i);
	for ( int i=1; i<=n; i++ ) scanf("%d",d+i);
	for ( int i=1; i<=n; i++ ) {
		if ( i+d[i]<=n ) {
			e[i].push_back(i+d[i]);
			e[i+d[i]].push_back(i);
		}
		if ( i-d[i]>=1 ) {
			e[i].push_back(i-d[i]);
			e[i-d[i]].push_back(i);
		}
	}
	for ( int i=1; i<=n; i++ ) if ( !vis[i] ) {
		s1.clear();
		s2.clear();
		go(i);
		if ( s1!=s2 ) { puts("NO"); return 0; }
	}
	puts("YES");
	return 0;
}