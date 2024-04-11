#include<stdio.h>
#include<algorithm>
#define MAXN 3010000
using namespace std;
int te[MAXN];
int p,n,m;
int pr[200];
int dis[MAXN];
bool can[MAXN]={false};
#define min(a,b) ((a)<(b)?(a):(b))
void dfs(int now,int x)
{
	if(!now)
	{
		te[++te[0]]=x;
		return;
	}
	for(;;)
	{
		dfs(now-1,x);
		if(n/x<pr[now])break;
		x*=pr[now];
	}
}
int main()
{
	scanf("%d%d%d",&m,&n,&p);
	for(int i=2;i<=p;i++)
	{
		bool flag=false;
		for(int j=2;j*j<=i;j++)
		if(i%j==0)flag=true;
		if(!flag)pr[++pr[0]]=i;
	}
	dfs(pr[0],1);
	sort(te+1,te+1+te[0]);
	for(int i=1;i<=te[0];i++)dis[i]=999999999;
	dis[1]=0;
	for(int i=2;i<=p;i++)
	{
		int l=1;
		for(int j=1;j<=te[0];j++)
		{
			while(te[l]<te[j]*i&&l<=te[0])l++;
			if(l<=te[0])
			{
				dis[l]=min(dis[l],dis[j]+1);
				if(dis[l]+i<=p)can[l]=1;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=te[0];i++)
	if(can[i])
	if(te[i]<=n&&te[i]>=m)ans++;
	printf("%d\n",ans);
	return 0;
}