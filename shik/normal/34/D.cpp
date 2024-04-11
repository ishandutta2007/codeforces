// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define N 50010
using namespace std;
vector<int> e[N];
int ans[N];
void go( int p, int f ) {
	ans[p]=f;
	FOR(it,e[p]) if ( *it!=f ) go(*it,p);
}
int main()
{
	int n,r1,r2,x;
	scanf("%d%d%d",&n,&r1,&r2);
	for ( int i=1; i<=n; i++ ) {
		if ( i==r1 ) continue;
		scanf("%d",&x);
		e[x].push_back(i);
		e[i].push_back(x);
	}
	go(r2,-1);
	for ( int i=1; i<=n; i++ ) if ( i!=r2 ) printf("%d%c",ans[i],(i==n||(i==n-1&&r2==n))?'\n':' ');
	return 0;
}