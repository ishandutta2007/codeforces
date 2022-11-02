// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 110
using namespace std;
struct DJS {
	int fa[N];
	void init( int n ) { for ( int i=1; i<=n; i++ ) fa[i]=i; }
	int Find( int x ) { return x==fa[x]?x:fa[x]=Find(fa[x]); }
	void Union( int a, int b ) { fa[Find(a)]=Find(b); }
} djs;
int main()
{
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	djs.init(n);
	if ( n!=m ) {
		puts("NO");
		return 0;
	}
	while ( m-- ) {
		scanf("%d%d",&a,&b);
		djs.Union(a,b);
	}
	for ( int i=1; i<=n; i++ )
		if ( djs.Find(i)!=djs.Find(1) ) {
			puts("NO");
			return 0;
		}
	puts("FHTAGN!");
	return 0;
}