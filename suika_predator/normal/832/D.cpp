#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=100011;
int n,q;
struct edge
{
	int v;
	edge *next;
}*h[MAXN],pool[MAXN*2];
int top;
inline void addedge(int u,int v)
{
	edge *tmp=&pool[top++];tmp->v=v;tmp->next=h[u];h[u]=tmp;
	edge *pmt=&pool[top++];pmt->v=u;pmt->next=h[v];h[v]=pmt;
}
int pa[MAXN],jmp[MAXN][21],dep[MAXN];
queue<int> Q;
inline int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;i>=0;i--)
	{
		if(dep[jmp[x][i]]>=dep[y])x=jmp[x][i];
	}
	for(int i=20;i>=0;i--)
	{
		if(jmp[x][i]!=jmp[y][i])
		{
			x=jmp[x][i];
			y=jmp[y][i];
		}
	}
	//cout<<x<<' '<<y<<endl;
	while(x!=y)
	{
		x=pa[x];
		y=pa[y];
	}
	return x;
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&pa[i]);
		//cout<<i<<' '<<pa[i]<<endl;
		addedge(pa[i],i);
		jmp[i][0]=pa[i];
	}
	Q.push(1);
	dep[1]=1;
	while(!Q.empty())
	{
		int u=Q.front();Q.pop();
		//cout<<u<<endl;
		for(edge *tmp=h[u];tmp;tmp=tmp->next)
		{
			if(!dep[tmp->v])
			{
				dep[tmp->v]=dep[u]+1;
				Q.push(tmp->v);
			}
		}
	}
	for(int j=1;j<=20;j++)
	{
		for(int i=1;i<=n;i++)
		{
			jmp[i][j]=jmp[jmp[i][j-1]][j-1];
		}
	}
	/*
	for(int i=1;i<=n;i++)
	{
		cout<<pa[i]<<' '<<dep[i]<<' '<<jmp[i][0]<<' '<<jmp[i][1]<<endl;
	}*/
	int a,b,c;
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		int d=lca(a,b),e=lca(a,c),f=lca(b,c);
		//cout<<d<<' '<<e<<' '<<f<<endl;
		if(c==e&&c==f/*&&(d==a||d==b)*/)
		{
			printf("%d\n",max(abs(dep[c]-dep[d])+1,max(abs(dep[a]-dep[d])+1,abs(dep[b]-dep[d])+1)));
		}
		else if(b==d&&b==f/*&&(a==e||c==e)*/)
		{
			printf("%d\n",max(abs(dep[b]-dep[e])+1,max(abs(dep[a]-dep[e])+1,abs(dep[c]-dep[e])+1)));
		}
		else if(a==d&&a==e/*&&(b==f||c==f)*/)
		{
			printf("%d\n",max(abs(dep[a]-dep[f])+1,max(abs(dep[b]-dep[f])+1,abs(dep[c]-dep[f])+1)));
		}
		else if(a==d)
		{
			printf("%d\n",max(abs(dep[c]-dep[e])+abs(dep[a]-dep[e])+1,abs(dep[b]-dep[a])+1));
		}
		else if(c==f)
		{
			printf("%d\n",max(abs(dep[c]-dep[e])+abs(dep[a]-dep[e])+1,abs(dep[b]-dep[c])+1));
		}
		else if(a==e)
		{
			printf("%d\n",max(abs(dep[b]-dep[d])+abs(dep[a]-dep[d])+1,abs(dep[c]-dep[a])+1));
		}
		else if(b==f)
		{
			printf("%d\n",max(abs(dep[b]-dep[d])+abs(dep[a]-dep[d])+1,abs(dep[c]-dep[b])+1));
		}
		else if(b==d)
		{
			printf("%d\n",max(abs(dep[b]-dep[f])+abs(dep[c]-dep[f])+1,abs(dep[a]-dep[b])+1));
		}
		else if(c==e)
		{
			printf("%d\n",max(abs(dep[b]-dep[f])+abs(dep[c]-dep[f])+1,abs(dep[a]-dep[c])+1));
		}
		else
		{
			int dis1,dis2,dis3;
			if(d==e)
			{
				dis1=abs(dep[f]-dep[d])+abs(dep[a]-dep[d])+1;
				dis2=abs(dep[b]-dep[f])+1;
				dis3=abs(dep[c]-dep[f])+1;
			}
			else if(d==f)
			{
				dis1=abs(dep[e]-dep[d])+abs(dep[b]-dep[d])+1;
				dis2=abs(dep[a]-dep[e])+1;
				dis3=abs(dep[c]-dep[e])+1;
			}
			else
			{
				dis1=abs(dep[d]-dep[e])+abs(dep[c]-dep[e])+1;
				dis2=abs(dep[b]-dep[d])+1;
				dis3=abs(dep[a]-dep[d])+1;
			}
			int maxx=max(dis1,dis2);
			maxx=max(maxx,dis3);
			printf("%d\n",maxx);
		}
	}
	return 0;
}