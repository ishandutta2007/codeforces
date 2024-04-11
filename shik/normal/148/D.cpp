// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
double dp[2][N][N];
int vis[2][N][N];
double go( int t, int w, int b ) {
	double &r=dp[t][w][b];
	if ( vis[t][w][b] ) return r;
	vis[t][w][b]=1;
	if ( w+b==0 ) return r=t;
	if ( b==0 ) return r=1;
	double p=1.0*w/(w+b);
	r=p; b--;
	if ( t==0 ) r+=(1-p)*(1-go(t^1,w,b));
	else {
		if ( w>0 ) r+=(1-p)*w/(w+b)*(1-go(t^1,w-1,b));
		if ( b>0 ) r+=(1-p)*b/(w+b)*(1-go(t^1,w,b-1));
		if ( w+b==0 ) r=1;
	}
	return r;
}
int main()
{
	int w,b;
	scanf("%d%d",&w,&b);
	printf("%.12f\n",go(0,w,b));
	return 0;
}