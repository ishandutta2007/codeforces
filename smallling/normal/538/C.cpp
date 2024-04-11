#include<cstdio>
#include<algorithm>

using namespace std;

int now,n,m,ans,d[100010],h[100010];

int main()
{
	scanf("%d%d",&n,&m);
	d[0]=1;
	h[0]=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&d[i],&h[i]);
		if(i==1)
		{
			ans=max(ans,h[i]+abs(d[i]-1));
			continue;
		}
		if(abs(d[i]-d[i-1])<abs(h[i]-h[i-1]))return puts("IMPOSSIBLE"),0;
		now=d[i]-d[i-1]-abs(h[i]-h[i-1]);
		ans=max(ans,h[i-1]+(now)/2);
		ans=max(ans,h[i]+now/2);
	}
	ans=max(ans,h[m]+n-d[m]);
	printf("%d",ans);
}