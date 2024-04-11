#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,K,i,j,k,tot,ans,x,y,now;
int id[3005][6005],fa[5000005];
int st[10000005],st_fa[10000005],top;

int get(int x)
{
	if(fa[x]==x)return x;
	st[++top]=x;
	st_fa[top]=fa[x];
	fa[x]=get(fa[x]);
	return fa[x];
}

void Union(int x,int y)
{
	if(!x||!y)return;
	if(x==y)return;
	x=get(x);
	y=get(y);
	st[++top]=x;
	st_fa[top]=x;
	fa[x]=y;
}

void Clear()
{
	for(;top;--top)
	fa[st[top]]=st_fa[top];
}

int main()
{
	scanf("%d%d%d",&n,&m,&K);
	for(i=1;i<=K+K;++i)fa[i]=i;
	for(;K;--K)
	{
		scanf("%d%d",&x,&y);
		id[x][y]=++tot;
		id[x][y+m]=++tot;
		if(y==m)id[x][0]=tot;
		if(y==1)id[x][m+m+1]=tot-1;
		top=0;
		now=id[x][y];
		Union(now,id[x-1][y]);
		Union(now,id[x+1][y]);
		Union(now,id[x][y-1]);
		Union(now,id[x][y+1]);
		Union(now,id[x-1][y-1]);
		Union(now,id[x-1][y+1]);
		Union(now,id[x+1][y-1]);
		Union(now,id[x+1][y+1]);
		y+=m;
		now=id[x][y];
		Union(now,id[x-1][y]);
		Union(now,id[x+1][y]);
		Union(now,id[x][y-1]);
		Union(now,id[x][y+1]);
		Union(now,id[x-1][y-1]);
		Union(now,id[x-1][y+1]);
		Union(now,id[x+1][y-1]);
		Union(now,id[x+1][y+1]);
		if(get(tot-1)==get(tot))
		{
			Clear();
			id[x][y]=0;
			id[x][y-m]=0;
			if(y==m+m)id[x][0]=0;
			if(y==m+1)id[x][m+m+1]=0;
			continue;
		}
		++ans;
	}
	printf("%d\n",ans);
}