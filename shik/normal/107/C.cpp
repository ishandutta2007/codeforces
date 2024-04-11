// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 16
using namespace std;
typedef long long LL;
inline int bit( int x, int i ) { return (x>>i)&1; }
int n,e[N][N];
int mem[1<<N];
int valid( int sta ) {
	if ( mem[sta]!=-1 ) return mem[sta];
	for ( int i=0; i<n; i++ )
		if ( bit(sta,i) )
			for ( int j=0; j<n; j++ )
				if ( e[i][j] && bit(sta,j)==0 ) return mem[sta]=0;
	return mem[sta]=1;
}
LL dp[1<<N];
int sol[N],tmt[1<<N],ac;
LL go( int ptr, int sta ) {
	if ( sta==0 ) return 1;
	if ( tmt[sta]==ac ) return dp[sta];
	tmt[sta]=ac;
	if ( !valid(sta) ) return dp[sta]=0;
	LL r=0;
	for ( int i=0; i<n; i++ )
		if ( bit(sta,i) && (sol[i]==n || ptr==sol[i]) ) r+=go(ptr+1,sta-(1<<i));
	//printf("== %d,%d: %I64d\n",ptr,sta,r);
	return dp[sta]=r;
}
int vis[N];
bool yo( int pos, LL rem ) {
	//printf("================ %d,%I64d\n",pos,rem);
	if ( pos==n ) return 1;
	LL pre=0;
	for ( int i=0; i<n; i++ ) {
		if ( vis[i] ) continue;
		sol[pos]=i;
		ac++;
		LL now=go(0,(1<<n)-1);
		//printf("%d: now = %I64d\n",i,now);
		//if ( now<rem ) pre=now;
		if ( now<rem ) rem-=now;
		else {
			vis[i]=1;
			return yo(pos+1,rem-pre);
		}
	}
	return 0;
}
int main()
{
	memset(mem,-1,sizeof(mem));
	int m,a,b; LL y;
	scanf("%d%I64d%d",&n,&y,&m);
	while ( m-- ) {
		scanf("%d%d",&a,&b);
		e[a-1][b-1]=1;
	}
	//for ( y=2006; y<=2006; y++ ) {
	for ( int i=0; i<n; i++ ) sol[i]=n;
	memset(vis,0,sizeof(vis));
	if ( yo(0,y-2000) ) {
		for ( int i=0; i<n; i++ ) printf("%d%c",sol[i]+1,i==n-1?'\n':' ');
	} else {
		puts("The times have changed");
	}
	//}
	return 0;
}