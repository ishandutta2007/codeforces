#include<bits/stdc++.h>

using namespace std;

int n,m,ans,g[110][110];
int L[110],R[110];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&g[i][j]);
	if(n<=m)
	{
		for(int i=1;i<=n;i++)
		{
			int nowm=100000;
			for(int j=1;j<=m;j++)
				nowm=min(nowm,g[i][j]);
			for(int j=1;j<=m;j++)
				g[i][j]-=nowm;
			ans+=nowm;
			L[i]=nowm;
		}
		for(int i=1;i<=m;i++)
		{
			int nowm=100000;
			for(int j=1;j<=n;j++)
				nowm=min(nowm,g[j][i]);
			for(int j=1;j<=n;j++)
				g[j][i]-=nowm;
			ans+=nowm;
			R[i]=nowm;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(g[i][j])
				{
					puts("-1");
					return 0;
				}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=L[i];j++)
				printf("row %d\n",i);
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=R[i];j++)
				printf("col %d\n",i);
		}
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			int nowm=100000;
			for(int j=1;j<=n;j++)
				nowm=min(nowm,g[j][i]);
			for(int j=1;j<=n;j++)
				g[j][i]-=nowm;
			ans+=nowm;
			R[i]=nowm;
		}
		for(int i=1;i<=n;i++)
		{
			int nowm=100000;
			for(int j=1;j<=m;j++)
				nowm=min(nowm,g[i][j]);
			for(int j=1;j<=m;j++)
				g[i][j]-=nowm;
			ans+=nowm;
			L[i]=nowm;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(g[i][j])
				{
					puts("-1");
					return 0;
				}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=L[i];j++)
				printf("row %d\n",i);
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=R[i];j++)
				printf("col %d\n",i);
		}
	}
}