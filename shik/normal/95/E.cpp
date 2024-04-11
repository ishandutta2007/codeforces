// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define N 100010
#define INF 999999
using namespace std;
int fa[N],rk[N],cnt[N],tmt[N];
int Find( int x ) { return x==fa[x]?x:fa[x]=Find(fa[x]); }
void Union( int a, int b ) {
	if ( rk[a]<rk[b] ) swap(a,b);
	else if ( rk[a]==rk[b] ) rk[a]++;
	fa[Find(b)]=Find(a);
}
int dp[N],lst[N],nl;
void gen_lst() {
	queue<int> q;
	q.push(0);
	while ( !q.empty() ) {
		int p=q.front(); q.pop();
		if ( p>N ) continue;
		if ( p>0 ) lst[nl++]=p;
		q.push(p*10+4);
		q.push(p*10+7);
	}
}
int main()
{
	gen_lst();
	int n,m,i,a,b,j,top=0,ans=INF;
	scanf("%d%d",&n,&m);
	for ( i=0; i<nl; i++ )
		if ( lst[i]<=n ) top=lst[i];
	//printf("top = %d\n",top);
	for ( i=1; i<=n; i++ ) fa[i]=i;
	while ( m-- ) {
		scanf("%d%d",&a,&b);
		Union(a,b);
	}
	for ( i=1; i<=n; i++ ) cnt[Find(i)]++;
	for ( i=1; i<=n; i++ ) tmt[cnt[i]]++;
	for ( i=1; i<=top; i++ ) dp[i]=INF;
	for ( i=1; i<=n; i++ ) {
		if ( tmt[i]==0 ) continue;
		//printf("==%d,%d\n",i,tmt[i]);
		int t=1,c=tmt[i],v;
		while ( c>=t ) {
			c-=t;
			v=t*i;
			for ( j=top; j>=v; j-- )
				if ( dp[j-v]+t < dp[j] ) dp[j]=dp[j-v]+t;
			t*=2;
		}
		if ( c==0 ) continue;
		v=c*i;
		for ( j=top; j>=v; j-- )
			if ( dp[j-v]+c < dp[j] ) dp[j]=dp[j-v]+c;
	}
	for ( i=0; i<nl&&lst[i]<=top; i++ ) ans=min(ans,dp[lst[i]]);
	//for ( i=0; i<nl&&lst[i]<=top; i++ ) printf("%d: %d,%d\n",i,lst[i],dp[lst[i]]);
	printf("%d\n",ans==INF?-1:ans-1);
	return 0;
}