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
#define PII pair<long long,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,k;
int a[1<<20];
struct edge{
	int u,v,w;
	const bool operator <(const edge &x)const{
		return w>x.w;
	}
};
priority_queue<edge>Q;
int id[1<<20];
int cnt;
int head[20010],tmp[20010],nxt[1000010],to[1000010],w[1000010],len[1000010],tot=1;
void add(int x,int y,int z,int d){
	// printf("%d %d %d %d\n",x,y,z,d);
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y,w[tot]=z,len[tot]=d;
	nxt[++tot]=head[y],head[y]=tot,to[tot]=x,w[tot]=0,len[tot]=-d;
}
int popcount(int x){
	int t=0;
	while(x) ++t,x-=x&-x;
	return t;
}
int s,ss,t;
bool vis[20010];
long long h[20010],dis[20010];
bool spfa(){
	memset(dis,-0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	queue<int>Q;
	Q.push(s);dis[s]=0;
	while(!Q.empty()){
		int u=Q.front();Q.pop();vis[u]=1;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(w[i]>0&&dis[v]<dis[u]+len[i]+h[u]-h[v]){
				dis[v]=dis[u]+len[i]+h[u]-h[v];Q.push(v);
			}
		}
	}
	return vis[t];
}
int dinic(int x,int mxf){
	vis[x]=1;
	if(x==t) return mxf;
	// printf("x:%d,mxf:%d\n",x,mxf);
	int sum=0;
	for(int &i=tmp[x];i;i=nxt[i]){
		if(!vis[to[i]]) if(w[i]>0&&h[to[i]]==h[x]+len[i]){
			int d=dinic(to[i],min(mxf,w[i]));
			mxf-=d;sum+=d;w[i]-=d;w[i^1]+=d;if(!mxf) return sum;
		}
	}
	return sum;
}
long long MCMF(){
	long long mincost=0,maxflow=0;
	while(spfa()){
		// printf("dafd\n");
		for(int i=1;i<=cnt;++i) if(vis[i]) h[i]+=dis[i];
		int fl=0;
		for(int i=1;i<=cnt;++i) tmp[i]=head[i];
		do{
			memset(vis,0,sizeof(vis));
			fl=dinic(s,0x3f3f3f3f);
			mincost+=fl*h[t],maxflow+=fl;
			// printf("fl:%d,%d\n",fl,mincost);
		}while(vis[t]);
	}
	// printf("%d %d\n",maxflow,mincost);
	return mincost;
}
int main(){
	n=read(),k=read();
	for(int i=0;i<(1<<n);++i) a[i]=read();
	for(int i=0;i<(1<<n);++i){
		for(int j=0;j<n;++j) if(i>>j&1){
			Q.push(edge{i,i^(1<<j),a[i]+a[i^(1<<j)]});
		}
		while(Q.size()>n*2*k) Q.pop();
	}
	while(!Q.empty()){
		edge e=Q.top();Q.pop();
		if(!id[e.u]) id[e.u]=++cnt;
		if(!id[e.v]) id[e.v]=++cnt;
		if(popcount(e.u)&1) swap(e.u,e.v);
		add(id[e.u],id[e.v],1,0);
	}
	s=++cnt,ss=++cnt,t=++cnt;
	add(s,ss,k,0);
	for(int i=0;i<(1<<n);++i) if(id[i]){
		if(popcount(i)&1) add(id[i],t,1,a[i]);else add(ss,id[i],1,a[i]);
	}
	printf("%lld\n",MCMF());
}