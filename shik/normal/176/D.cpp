// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 2010
#define L 1000010
#define INF 514514514
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
using namespace std;
typedef pair<int,int> PII;
inline void chkmin( PII &a, PII b ) { if ( b<a ) a=b; }
char buf[L+N],*b[N],s[N];
int hav[N][26],len[N],x[N],st[N],ed[N],bel[N+L];
int nx1[N][26],nx2[L+N][26],last[26];
PII dp[N][N];
int main()
{
	int n,m;
	scanf("%d",&n);
	b[0]=buf;
	for ( int i=1; i<=n; i++ ) {
		b[i]=b[i-1]+len[i-1]+1;
		scanf("%s",b[i]);
		len[i]=strlen(b[i]);
	}
	for ( int i=0; i<=n; i++ ) {
		st[i]=b[i]-buf;
		ed[i]=st[i]+len[i];
		for ( int j=st[i]; j<=ed[i]; j++ ) bel[j]=i;
		for ( int j=0; j<len[i]; j++ ) hav[i][b[i][j]-'a']=1;
	}
	scanf("%d",&m);
	for ( int i=1; i<=m; i++ ) scanf("%d",x+i);
	fill(last,last+26,m+1);
	for ( int i=m; i>=0; i-- ) {
		memcpy(nx1[i],last,sizeof(last));
		for ( int j=0; j<26; j++ ) if ( hav[x[i]][j] ) last[j]=i;
	}
	fill(last,last+26,N+L);
	for ( int i=ed[n]; i>=0; i-- ) {
		memcpy(nx2[i],last,sizeof(last));
		if ( buf[i] ) last[buf[i]-'a']=i;
	}
	scanf("%s",s);
	int l=strlen(s);
	for ( int i=0; i<N; i++ ) for ( int j=0; j<N; j++ ) dp[i][j]=MP(INF,INF);
	dp[0][0]=MP(0,0);
	for ( int i=0; i<l; i++ ) for ( int j=0; j<=i; j++ ) if ( dp[i][j].first!=INF ) {
		chkmin(dp[i+1][j],dp[i][j]);
		int p=dp[i][j].first,q=dp[i][j].second;
		int nx=nx2[st[x[p]]+q][s[i]-'a'];
		//printf("%d,%d: %d,%d, x[p]=%d, nx=%d\n",i,j,p,q,x[p],nx);
		if ( nx==N+L || bel[nx]!=x[p] ) {
			int np=nx1[p][s[i]-'a'];
			//printf("np = %d\n",np);
			if ( np>m ) continue;
			int nq=nx2[st[x[np]]-1][s[i]-'a'];
			chkmin(dp[i+1][j+1],MP(np,nq-st[x[np]]));
		} else {
			chkmin(dp[i+1][j+1],MP(p,nx-st[x[p]]));
		}
	}
	int ans=0;
	for ( int i=0; i<=l; i++ ) if ( dp[l][i].first!=INF ) ans=i;
	printf("%d\n",ans);
	return 0;
}