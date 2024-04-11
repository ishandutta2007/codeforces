// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
LL sqr( LL x ) { return x*x; }
struct P {
	int x,y,t;
	double p;
	void read() { scanf("%d%d%d%lf",&x,&y,&t,&p); }
} p[N];
bool cp( P a, P b ) { return a.t<b.t; }
LL dis2( P a, P b ) { return sqr(a.x-b.x)+sqr(a.y-b.y); }
double dp[N];
int main()
{
	int n;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) p[i].read();
	sort(p,p+n,cp);
	for ( int i=0; i<n; i++ ) {
		dp[i]=p[i].p;
		for ( int j=0; j<i; j++ ) if ( sqr(p[i].t-p[j].t)>=dis2(p[i],p[j]) ) dp[i]=max(dp[i],dp[j]+p[i].p);
	}
	printf("%.9f\n",*max_element(dp,dp+n));
	return 0;
}