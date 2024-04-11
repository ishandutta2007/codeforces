// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int ea[N],eb[N];
vector<int> e[N];
int dep[N],fa[N][17];
void go( int p, int f, int lv ) {
	dep[p]=lv;
	fa[p][0]=f;
	for ( int i=1; i<17; i++ ) fa[p][i]=fa[fa[p][i-1]][i-1];
	FOR(it,e[p]) if ( *it!=f ) go(*it,p,lv+1);
}
inline int bit( int x, int i ) { return (x>>i)&1; }
int lca( int a, int b ) {
	if ( dep[a]>dep[b] ) swap(a,b);
	for ( int i=16; i>=0; i-- ) if ( bit(dep[b]-dep[a],i) ) b=fa[b][i];
	if ( a==b ) return a;
	for ( int i=16; i>=0; i-- ) if ( fa[a][i]!=fa[b][i] ) {
		a=fa[a][i];
		b=fa[b][i];
	}
	return fa[a][0];
}
int val[N];
int la( int p, int f ) {
	FOR(it,e[p]) if ( *it!=f ) val[p]+=la(*it,p);
	return val[p];
}
int main()
{
	int n,m,a,b;
	scanf("%d",&n);
	for ( int i=1; i<n; i++ ) scanf("%d%d",ea+i,eb+i);
	for ( int i=1; i<n; i++ ) {
		e[ea[i]].push_back(eb[i]);
		e[eb[i]].push_back(ea[i]);
	}
	go(1,0,0);
	scanf("%d",&m);
	while ( m-- ) {
		scanf("%d%d",&a,&b);
		int c=lca(a,b);
		val[a]++;
		val[b]++;
		val[c]-=2;
	}
	la(1,0);
	for ( int i=1; i<n; i++ ) if ( dep[ea[i]]>dep[eb[i]] ) swap(ea[i],eb[i]);
	for ( int i=1; i<n; i++ ) printf("%d%c",val[eb[i]],i==n-1?'\n':' ');
	return 0;
}