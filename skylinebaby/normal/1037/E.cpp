#include<bits/stdc++.h>
using namespace std;
struct P{
	int x;int y;
};
P ar[201010];
int vis[201010];
vector<P> adj[201010];
int deg[201010]; 
int gog[201010];
int anw[201010];
int ans;
int k;
int n;
void del(int i)
{
	gog[i] = 0;
	//printf("del %d\n",i);
	//for(int j = 0;j<n;j++) printf("%d ",deg[j]);
	ans -- ;
	for(int j = 0;j<adj[i].size();j++)
	{
		if(vis[adj[i][j].y]==1) continue;
		int x = adj[i][j].x;		
		//printf("%d %d %d\n",i,x,adj[i][j].y);
		deg[x]--;
		vis[adj[i][j].y]=1;
		if (deg[x]<k&&gog[x]==1) del(x);
	}
}
int main()
{
	int m;
	scanf("%d %d %d",&n,&m,&k);
	for(int i = 0;i<m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		x--;y--;
		ar[i]=(P){x,y};
		deg[x]++;
		deg[y]++;
		adj[x].push_back((P){y,i});
		adj[y].push_back((P){x,i});
	} 
	memset(vis,0,sizeof(vis));
	ans = n;
	for(int i = 0;i<n;i++) gog[i] = 1;
	for(int i = 0;i<n;i++)
	{
		if(deg[i]<k&&gog[i]==1) del(i);
	}
	anw[m-1] = ans;
	for(int i = m-1;i>0;i--)
	{
		int x = ar[i].x;
		int y = ar[i].y;
		if (gog[x]==gog[y]&&gog[x]==1)
		{
			deg[x]--;
			if(deg[x]<k) del(x);
			else 
			{
				deg[y]--;
				deg[x]++;
				if(deg[y]<k) del(y);
				else 
				{
					deg[x]--;
					vis[i]=1;
				}			
			}			
		}
		anw[i-1] = ans;
	}
	for(int i = 0;i<m;i++)
	{
		printf("%d\n",anw[i]);
	}
	return 0;
}