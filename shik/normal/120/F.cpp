// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
vector<int> e[110];
int big,t;
void go( int p, int f=-1, int lv=0 ) {
	if ( lv>big ) {
		big=lv;
		t=p;
	}
	FOR(it,e[p]) if ( *it!=f ) go(*it,p,lv+1);
}
int get() {
	int n,a,b;
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) e[i].clear();
	for ( int i=1; i<n; i++ ) {
		scanf("%d%d",&a,&b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	big=-1; go(1);
	big=-1; go(t);
	return big;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,ans=0;
	scanf("%d",&n);
	while ( n-- ) ans+=get();
	printf("%d\n",ans);
	return 0;
}