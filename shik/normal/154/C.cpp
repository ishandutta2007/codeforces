// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#define N 1000010
#define H 3214567
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
LL h[N],p[N]={1},s[N];
bool cp( int a, int b ) { return h[a]<h[b]; }
int main()
{
	for ( int i=1; i<N; i++ ) p[i]=p[i-1]*H;
	for ( int i=1; i<N; i++ ) s[i]=i;
	int n,m,a,b;
	LL ans=0;
	scanf("%d%d",&n,&m);
	while ( m-- ) {
		scanf("%d%d",&a,&b);
		h[a]+=p[b];
		h[b]+=p[a];
	}
	sort(s+1,s+n+1,cp);
	for ( int i=1,j=1; i<=n; i=j ) {
		while ( j<=n && h[s[i]]==h[s[j]] ) j++;
		ans+=1LL*(j-i)*(j-i-1)/2;
	}
	for ( int i=1; i<=n; i++ ) h[i]+=p[i];
	sort(s+1,s+n+1,cp);
	for ( int i=1,j=1; i<=n; i=j ) {
		while ( j<=n && h[s[i]]==h[s[j]] ) j++;
		ans+=1LL*(j-i)*(j-i-1)/2;
	}
	printf("%I64d\n",ans);
	return 0;
}