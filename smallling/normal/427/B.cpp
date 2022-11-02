#include<cstdio>
#include<algorithm>

using namespace std;

int n,t,c,a[300001],o,ans;

int main()
{
	scanf("%d%d%d",&n,&t,&c);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		if(a[i]<=t)o++;
		else
		{
			ans+=max(0,o-c+1);
			o=0;
		}
	ans+=max(0,o-c+1);
	printf("%d",ans);
}