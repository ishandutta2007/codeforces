#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int son[100005],next[200005],ed[200005];
int val[100005],id[100005],fa[100005],size[100005];
int n,m,u,v,i,j,k;
long long ans;
bool use[100005];

inline bool cmp(const int &a,const int &b){return val[a]>val[b];}
int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",&val[i]),id[i]=i,fa[i]=i,size[i]=1;
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		next[i]=son[u];son[u]=i;ed[i]=v;
		next[i+m]=son[v];son[v]=i+m;ed[i+m]=u;
	}
	sort(id+1,id+n+1,cmp);
	for(i=1;i<=n;++i)
	{
		k=id[i];
		use[k]=true;
		for(j=son[k];j;j=next[j])
		if(use[ed[j]])
		{
			u=get(k);
			v=get(ed[j]);
			if(u!=v)
			{
				ans+=((long long)val[k])*size[u]*size[v];
				fa[u]=v;
				size[v]+=size[u];
			}
		}
	}
	printf("%.9lf\n",((double)ans)/n/(n-1)*2);
}