#include<bits/stdc++.h>
using namespace std;
int n,m,ans,know[101][101],fa[101];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x)
			ans=-1;
		while(x--)
		{
			int y;
			scanf("%d",&y);
			know[i][y]=1;
		}
	}
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=n;i++)
		for(int l=i+1;l<=n;l++)
		{
			bool flag=0;
			for(int j=1;j<=m;j++)
				if(know[i][j]&&know[l][j])
				{
					
					flag=1;
					break;
				}
			if(flag)
				fa[find(i)]=find(l);	
		}
	for(int i=1;i<=n;i++)
		if(fa[i]==i)
			ans++;
	cout<<ans;
	return 0;
}