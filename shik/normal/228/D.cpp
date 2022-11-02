// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
struct BIT {
	LL dat[N];
	LL ask( int x ) {
		LL r=0;
		for ( int i=x; i; i-=i&-i ) r+=dat[i];
		return r;
	}
	LL ask( int l, int r ) {
		return ask(r)-ask(l-1);
	}
	void add( int x, int v ) {
		for ( int i=x; i<N; i+=i&-i ) dat[i]+=v;
	}
} bit[5][10];
int a[N];
int main()
{
	int n;
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
	for ( int i=0; i<5; i++ ) for ( int j=0; j<2*(i+1); j++ ) for ( int k=j+1; k<=n; k+=2*(i+1) ) bit[i][j].add(k,a[k]);
	int m,op,p,v,l,r,z;
	scanf("%d",&m);
	while ( m-- ) {
		scanf("%d",&op);
		if ( op==1 ) {
			scanf("%d%d",&p,&v);
			int d=v-a[p];
			a[p]=v;
			for ( int i=0; i<5; i++ ) {
				int j=(p-1)%(2*(i+1));
				bit[i][j].add(p,d);
			}
		} else if ( op==2 ) {
			scanf("%d%d%d",&l,&r,&z);
			LL ans=0;
			for ( int i=1; i<=2*(z-1) && l+i-1<=r; i++ ) {
				int s,t=i%(2*(z-1));
				if ( t==0 ) s=2;
				else if ( t<=z ) s=t;
				else s=2*z-t;
				ans+=s*bit[z-2][(l+i-2)%(2*(z-1))].ask(l,r);
			}
			printf("%I64d\n",ans);
		} else puts("QQ");
	}
	return 0;
}