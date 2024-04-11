#include <cstdio>
#include <algorithm>
using namespace std;
int n,i;
long long v[200005],ans;
int main()
{
	scanf("%d",&n);
	for (i=1;i<=2*n;i++)
		scanf("%I64d",&v[i]);
	sort(v+1,v+2*n+1);
	ans=(v[2*n]-v[n+1])*(v[n]-v[1]);
	for (i=2;i<=n;i++)
		if ((v[i+n-1]-v[i])*(v[2*n]-v[1])<ans)
			ans=(v[i+n-1]-v[i])*(v[2*n]-v[1]);
	printf("%I64d\n",ans);
	return 0;
}