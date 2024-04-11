// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 80000
#define MOD 777777777
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
int w[3][3];
struct Seg {
	int c[4*N][3][3];
	void pull( int id ) {
		for ( int i=0; i<3; i++ ) for ( int j=0; j<3; j++ ) {
			LL s=0;
			for ( int k=0; k<3; k++ ) for ( int l=0; l<3; l++ ) s+=1LL*c[id*2][i][k]*w[k][l]*c[id*2+1][l][j];
			c[id][i][j]=s%MOD;
		}
	}
	void init( int id, int l, int r ) {
		memset(c[id],0,sizeof(c[id]));
		if ( l==r ) {
			for ( int i=0; i<3; i++ ) c[id][i][i]=1;
			return;
		}
		int m=(l+r)/2;
		init(id*2,l,m);
		init(id*2+1,m+1,r);
		pull(id);
	}
	void chg( int id, int l, int r, int p, int v ) {
		if ( l==r ) {
			memset(c[id],0,sizeof(c[id]));
			if ( v==0 ) for ( int i=0; i<3; i++ ) c[id][i][i]=1;
			else c[id][v-1][v-1]=1;
			return;
		}
		int m=(l+r)/2;
		if ( p<=m ) chg(id*2,l,m,p,v);
		else chg(id*2+1,m+1,r,p,v);
		pull(id);
	}
} seg;
int main()
{
	int n,m,p,v;
	scanf("%d%d",&n,&m);
	for ( int i=0; i<3; i++ ) for ( int j=0; j<3; j++ ) scanf("%d",w[i]+j);
	seg.init(1,1,n);
	while ( m-- ) {
		scanf("%d%d",&p,&v);
		seg.chg(1,1,n,p,v);
		LL ans=0;
		for ( int i=0; i<3; i++ ) for ( int j=0; j<3; j++ ) ans+=seg.c[1][i][j];
		printf("%d\n",(int)(ans%MOD));
	}
	return 0;
}