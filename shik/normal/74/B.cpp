// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 99999
#define T 210
#define N 60
using namespace std;
int n,m;
char s[T];
int dp[T][N],q_pos[T];
bool valid( int x ) { return x>=1 && x<=n; }
int go( int t, int p ) {
	if ( dp[t][p]!=-1 ) return dp[t][p];
	int q=q_pos[t];
	if ( p==q ) return dp[t][p]=t;
	if ( t==m ) return dp[t][p]=INF;
	int r=0;
	if ( s[t]=='0' ) {
		if ( valid(p-1) && p-1!=q ) r=max(r,go(t+1,p-1));
		if ( valid( p ) &&  p !=q ) r=max(r,go(t+1, p ));
		if ( valid(p+1) && p+1!=q ) r=max(r,go(t+1,p+1));
	} else if ( s[t]=='1' ) {
		for ( int i=1; i<=n; i++ ) r=max(r,go(t+1,i));
	} else puts("QQ");
	return dp[t][p]=r;
}
int main()
{
	int a,b,dir; char tmt[100];
	scanf("%d%d%d %*s %s %s",&n,&a,&b,tmt,s+1);
	if ( strcmp(tmt,"head")==0 ) dir=-1;
	else if ( strcmp(tmt,"tail")==0 ) dir=1;
	else puts("QQ");
	m=strlen(s+1);
	q_pos[1]=b;
	for ( int i=1; i<m; i++ ) {
		if ( q_pos[i]+dir==0 || q_pos[i]+dir>n ) dir*=-1;
		q_pos[i+1]=q_pos[i]+dir;
	}
	memset(dp,-1,sizeof(dp));
	if ( go(1,a)==INF ) puts("Stowaway");
	else printf("Controller %d\n",go(1,a)-1);
	return 0;
}