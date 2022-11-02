#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n,m,i,j,k,u,v;
int prep[100005],from[100005],former[100005];
int Min[100005],ans;
bool vis[100005],mark[100005];

struct Edge
{
	int u,v,c,link,use,dec,inc;
}e[100005],q[1200000];
int tot;

bool Deric_MST(int n,int m,int &ans)
{
	int root=1,newdot=n;
	int i,j,k,u,v;
	bool finished;
	int c;
	
	ans=0;
	for(;;)
	{
		for(i=1;i<=newdot;++i)prep[i]=0;
		for(i=1;i<=m;++i)
		{
			u=e[i].u;
			v=e[i].v;
			if(u!=v&&v!=root)
			{
				if(!prep[v]||e[i].c<Min[v])
				{
					prep[v]=u;
					Min[v]=e[i].c;
					former[v]=e[i].link;
				}
			}
		}
		for(i=1;i<=newdot;++i)
		if(i!=root&&prep[i]==0)
		return false;
		
		for(i=1;i<=newdot;++i)
		if(i!=root)
		{
			++q[former[i]].use;
			ans+=Min[i];
		}
		for(i=1;i<=newdot;++i)vis[i]=false;
		k=newdot;finished=true;newdot=0;
		for(i=1;i<=k;++i)from[i]=0;
		for(i=1;i<=k;++i)
		if(!vis[i])
		{
			for(j=i;j;j=prep[j])
			{
				if(mark[j])break;
				if(vis[j])break;
				vis[j]=true;
				mark[j]=true;
			}
			if(mark[j])
			{
				++newdot;
				finished=false;
				for(;mark[j];j=prep[j])
				{
					mark[j]=false;
					from[j]=newdot;
				}
			}
			for(j=i;mark[j];j=prep[j])mark[j]=false;
		}
		if(finished)return true;
		
		for(i=1;i<=k;++i)if(!from[i])from[i]=++newdot;
		for(i=1;i<=m;++i)
		{
			v=e[i].v;
			e[i].c-=Min[e[i].v];
			e[i].u=from[e[i].u];
			e[i].v=from[e[i].v];
			if(e[i].u!=e[i].v)
			{
				q[++tot]=e[i];
				q[tot].use=0;
				q[tot].inc=e[i].link;
				q[tot].dec=former[v];
				e[i].link=tot;
			}
		}
		root=from[root];
	}
}

int T;
int main()
{
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].c);
		q[++tot]=e[i];
		e[i].link=tot;
	}
	if(Deric_MST(n,m,ans))
	{
		printf("%d\n",ans);
		for(i=tot;i>m;--i)
		{
			q[q[i].inc].use+=q[i].use;
			q[q[i].dec].use-=q[i].use;
		}
		for(i=1;i<=m;++i)if(q[i].c==1&&q[i].use>0)printf("%d ",i);
		printf("\n");
	}
	else printf("-1\n");
}