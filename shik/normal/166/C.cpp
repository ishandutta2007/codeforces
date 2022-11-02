// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,x,a[10010];
	scanf("%d%d",&n,&x);
	for ( int i=0; i<n; i++ ) scanf("%d",a+i);
	sort(a,a+n);
	int ans=0;
	while ( a[(n-1)/2]!=x ) {
		a[n++]=x;
		sort(a,a+n);
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}