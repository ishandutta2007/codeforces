// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,d[110],i,a,b,ans=0;
	scanf("%d",&n);
	for ( i=1; i<n; i++ ) scanf("%d",d+i);
	scanf("%d%d",&a,&b);
	for ( i=a; i<b; i++ ) ans+=d[i];
	printf("%d\n",ans);
	return 0;
}