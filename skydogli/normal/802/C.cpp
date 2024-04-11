#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int a=0;char c=getchar();
	while(c>57 or c<48)c=getchar();
	while(47<c and c<58){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
#define MN 100005
#define INF 2147483647
int to[MN],c[MN],nxt[MN],head[MN],cnt,cur[MN],dis[MN];
int lst[MN],pre[MN],flow[MN];
int dep[MN],vis[MN];
int n,m,S,T,N;
queue<int>Q;
void ADD(int x,int y,int z,int d){
	++cnt;
	to[cnt]=y;
	c[cnt]=z;
	dis[cnt]=d;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
void add(int x,int y,int z,int d){
	ADD(x,y,z,d);
	ADD(y,x,0,-d);
}
bool bfs(){
	while(!Q.empty())Q.pop();
	for(int i=1;i<=N;++i)dep[i]=1e9;
	memset(flow,0x3f,sizeof(flow));
	for(int i=1;i<=N;++i)vis[i]=0;
	Q.push(S);
	dep[S]=0;
	while(!Q.empty()){
		int x=Q.front();
		Q.pop();
		vis[x]=0;
		for(int i=head[x];i;i=nxt[i]){
			int v=to[i];
			if(c[i]<=0)continue;
			if(dep[v]>dep[x]+dis[i]) {
				pre[v]=x;
				lst[v]=i;
				dep[v]=dep[x]+dis[i];
				flow[v]=min(flow[x],c[i]);
				if(!vis[v])Q.push(v),vis[v]=1;
			}
		}
	}
	return dep[T]<1e8;
}
int cost;
int Dinic(){
	int ans=0;
	while(bfs()){
		int now=T;
		ans+=flow[now];
		cost+=flow[T]*dep[T];
		while(now!=S){
			c[lst[now]]-=flow[T];
			c[lst[now]^1]+=flow[T];
			now=pre[now];
		}
	}
	return ans;
}
int a[MN],co[MN];
int main(){
	cnt=1;
	n=read();m=read();
	N=n*2+2;S=n*2+1;T=n*2+2;
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)co[i]=read();
	for(int i=1;i<=n;++i){
		add(S,i,1,co[a[i]]);
		add(i,i+n,1,0);
		if(i<n)add(i,i+1,m-1,0);
		add(i+n,T,1,0);
		for(int j=i-1;j;--j)
			if(a[i]==a[j]){
			//	cerr<<"OK "<<i<<" "<<j<<endl;
				add(i-1,j+n,1,-co[a[i]]);
				break;
			}
	}
	Dinic();
	printf("%d\n",cost);
	return 0;
}