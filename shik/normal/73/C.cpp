// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[110];
int val[130][130],dp[110][110][130],vis[110][110][130];
int go( int p, int k, int q ) {
	int &r=dp[p][k][q];
	if ( vis[p][k][q] ) return r;
	vis[p][k][q]=1;
	if ( s[p]==0 ) return r=0;
	r=go(p+1,k,s[p])+val[q][(int)s[p]];
	if ( k>0 ) for ( int i='a'; i<='z'; i++ ) r=max(r,go(p+1,k-1,i)+val[q][i]);
	return r;
}
int main()
{
	int k,n,c; char a,b;
	scanf("%s%d%d",s,&k,&n);
	while ( n-- ) {
		scanf(" %c %c %d",&a,&b,&c);
		val[(int)a][(int)b]=c;
	}
	printf("%d\n",go(0,k,0));
	return 0;
}