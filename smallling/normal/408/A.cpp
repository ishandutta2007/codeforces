#include<cstdio>
#include<algorithm>

using namespace std;

int i,j,n,now,a[101],ans,o;

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	ans=210000000;
	for(i=1;i<=n;i++)
	{
		now=a[i]*15;
		for(j=1;j<=a[i];j++)
		{
			scanf("%d",&o);
			now+=o*5;
		}
		ans=min(ans,now);
	}
	printf("%d",ans);
}