// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int x1,x2,a,b;
	scanf("%d%d%d%d",&x1,&x2,&a,&b);
	if ( x1+a<=x2 && x2<=x1+b ) { printf("FIRST\n%d\n",x2); return 0; }
	if ( a<=0 && 0<=b ) { puts("DRAW"); return 0; }
	if ( x1<x2 && b<0 ) { puts("DRAW"); return 0; }
	if ( x1>x2 && a>0 ) { puts("DRAW"); return 0; }
	int d=abs(x1-x2),e=abs(a+b),f=min(abs(a),abs(b)),g=max(abs(a),abs(b));
	if ( d%e==0 ) puts("SECOND");
	else if ( d%e<f || d%e>g ) puts("DRAW");
	else {
		puts("FIRST");
		if ( x1<x2 ) printf("%d\n",x1+d%e);
		else printf("%d\n",x1-d%e);
	}
	return 0;
}