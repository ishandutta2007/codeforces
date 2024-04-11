#include<cstdio>
#include<algorithm>

using namespace std;

int a[101],c,i,n,ans;

int main()
{
	scanf("%d%d",&n,&c);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(i>1)ans=max(ans,a[i-1]-a[i]);
	}
	ans-=c;
	ans=max(ans,0);
	printf("%d",ans);
}