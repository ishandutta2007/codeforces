// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#define N 100010
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int a[N];
map<int,int> app;
set<int> heap;
int main()
{
	int n,l;
	scanf("%d%d",&n,&l);
	for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
	for ( int i=1; i<=n; i++ ) {
		heap.insert(-a[i]);
		if ( ++app[a[i]]>1 ) heap.erase(-a[i]);
		if ( i<l ) continue;
		if ( heap.empty() ) puts("Nothing");
		else printf("%d\n",-*heap.begin());
		int t=--app[a[i-l+1]];
		if ( t==0 ) heap.erase(-a[i-l+1]);
		else if ( t==1 ) heap.insert(-a[i-l+1]);
	}
	return 0;
}