#include<bits/stdc++.h>
using namespace std; 
int n,b,vis[5001],a[5001][5001];
char st[5001];
void dfs(int x,int fa)
{
	if(b)
		return ;
	vis[x]=1;
	for(int i=1;i<=n;i++)
		if(a[x][i])
		{
			int to=i;
			if(!b&&a[to][fa])
			{
				cout<<fa<<" "<<x<<" "<<to;
				b=1;
				return ;
			}
			if(!vis[to])
				dfs(to,x);
		}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",st+1);
		for(int l=1;l<=n;l++)
			a[i][l]=st[l]-'0';
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs(i,0);
	if(!b)
		puts("-1");
	return 0;
}//1