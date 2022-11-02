// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 2010
#define MOD 1000000007
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int fa[N];
int Find( int x ) { return x==fa[x]?x:fa[x]=Find(fa[x]); }
void Union( int a, int b ) { fa[Find(a)]=Find(b); }
int main()
{
	int n,m,k,ans=1;
	scanf("%d%d%d",&n,&m,&k);
	for ( int i=1; i<=n; i++ ) fa[i]=i;
	for ( int i=1; i+k-1<=n; i++ ) for ( int j=0; j<k; j++ ) Union(i+j,i+k-j-1);
	for ( int i=1; i<=n; i++ ) if ( Find(i)==i ) ans=1LL*ans*m%MOD;
	printf("%d\n",ans);
	return 0;
}