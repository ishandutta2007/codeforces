#include<bits/stdc++.h>
using namespace std;
struct node{
	int to,next;
} edge[400001];
int n,m,k,kk,cnt,top,vis[100001],dfn[100001],head[100001],col[100001]; 
vector<int> st,col_gro[2];
void add(int x,int y)
{
	edge[++cnt].to=y;
	edge[cnt].next=head[x];
	head[x]=cnt;
}
void dfs(int x,int fa)
{
	st.push_back(x);
	dfn[x]=(int)st.size();
	for(int i=head[x];i;i=edge[i].next)
		if(edge[i].to!=fa)
		{
			if(!dfn[edge[i].to])
			{
				dfs(edge[i].to,x);
				continue;
			}
			if(dfn[x]-dfn[edge[i].to]+1<=k&&dfn[x]+1>=dfn[edge[i].to])
			{
				puts("2");
				cout<<dfn[x]-dfn[edge[i].to]+1<<endl;
				for(int j=dfn[edge[i].to]-1;j<dfn[x];j++)
					cout<<st[j]<<" ";
				exit(0);
			}
		}	
	st.pop_back();
}
void color(int x,int c)
{
	col_gro[c].push_back(x);
	col[x]=c;
	if(col_gro[c].size()==kk)
	{
		puts("1"); 
		for(int i=0;i<col_gro[c].size();i++)
			cout<<col_gro[c][i]<<" ";
//		for(int i:col_gro[c])
//			cout<<i<<" ";
		exit(0);
	}
	for(int i=head[x];i;i=edge[i].next)
		if(col[edge[i].to]==-1)
			color(edge[i].to,c^1);
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	memset(col,-1,sizeof(col));
	kk=(k+1)/2;
	dfs(1,0); 
	color(1,1);
	return 0;
}