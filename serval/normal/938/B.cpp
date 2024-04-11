#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,ans;
int a[100005];
int main()
{
	scanf("%d",&n);
	a[0]=1;
	ans=a[n+1]=1000000;
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (i=1;i<=n+1;i++)
		if (max(a[i-1]-1,1000000-a[i])<ans)
			ans=max(a[i-1]-1,1000000-a[i]);
	printf("%d\n",ans);
	return 0;
}