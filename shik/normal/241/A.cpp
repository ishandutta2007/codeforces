// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,k,d[N],s[N];
	scanf("%d%d",&n,&k);
	for ( int i=1; i<=n; i++ ) scanf("%d",d+i);
	for ( int i=1; i<=n; i++ ) scanf("%d",s+i);
	int now=0,big=0,ans=0;
	for ( int i=1; i<=n; i++ ) {
		now+=s[i];
		big=max(big,s[i]);
		while ( now<d[i] ) {
			now+=big;
			ans+=k;
		}
		now-=d[i];
		ans+=d[i];
	}
	printf("%d\n",ans);
	return 0;
}