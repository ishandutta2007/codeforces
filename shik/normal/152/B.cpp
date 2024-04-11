// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
int main()
{
	int n,m,x,y,k,vx,vy;
	LL ans=0;
	scanf("%d%d%d%d%d",&n,&m,&x,&y,&k);
	for ( int i=0; i<k; i++ ) {
		scanf("%d%d",&vx,&vy);
		LL L=0,R=max(n,m);
		while ( L!=R ) {
			LL M=(L+R+1)/2,nx=x+M*vx,ny=y+M*vy;
			if ( nx<1 || nx>n || ny<1 || ny>m ) R=M-1;
			else L=M;
		}
		ans+=L;
		x+=L*vx;
		y+=L*vy;
	}
	printf("%I64d\n",ans);
	return 0;
}