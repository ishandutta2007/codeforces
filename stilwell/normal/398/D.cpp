#include <stdio.h>
#include <stdlib.h>
using namespace std;

int son[50005],next[500005],ed[500005];
int ans[50005],size[50005],now[50005];
int u[200005],v[200005];
int n,m,q,i,j,k,x,y,tot;
char opt;

void addedge(int u,int v){next[++tot]=son[u];son[u]=tot;ed[tot]=v;ans[v]+=now[u];}

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	scanf("%d",&k);
	for(;k;--k)scanf("%d",&i),now[i]=1;
	for(i=1;i<=m;++i)scanf("%d%d",&u[i],&v[i]),++size[u[i]],++size[v[i]];
	for(i=1;i<=m;++i)if(size[u[i]]<size[v[i]])addedge(u[i],v[i]);else addedge(v[i],u[i]);
	for(;q;--q)
	{
		opt=getchar();
		while(opt!='O'&&opt!='F'&&opt!='A'&&opt!='D'&&opt!='C')opt=getchar();
		if(opt=='O')
		{
			scanf("%d",&x);now[x]=1;
			for(i=son[x];i;i=next[i])++ans[ed[i]];
		}
		if(opt=='F')
		{
			scanf("%d",&x);now[x]=0;
			for(i=son[x];i;i=next[i])--ans[ed[i]];
		}
		if(opt=='A')
		{
			scanf("%d%d",&x,&y);
			++size[x];++size[y];
			if(size[x]<size[y])addedge(x,y);else addedge(y,x);
		}
		if(opt=='D')
		{
			scanf("%d%d",&x,&y);
			--size[x];--size[y];
			for(j=0,i=son[x];i;j=i,i=next[i])
			if(ed[i]==y)
			{
				if(j)next[j]=next[i];else son[x]=next[i];
				ans[y]-=now[x];
				break;
			}
			if(i)continue;
			for(j=0,i=son[y];i;j=i,i=next[i])
			if(ed[i]==x)
			{
				if(j)next[j]=next[i];else son[y]=next[i];
				ans[x]-=now[y];
				break;
			}
		}
		if(opt=='C')
		{
			scanf("%d",&x);
			y=ans[x];
			for(i=son[x];i;i=next[i])y+=now[ed[i]];
			printf("%d\n",y);
		}
	}
}