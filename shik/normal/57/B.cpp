// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
using namespace std;
struct R { int a,b,c; void read() { scanf("%d%d%d",&a,&b,&c); } } r[N];
int main()
{
	int n,m,k,i,p;
	long long ans=0;
	scanf("%d%d%d",&n,&m,&k);
	for ( i=0; i<m; i++ ) r[i].read();
	while ( k-- ) {
		scanf("%d",&p);
		for ( i=0; i<m; i++ )
			if ( r[i].a<=p && p<=r[i].b ) ans+=r[i].c+p-r[i].a;
	}
	printf("%I64d\n",ans);
	return 0;
}