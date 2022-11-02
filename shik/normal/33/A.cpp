// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,m,t,i,sml[1010],r,c,ans=0;
	scanf("%d%d%d",&n,&m,&t);
	for ( i=1; i<=m; i++ ) sml[i]=999999999;
	for ( i=1; i<=n; i++ ) {
		scanf("%d%d",&r,&c);
		sml[r]=min(sml[r],c);
	}
	for ( i=1; i<=m; i++ ) ans+=sml[i];
	ans=min(ans,t);
	printf("%d\n",ans);
	return 0;
}