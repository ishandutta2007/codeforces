// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1000
using namespace std;
int pre[N];
int main()
{
	int n,k,c,i,x,ans=0,tmt=0;
	scanf("%d%d%d",&n,&k,&c);
	for ( i=1; i<=c; i++ ) {
		scanf("%d",&x);
		pre[x]=1;
	}
	for ( i=1; i<=n; i++ ) {
		if ( pre[i] || i-tmt==k ) {
			ans++;
			tmt=i;
		}
	}
	printf("%d\n",ans);
	return 0;
}