// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 1010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
struct DJS {
	int fa[N];
	void init( int n ) { for ( int i=1; i<=n; i++ ) fa[i]=i; }
	int Find( int x ) { return x==fa[x]?x:fa[x]=Find(fa[x]); }
	void Union( int a, int b ) { fa[Find(a)]=Find(b); }
} djs;
int main()
{
	int n,a,b;
	vector<pair<int,int> > lst;
	scanf("%d",&n);
	djs.init(n);
	for ( int i=1; i<n; i++ ) {
		scanf("%d%d",&a,&b);
		if ( djs.Find(a)==djs.Find(b) ) lst.push_back(make_pair(a,b));
		else djs.Union(a,b);
	}
	printf("%d\n",SZ(lst));
	for ( int i=1; i<=n; i++ ) for ( int j=1; j<=n; j++ ) if ( djs.Find(i)!=djs.Find(j) ) {
		printf("%d %d %d %d\n",lst.back().first,lst.back().second,i,j);
		djs.Union(i,j);
		lst.pop_back();
	}
	return 0;
}