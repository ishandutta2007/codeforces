#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,m;
int s,t;
int cnt;
int head[1510],nxt[200010],to[200010],w[200010],c[200010];
int tot=1;
bool used[110][110];
int id[110][110][2];
bool ans[110][110];
bool vis[1510];
int dis[1510],flow[1510],pre[1510],edgenum[1510],h[1510];
void add(int x,int y,int z,int cst){
	if(x<0||y<0) return ;
	// printf("x:%d,y:%d,z:%d,cst:%d\n",x,y,z,cst);
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y,w[tot]=z,c[tot]=cst;
	nxt[++tot]=head[y],head[y]=tot,to[tot]=x,w[tot]=0,c[tot]=-cst;
}
bool dijkstra(){
	memset(dis,0x3f,sizeof(dis));
	memset(flow,0x3f,sizeof(flow));
	memset(pre,-1,sizeof(pre));
	priority_queue<PII,vector<PII>,greater<PII> >Q;
	Q.push(mp(0,s));dis[s]=0;
	while(!Q.empty()){
		PII now=Q.top();Q.pop();
		int u=now.se;
		if(now.fi!=dis[u]) continue ;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(w[i]>0&&dis[v]>dis[u]+c[i]+h[u]-h[v]){
				dis[v]=dis[u]+c[i]+h[u]-h[v];
				flow[v]=min(flow[u],w[i]);
				pre[v]=u,edgenum[v]=i;
				Q.push(mp(dis[v],v));
			}
		}
	}
	return pre[t]!=-1;
}
int dinic(int x,int maxf){
	vis[x]=1;
	if(x==t) return maxf;
	int sum=0;
	for(int i=head[x];i;i=nxt[i]){
		int v=to[i];
		if(!vis[v]){
			if(w[i]&&h[v]==h[x]+c[i]){
				int d=dinic(v,min(maxf,w[i]));
				maxf-=d;w[i]-=d;w[i^1]+=d;sum+=d;
				if(!maxf) return sum;
			}
		}
	}
	return sum;
}
int in[110];
void mcmf(){
	// return ;
	int v;int maxflow=0,mincost=0;
	while(dijkstra()){
		// printf("?ad\n");
		for(int i=0;i<=cnt;++i){
			if(dis[i]<0x15151515) h[i]+=dis[i];
		}
		do{
			memset(vis,0,sizeof(vis));
			int flow=dinic(s,0x3f3f3f3f);
			mincost+=flow*h[t];maxflow+=flow;
			// printf("flow:%d,h:%d\n",flow,h[t]);
		}while(vis[t]);
	}
	// printf("%d %d\n",maxflow,mincost);
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		++in[u];used[u][v]=used[v][u]=1;
		ans[u][v]=1;
	}
	s=0;cnt=n;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j) if(!used[i][j]){
			// printf("i:%d,j:%d\n",i,j);
			add(s,++cnt,1,0);
			id[i][j][0]=tot+1;
			add(cnt,i,1,0);
			id[i][j][1]=tot+1;
			add(cnt,j,1,0);
		}
	}
	t=++cnt;
	for(int i=1;i<=n;++i){
		for(int j=in[i]+1;j<=n;++j){
			add(i,t,1,(j*(j-1)>>1)-((j-1)*(j-2)>>1));
		}
	}
	mcmf();
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j) if(!used[i][j]){
			if(!w[id[i][j][0]]){
				ans[i][j]=1;
			}
			else ans[j][i]=1;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) putchar(ans[i][j]+'0');
		putchar('\n');
	}
}