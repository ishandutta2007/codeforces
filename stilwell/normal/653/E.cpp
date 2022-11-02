#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <algorithm>
using namespace std;

int n,m,K,i,j,k,u,v,l,r,pre,cnt,Cnt;
int fa[300005],fa_[300005],size[300005];

struct node
{
	int u,v;
}t[600005];
int tot;
inline bool cmp(const node &a,const node &b)
{
	if(a.u!=b.u)return a.u<b.u;
	return a.v<b.v;
}
int get(int *fa,int x){return fa[x]==x?x:fa[x]=get(fa,fa[x]);}

void merge(int u,int v)
{
	u=get(fa,u);v=get(fa,v);
	if(u!=v)fa[u]=v;
}
void work(int l,int r)
{
	if(l>r)return;
	for(;l<=r;l=get(fa_,l))
	{
		merge(i,l);
		fa_[l]=l+1;
	}
	merge(i,r);
}

int main()
{
	scanf("%d%d%d",&n,&m,&K);
	cnt=n-1;
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		++tot;t[tot].u=u;t[tot].v=v;
		++tot;t[tot].u=v;t[tot].v=u;
	}
	sort(t+1,t+tot+1,cmp);
	for(i=1;i<=n+1;++i)fa[i]=fa_[i]=i;
	for(i=1;i<=tot;++i)
	if(t[i].u!=1)
	{
		r=i-1;
		break;
	}
	for(i=2;i<=n;++i)
	{
		l=r+1;
		for(;r<tot&&t[r+1].u==i;++r);
		k=1;
		for(j=l;j<=r;++j)work(k+1,t[j].v-1),k=t[j].v;
		work(k+1,n);
	}
	for(i=2;i<=n;++i)++size[get(fa,i)];
	for(i=1;i<=tot;++i)if(t[i].u==1)--size[get(fa,t[i].v)],--cnt;
	for(i=2;i<=n;++i)
	if(fa[i]==i)
	{
		++Cnt;
		if(!size[i])
		{
			printf("impossible\n");
			return 0;
		}
	}
	if(cnt<K||Cnt>K)
	{
		printf("impossible\n");
		return 0;
	}
	printf("possible\n");
}