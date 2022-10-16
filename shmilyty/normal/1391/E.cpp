#include<bits/stdc++.h>
using namespace std;
struct node{
	int to,next;
} edge[2000001];
int t,n,m,cnt,path,head[500001],fa[500001],dep[500001],vis[500001];
vector<int> buc[500001];
void add(int x,int y)
{
	edge[++cnt].to=y;
	edge[cnt].next=head[x];
	head[x]=cnt;
}
void dfs(int x)
{
	vis[x]=1;
	for(int i=head[x];i;i=edge[i].next)
		if(!vis[edge[i].to])
		{
			dep[edge[i].to]=dep[x]+1;
			fa[edge[i].to]=x;
			dfs(edge[i].to);
		}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(vis,0,(n+1)*sizeof(int));
		memset(fa,0,(n+1)*sizeof(int));
		memset(dep,0,(n+1)*sizeof(int));
		memset(head,0,(n+1)*sizeof(int));
		path=cnt=0;
		for(int i=1;i<=n;i++)
			buc[i].clear();
		for(int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		dep[1]=1;
		dfs(1);
		for(int i=1;i<=n;i++)
			if(dep[i]>=(n+1)>>1)
			{
				puts("PATH");
				cout<<dep[i];
				while(i)
				{
					cout<<" "<<i;
					i=fa[i];
				}
				puts("");
				path=1;
				break;
			}
			else
				buc[dep[i]].push_back(i); 
		if(path)
			continue;
		puts("PAIRING");
		cnt=0;
		for(int i=1;i<=n;i++)
			cnt+=(buc[i].size()/2);
		cout<<cnt<<endl;
		for(int i=1;i<=n;i++)
			for(int l=0;l+1<buc[i].size();l+=2)
				cout<<buc[i][l]<<" "<<buc[i][l+1]<<endl;
	}
	
}//1