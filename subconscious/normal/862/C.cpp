#include<cstdio>
#include<algorithm>
using namespace std;
int ans[100010],tmp[100010],x,fuck,n,tot;
int main()
{
	scanf("%d%d",&n,&x);
	if(n==2&&!x)
	{
		puts("NO");
		return 0;
	}
	for(int i=0;i<n-1;i++)
	{
		ans[i+1]=i;
		fuck^=i;
	}
	ans[n]=x^fuck;
	if(ans[n]<=n-2)
	{
		if(ans[n]==0)
		{
			ans[2]+=1<<19;
		}
		else
		{
			ans[1]+=1<<19;
		}
		ans[n]+=1<<19;
	}
	puts("YES");
	for(int i=1;i<n;i++)
	{
		printf("%d ",ans[i]);
	}
	printf("%d\n",ans[n]);
	return 0;
}