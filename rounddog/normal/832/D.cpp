#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<iostream>
#include<algorithm>
#define maxn 400020

int to[maxn],next[maxn],h[maxn],n,m,query,p,dep[maxn],d,b,c,a[maxn][20],ans;
bool visit[maxn];

using namespace std;

void add_edge(int x,int y)
{
	p++;
	to[p]=y;
	next[p]=h[x];
	h[x]=p;
}

void dfs(int x,int y)
{
	visit[x]=false;
	dep[x]=y;
	for (int i=h[x];i;i=next[i])
	    if (visit[to[i]]){
	    	a[to[i]][0]=x;
	        dfs(to[i],y+1);
	    }
}

int lca(int x,int y)
{
	if (dep[x]<dep[y]){
		int tmp=x;x=y;y=tmp;
	}  
	for (int i=18;i>=0;i--)
	    if (dep[x]-dep[y]>=(1<<i)) x=a[x][i];
    if (x==y) return x;
    for (int i=18;i>=0;i--)
        if (a[x][i]!=a[y][i]){
        	x=a[x][i];
        	y=a[y][i];
        }
    return a[x][0];
}

int check(int x,int y,int z)
{
	int tmp1=lca(x,z);
	int tmp2=lca(y,z);
	int tt=lca(x,y);
	if (tmp1!=tmp2) return (dep[z]-max(dep[tmp1],dep[tmp2])+1);
	else return (dep[z]+dep[tt]-dep[tmp1]*2+1);
}

int main()
{
	scanf("%d%d",&n,&query);
	p=0;
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&b);
		add_edge(b,i);
		add_edge(i,b);
	}
	memset(visit,true,sizeof(visit));
	dfs(1,0);a[1][0]=1;
    for (int j=1;j<=18;j++)
	    for (int i=1;i<=n;i++)
	        a[i][j]=a[a[i][j-1]][j-1];
    while (query--)
    {
    	scanf("%d%d%d",&b,&c,&d);
    	ans=0;
    	ans=max(ans,check(b,c,d));
    	ans=max(ans,check(b,d,c));
    	ans=max(ans,check(c,d,b));
    	printf("%d\n",ans);
    }
    return 0;
}