// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 1010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef vector<int> VI;
int get( VI &a, VI &b, VI &c ) {
	int ans=0;
	for ( int i=1; i<SZ(b); i++ ) {
		int l=lower_bound(a.begin(),a.end(),b[i])-lower_bound(a.begin(),a.end(),b[i-1]);
		int r=lower_bound(c.begin(),c.end(),b[i])-lower_bound(c.begin(),c.end(),b[i-1]);
		if ( l!=r ) ans++;
	}
	return ans;
}
int main()
{
	int n,m,x;
	VI b[N];
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) {
		scanf("%d",&m);
		while ( m-- ) {
			scanf("%d",&x);
			b[i].push_back(x);
		}
		sort(b[i].begin(),b[i].end());
	}
	b[0]=b[n]; b[n+1]=b[1];
	int ans=0;
	for ( int i=1; i<=n; i++ ) ans+=get(b[i-1],b[i],b[i+1]);
	printf("%d\n",ans);
	return 0;
}