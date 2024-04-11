#include<cstdio>
#include<algorithm>

using namespace std;

int ans[2000010],n,now,a[2000010];

void should(int n)
{
	a[0]=0;
	while(n)
	{
		a[++a[0]]=n%10;
		n/=10;
	}
}

int main()
{
	scanf("%d",&n);
	should(n);
	while(1)
	{
		now=0;
		for(int i=a[0];i;i--)
			if(a[i])now=now*10+1,a[i]--;
			else now=now*10;
		if(!now)break;
		ans[++ans[0]]=now;
	}
	printf("%d\n",ans[0]);
	for(int i=1;i<=ans[0];i++)printf("%d ",ans[i]);
}