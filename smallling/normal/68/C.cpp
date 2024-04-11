#include<cstdio>
#include<algorithm>

using namespace std;

int l[7][7],h[7][7],A[7][7],a[36],b[36],sum[7];
int n,m,ans1,ans2,nowans,x,y,tot;

void dfs(int x)
{
	if(x>tot)
	{
		if(n>2&&sum[n-1]!=0)return;
		if(sum[1]==ans1)ans2=max(ans2,nowans);
		if(sum[1]<ans1)
		{
			ans1=sum[1];
			ans2=nowans;
		}
		return;
	}
	if(a[x]>1&&sum[a[x]]>0)return;
	if(sum[1]>ans1)return;
	if(a[x]>2&&sum[a[x]-1]!=0)return;
	for(int i=l[a[x]][b[x]];i<=h[a[x]][b[x]];i++)
	{
		sum[a[x]]+=i;
		sum[b[x]]-=i;
		if(i)nowans+=A[a[x]][b[x]]+i*i;
		dfs(x+1);
		if(i)nowans-=A[a[x]][b[x]]+i*i;
		sum[a[x]]-=i;
		sum[b[x]]+=i;
	}
}

int main()
{
	scanf("%d",&n);
	ans1=1e8;
	a[0]=1;
	b[0]=1;
	for(int i=1;i<=n*(n-1)/2;i++)
	{
		if(b[i]>n)b[i]=1,a[i]++;
		scanf("%d%d",&x,&y);
		scanf("%d%d%d",&l[x][y],&h[x][y],&A[x][y]);
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			a[++tot]=i,b[tot]=j;
	dfs(1);
	if(ans1==1e8)ans1=ans2=-1;
	printf("%d %d",ans1,ans2);
}