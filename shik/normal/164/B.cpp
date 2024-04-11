// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 2000010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,m,a[N],b[N],c[N];
int get( int p, int x ) {
	while ( x<=p ) x+=m;
	return x;
}
int main()
{
	int ans=0;
	scanf("%d%d",&n,&m);
	for ( int i=0; i<n; i++ ) scanf("%d",a+i);
	for ( int i=0; i<n; i++ ) a[i+n]=a[i];
	for ( int i=0; i<m; i++ ) scanf("%d",b+i);
	memset(c,-1,sizeof(c));
	for ( int i=0; i<m; i++ ) c[b[i]]=i;
	int l=-1,r=-1;
	for ( int i=0,j=-1; i<n; i++ ) {
		if ( c[a[i]]==-1 ) continue;
		l=get(l,c[a[i]]);
		if ( j<i ) j=i,r=l;
		while ( j-i+1<n && c[a[j+1]]!=-1 && get(r,c[a[j+1]])-l+1<=m ) r=get(r,c[a[++j]]);
		while ( l>=m ) l-=m,r-=m;
		ans=max(ans,j-i+1);
	}
	printf("%d\n",ans);
	return 0;
}