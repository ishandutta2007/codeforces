// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
using namespace std;
int fa[N],sz[N];
int Find( int x ) { return x==fa[x]?x:fa[x]=Find(fa[x]); }
void Union( int a, int b ) {
	a=Find(a); b=Find(b);
	if ( sz[a]>sz[b] ) swap(a,b);
	fa[a]=b;
	sz[b]+=sz[a];
	sz[a]=0;
}
bool lucky( int x ) {
	while ( x ) {
		if ( x%10!=4 && x%10!=7 ) return 0;
		x/=10;
	}
	return 1;
}
int main()
{
	int n,a,b,c,all=0;
	long long ans=0;
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) sz[fa[i]=i]=1;
	for ( int i=1; i<n; i++ ) {
		scanf("%d%d%d",&a,&b,&c);
		if ( !lucky(c) ) Union(a,b);
	}
	for ( int i=1; i<=n; i++ ) all+=sz[i];
	for ( int i=1; i<=n; i++ ) ans+=(long long)sz[i]*(all-sz[i])*(all-sz[i]-1);
	printf("%I64d\n",ans);
	return 0;
}