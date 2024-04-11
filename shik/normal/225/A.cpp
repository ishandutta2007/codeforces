// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	const int t[7]={0,1,2,3,3,2,1};
	int n,x,a,b;
	scanf("%d%d",&n,&x);
	for ( int i=0; i<n; i++ ) {
		scanf("%d%d",&a,&b);
		if ( t[x]==t[a] || t[x]==t[b] ) return puts("NO"),0;
	}
	puts("YES");
	return 0;
}