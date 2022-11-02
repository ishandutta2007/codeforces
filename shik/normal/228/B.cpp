// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 55
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n1,m1,n2,m2,a[N][N],b[N][N];
int main()
{
	scanf("%d%d",&n1,&m1);
	for ( int i=1; i<=n1; i++ ) for ( int j=1; j<=m1; j++ ) scanf("%1d",a[i]+j);
	scanf("%d%d",&n2,&m2);
	for ( int i=1; i<=n2; i++ ) for ( int j=1; j<=m2; j++ ) scanf("%1d",b[i]+j);
	int ans=-1,ax=514,ay=514;
	for ( int x=-N; x<=N; x++ ) for ( int y=-N; y<=N; y++ ) {
		int s=0;
		for ( int i=1; i<=n1; i++ ) for ( int j=1; j<=m1; j++ ) {
			int p=i+x,q=j+y;
			if ( 1<=p && p<=n2 && 1<=q && q<=m2 ) s+=a[i][j]*b[p][q];
		}
		if ( s>ans ) ans=s,ax=x,ay=y;
	}
	printf("%d %d\n",ax,ay);
	return 0;
}