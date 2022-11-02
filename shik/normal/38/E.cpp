// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 3010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
struct P {
	int x,c;
	void read() { scanf("%d%d",&x,&c); }
} p[N];
bool cp( P a, P b ) { return a.x<b.x; }
LL dp[N];
int main()
{
	int n;
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) p[i].read();
	sort(p+1,p+n+1,cp);
	for ( int i=1; i<=n; i++ ) {
		dp[i]=p[i].c+dp[i-1];
		LL w=0;
		for ( int j=i-1; j>=1; j-- ) {
			w+=1LL*(i-j)*(p[j+1].x-p[j].x);
			dp[i]=min(dp[i],dp[j-1]+p[j].c+w);
		}
	}
	printf("%I64d\n",dp[n]);
	return 0;
}