// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#define N 2010
#define MOD 1000003
using namespace std;
int n,seq[N];
char inp[N],*ptr=inp;
int get() {
	if ( isdigit(*ptr) ) {
		while ( isdigit(*ptr) ) ptr++;
		return 0;
	} else if ( *ptr=='+' || *ptr=='-' ) {
		ptr++;
		return 1;
	} else if ( *ptr=='*' || *ptr=='/' ) {
		ptr++;
		return 2;
	}
	puts("QQ");
	return -1;
}
void input() {
	gets(inp);
	while ( *ptr ) seq[n++]=get();
}
bool check() {
	int p=0;
	while ( p<n && seq[p]==1 ) p++;
	if ( p<n && seq[p]==2 ) return 0;
	p++;
	while ( p<n ) {
		p++;
		while ( p<n && seq[p]==1 ) p++;
		if ( p<n && seq[p]==2 ) return 0;
		p++;
	}
	return 1;
}
int dp[N][N];
int go( int p, int r ) {
	if ( r<0 ) return 0;
	if ( dp[p][r]!=-1 ) return dp[p][r];
	if ( p==n ) return dp[p][r]=(r==0);
	if ( seq[p]==0 ) return dp[p][r]=(go(p+1,r)+go(p,r-1))%MOD;
	else return dp[p][r]=go(p+1,r+1);
}
void solve() {
	memset(dp,-1,sizeof(dp));
	if ( !check() ) { puts("0"); return; }
	int ans=go(0,0);
	printf("%d\n",ans);
}
int main()
{
	input();
	solve();
	return 0;
}