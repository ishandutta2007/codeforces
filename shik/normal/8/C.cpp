// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 24
#define INF 999999999
using namespace std;
struct P {
	int x,y;
	void read() { scanf("%d%d",&x,&y); }
} st,p[N];
inline int bit( int x, int idx ) { return (x>>idx)&1; }
inline int sqr( int x ) { return x*x; }
inline int dis( const P &a, const P &b ) { return sqr(a.x-b.x)+sqr(a.y-b.y); }
int n,dp[1<<N],vis[1<<N],fi[1<<N],fj[1<<N];
int go( int sta ) {
	if ( sta==0 ) return 0;
	if ( vis[sta] ) return dp[sta];
	vis[sta]=1;
	int r=INF,now,wi=-1,wj=-1;
	for ( int i=0; i<n; i++ ) {
		if ( bit(sta,i)==0 ) continue;
		if ( (now=(go(sta-(1<<i))+2*dis(st,p[i]))) ) {
			r=now;
			wi=i;
			wj=-1;
		}
		for ( int j=i+1; j<n; j++ )
			if ( bit(sta,j)==1 ) {
				if ( (now=go(sta-(1<<i)-(1<<j))+dis(st,p[i])+dis(p[i],p[j])+dis(p[j],st))<r ) {
					r=now;
					wi=i;
					wj=j;
				}
			}
		break;
	}
	fi[sta]=wi;
	fj[sta]=wj;
	return dp[sta]=r;
}
void trace( int sta ) {
	//printf("sta = %d\n",sta);
	if ( sta==0 ) {
		puts("0");
		return;
	}
	printf("0 %d ",fi[sta]+1);
	if ( fj[sta]!=-1 ) {
		printf("%d ",fj[sta]+1);
		trace(sta-(1<<fi[sta])-(1<<fj[sta]));
	} else trace(sta-(1<<fi[sta]));
}
int main()
{
	st.read();
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) p[i].read();
	printf("%d\n",go((1<<n)-1));
	trace((1<<n)-1);
	return 0;
}