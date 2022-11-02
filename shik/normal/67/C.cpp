// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define N 4010
#define INF 999999999
using namespace std;
int ti,td,tid,tr,te,a[N],b[N],na,nb,dp[N][N],prea[N][26],preb[N][26];
int go( int pa, int pb ) {
	if ( pa==0 && pb==0 ) return 0;
	if ( pa==0 ) return ti*pb;
	if ( pb==0 ) return td*pa;
	if ( dp[pa][pb]!=-1 ) return dp[pa][pb];
	int la=a[pa],lb=b[pb];
	if ( la==lb ) return dp[pa][pb]=go(pa-1,pb-1);
	int r=min(go(pa-1,pb)+td,go(pa,pb-1)+ti);
	r=min(r,go(pa-1,pb-1)+tr);
	if ( prea[pa-1][lb]>0 ) {
		if ( preb[pb-1][la]>0 ) r=min(r,go(prea[pa-1][lb]-1,preb[pb-1][la]-1)+te+td*(pa-prea[pa-1][lb]-1)+ti*(pb-preb[pb-1][la]-1));
		else r=min(r,te+td*(pa-1)+ti*(pb-1));
	}
	return dp[pa][pb]=r;
}
int main()
{
	char sa[N],sb[N];
	scanf("%d%d%d%d %s %s",&ti,&td,&tr,&te,sa+1,sb+1);
	na=strlen(sa+1);
	nb=strlen(sb+1);
	a[0]=b[0]=-514;
	for ( int i=1; i<=na; i++ ) a[i]=sa[i]-'a';
	for ( int i=1; i<=nb; i++ ) b[i]=sb[i]-'a';
	for ( int i=1; i<=na; i++ ) {
		for ( int j=0; j<26; j++ ) prea[i][j]=prea[i-1][j];
		prea[i][a[i]]=i;
	}
	for ( int i=1; i<=nb; i++ ) {
		for ( int j=0; j<26; j++ ) preb[i][j]=preb[i-1][j];
		preb[i][b[i]]=i;
	}
	memset(dp,-1,sizeof(dp));
	printf("%d\n",go(na,nb));
	return 0;
}
// ba
// ac
// tr+tr vs te+tr
// tr vs te
// te+te>=