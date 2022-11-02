// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
struct P {
	LL x,y;
	P(){}
	P( LL _x, LL _y ):x(_x),y(_y){}
	void read() { scanf("%I64d%I64d",&x,&y); }
} p[N],q;
P operator -( P a, P b ) { return P(a.x-b.x,a.y-b.y); }
LL operator *( P a, P b ) { return a.x*b.y-a.y*b.x; }
LL X( P o, P a, P b ) { return (a-o)*(b-o); }
bool operator <( P a, P b ) { return a.x!=b.x?a.x<b.x:a.y<b.y; }
int main()
{
	int n,m;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) p[i].read();
	int w=min_element(p,p+n)-p;
	rotate(p,p+w,p+n);
	scanf("%d",&m);
	while ( m-- ) {
		q.read();
		int L=1,R=n-1;
		if ( X(p[0],p[1],q)>=0 ) return puts("NO"),0;
		if ( X(p[0],p[n-1],q)<=0 ) return puts("NO"),0;
		while ( L!=R ) {
			int M=(L+R)/2;
			if ( X(p[0],p[M],q)>=0 ) R=M;
			else L=M+1;
		}
		if ( X(p[L],p[L-1],q)<=0 ) return puts("NO"),0;
	}
	puts("YES");
	return 0;
}