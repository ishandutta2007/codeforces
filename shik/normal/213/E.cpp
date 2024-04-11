// by shik
#include <cstdio>
#define N 200010
#define H 19920401
using namespace std;
int n,m,a[N],b[N],pw[N],w[N],ha,dn,ans,v[4*N],h[4*N];
void add( int id, int l, int r, int p, int d ) {
	if ( l==r ) {
		v[id]+=d;
		h[id]=b[p]*v[id];
		return;
	}
	int m=(l+r)/2;
	if ( p<=m ) add(id*2,l,m,p,d);
	else add(id*2+1,m+1,r,p,d);
	v[id]=v[id*2]+v[id*2+1];
	h[id]=h[id*2]*pw[v[id*2+1]]+h[id*2+1];
}
int main()
{
	scanf("%d%d",&n,&m);
	for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
	for ( int i=1; i<=m; i++ ) scanf("%d",b+i);
	for ( int i=pw[0]=1; i<=n; i++ ) pw[i]=H*pw[i-1];
	for ( int i=1; i<=n; i++ ) ha=ha*H+a[i],dn=dn*H+1;
	for ( int i=1; i<=m; i++ ) w[b[i]]=i;
	for ( int i=1; i<=m; i++ ) {
		add(1,1,m,w[i],1);
		if ( i>n ) {
			add(1,1,m,w[i-n],-1);
			ha+=dn;
		}
		if ( h[1]==ha ) ans++;
	}
	printf("%d\n",ans);
	return 0;
}