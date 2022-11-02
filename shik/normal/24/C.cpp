// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int x[N],y[N];
int main()
{
	int n,sx,sy; long long m;
	scanf("%d%I64d%d%d",&n,&m,&sx,&sy);
	for ( int i=0; i<n; i++ ) scanf("%d%d",x+i,y+i);
	m%=2*n;
	for ( int i=0; i<m; i++ ) {
		sx=2*x[i%n]-sx;
		sy=2*y[i%n]-sy;
	}
	printf("%d %d\n",sx,sy);
	return 0;
}