#include<cstdio>
#include<cstdlib>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
#define MM 200000
struct edge{int nx,t;}e[MN*2+5];
int h[MN+5],en,u[MN+5][2],q[MN*2+5],qn;
inline void ins(int x,int y){e[++en]=(edge){h[x],y};h[x]=en;}
void out(int x,int y)
{
	if(x!=q[0]||y)out(u[x][y],y^1);
	printf("%d ",x);
}
void dfs(int x)
{
	u[x][0]=-1;
	for(int i=h[x];i;i=e[i].nx)
		if(u[e[i].t][0]>=0)dfs(e[i].t);
		else if(u[e[i].t][0]>-2){puts("Draw");exit(0);}
	u[x][0]=-2;
}
int main()
{
	int n,m,i,j,x;
	n=read();m=read();
	for(i=1;i<=n;++i)for(x=read();x--;)ins(i,read());
	u[q[0]=read()][0]=1;
	for(i=0;i<=qn;++i)
	{
		if(q[i]<0)
		{
			if(!h[x=-q[i]]){puts("Win");out(x,1);return 0;}
			for(j=h[x];j;j=e[j].nx)if(!u[e[j].t][0])u[e[j].t][0]=x,q[++qn]=e[j].t;
		}
		else for(j=h[x=q[i]];j;j=e[j].nx)if(!u[e[j].t][1])u[e[j].t][1]=x,q[++qn]=-e[j].t;
	}
	dfs(q[0]);
	puts("Lose");
}