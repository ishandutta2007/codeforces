#include<cstdio>
#include<queue>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
struct edge{int nx,t;}e[MN+5];
int u[MN+5],h[MN+5],en,r[MN+5];
queue<int> q[2];
inline void ins(int x,int y){e[++en]=(edge){h[x],y};h[x]=en;++r[y];}
void solve(queue<int>&Q)
{
	int x=Q.front(),i;Q.pop();
	for(i=h[x];i;i=e[i].nx)if(!--r[e[i].t])q[u[e[i].t]].push(e[i].t);
}
int main()
{
	int n,m,i,x,ans=0;
	n=read();m=read();
	for(i=0;i<n;++i)u[i]=read();
	while(m--)i=read(),ins(read(),i);
	for(i=0;i<n;++i)if(!r[i])q[u[i]].push(i);
	while(!q[0].empty()||!q[1].empty())
		if(q[0].empty())for(++ans;!q[1].empty();)solve(q[1]);
		else solve(q[0]);
	printf("%d",ans);
}