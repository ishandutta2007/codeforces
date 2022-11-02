// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,m,p[2010],ans=0,big=0;
	scanf("%d%d",&n,&m);
	ans=m;
	for ( int i=1; i<=n; i++ ) scanf("%d",p+i);
	for ( int i=n; i>0; i-- ) {
		ans=max(ans,m%p[i]+m/p[i]*big);
		big=max(p[i],big);
	}
	printf("%d\n",ans);
	return 0;
}