// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 514514514
using namespace std;
int main()
{
	int n,x,a,b,l=-INF,r=INF;
	scanf("%d%d",&n,&x);
	while ( n-- ) {
		scanf("%d%d",&a,&b);
		if ( a>b ) swap(a,b);
		l=max(l,a);
		r=min(r,b);
	}
	if ( l>r ) puts("-1");
	else if ( l<=x && x<=r ) puts("0");
	else printf("%d\n",min(abs(l-x),abs(r-x)));
	return 0;
}