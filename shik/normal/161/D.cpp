// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 50010
#define K 510
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
vector<int> e[N];
int n,k,fa[N],dp[N][K];
void go( int p, int f ) {
	fa[p]=f;
	dp[p][0]=1;
	FOR(it,e[p]) if ( *it!=f ) {
		go(*it,p);
		for ( int i=1; i<=k; i++ ) dp[p][i]+=dp[*it][i-1];
	}
}
long long cal( int p ) {
	long long ret=0;
	for ( int i=k; i>=0&&p; i--,p=fa[p] ) {
		ret+=dp[p][i];
		if ( fa[p] && i>=2 ) ret-=dp[p][i-2];
	}
	return ret;
}
int main()
{
	int a,b;
	long long ans=0;
	scanf("%d%d",&n,&k);
	for ( int i=1; i<n; i++ ) {
		scanf("%d%d",&a,&b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	go(1,0);
	for ( int i=1; i<=n; i++ ) ans+=cal(i);
	printf("%I64d\n",ans/2);
	return 0;
}