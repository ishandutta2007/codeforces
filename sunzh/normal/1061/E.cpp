#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
#define int long long 
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int s,t;
int n,X,Y;
int a[510];
int sum1[510],sum2[510],tag1[510],tag2[510];
vector<int>vec1[510],vec2[510];
int head[5010],nxt[100010],to[100010],w[100010],c[100010];
int pre[5010],edgenum[5010];
bool vis[5010];
int dis[5010];
int flow[5010];
int tot=2;
void add(int x,int y,int z,int cst){
	nxt[tot]=head[x],head[x]=tot,to[tot]=y,w[tot]=z,c[tot]=cst;
	tot++;
}
queue<int>q;
bool spfa(){
	memset(pre,-1,sizeof(pre));
	memset(dis,0x3f,sizeof(dis));
	memset(flow,0x3f,sizeof(flow));
	q.push(s);
	dis[s]=0;
	vis[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(w[i]>0&&dis[v]>dis[u]+c[i]){
				dis[v]=dis[u]+c[i];
				flow[v]=min(flow[u],w[i]);
				edgenum[v]=i;
				pre[v]=u;
				if(vis[v]==0){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	return pre[t]==-1?0:1;
}
void EK(int s,int t){
	int v;
	int maxflow=0;
	int mincost=0;
	while(spfa()) {
		maxflow+=flow[t];
		mincost+=flow[t]*dis[t];
		v=t;
		while(v!=s){
			w[edgenum[v]]-=flow[t];
			w[edgenum[v]^1]+=flow[t];
			v=pre[v];
		}
	}
	if(maxflow!=tag1[X]||maxflow!=tag2[Y]){
		printf("-1\n");exit(0);
	}
	printf("%lld\n",-mincost);
}
void dfs1(int x,int f){
	for(int v:vec1[x]){
		if(v==f) continue ;
		dfs1(v,x);
		sum1[x]+=sum1[v];
	}
	if(tag1[x]!=-1){
		if(sum1[x]>tag1[x]){
			printf("-1\n");exit(0);
		}
//		printf("x:%d,flow:%d\n",x,tag1[x]-sum1[x]);
		add(s,x,tag1[x]-sum1[x],0);
		add(x,s,0,0);
		sum1[x]=tag1[x];
	}
	else {
		add(f,x,0x3f3f3f3f,0),add(x,f,0,0);
	}
}
void dfs2(int x,int f){
	for(int v:vec2[x]){
		if(v==f) continue ;
		dfs2(v,x);
		sum2[x]+=sum2[v];
	}
	if(tag2[x]!=-1){
		if(sum2[x]>tag2[x]){
			printf("-1\n");exit(0);
		}
		
//		printf("2x:%d,flow:%d\n",x,tag2[x]-sum2[x]);
		add(x+n,t,tag2[x]-sum2[x],0);
		add(t,x+n,0,0);
		
		sum2[x]=tag2[x];
	}
	else {
		add(x+n,f+n,0x3f3f3f3f,0),add(f+n,x+n,0,0);
	}
}
signed main(){
	memset(tag1,-1,sizeof(tag1));
	memset(tag2,-1,sizeof(tag2));
	n=read(),X=read(),Y=read();
	s=0,t=n+n+1;
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		vec1[u].pb(v),vec1[v].pb(u); 
	}
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		vec2[u].pb(v),vec2[v].pb(u); 
	}
	int Q1=read();
	while(Q1--){
		int x=read();
		if(tag1[x]!=-1){
			int y=read();
			if(y==tag1[x]) continue ;
			printf("-1\n");return 0;
		}
		tag1[x]=read();
	}
	int Q2=read();
	while(Q2--){
		int x=read();
		if(tag2[x]!=-1){
			int y=read();
			if(y==tag2[x]) continue ;
			printf("-1\n");return 0;
		}
		tag2[x]=read();
	}
	dfs1(X,0);
	dfs2(Y,0);
	for(int i=1;i<=n;++i) add(i,i+n,1,-a[i]),add(i+n,i,0,a[i]);
	EK(s,t);
}