// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 55
#define M 110
#define INF 514514
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,m,dp[2][N][M],vis[2][N][M];
char s[M];
int go( int d, int p, int q ) {
	int &r=dp[d][p][q];
	if ( vis[d][p][q] ) return r;
	vis[d][p][q]=1;
	if ( q==m ) return r=(p==0?0:-INF);
	r=-INF;
	for ( int i=0; i<=p; i++ ) {
		if ( (i%2==0)^(s[q]=='F') ) r=max(r,go(d^1,p-i,q+1));
		else r=max(r,go(d,p-i,q+1)+(d==0?1:-1));
	}
	return r;
}
int main()
{
	scanf("%s%d",s,&n);
	m=strlen(s);
	printf("%d\n",max(go(0,n,0),go(1,n,0)));
	return 0;
}