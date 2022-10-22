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
int n,m;
int N;
struct edge{
	int u,v,w;
}e[100010];
int tot=2;
int s,t;
int head[20010],nxt[400010],to[400010],w[400010];
int depth[20010],gap[20010];
void add(int x,int y,int z){
	nxt[tot]=head[x],head[x]=tot,to[tot]=y,w[tot]=z;
	tot++;
}
bool bfs(int s,int t){
	queue<int>q;
	while(!q.empty()) q.pop();
	q.push(t);
	depth[t]=1;
	gap[1]++;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(depth[v]==0){
				depth[v]=depth[u]+1;
				gap[depth[v]]++;
				q.push(v);
			}
		}
	}
	if(depth[s]==0) return 0;
	return 1;
}
int dfs(int x,int maxf){
	if(x==t) return maxf;
	int sum=0;
	for(int i=head[x];i;i=nxt[i]){
		int v=to[i];
		if(depth[v]+1==depth[x]){
			int di=dfs(v,min(maxf,w[i]));
			w[i]-=di;
			w[i^1]+=di;
			maxf-=di;
			sum+=di;
			if(maxf==0) return sum;
		}
	}
	if(--gap[depth[x]]==0) depth[s]=N+1;
	++gap[++depth[x]];
	return sum;
}
inline int ISAP(int s,int t){
	int maxflow=0;
	if(bfs(s,t)==0) return 0;
	while(depth[s]<=N) {
		maxflow+=dfs(s,0x3f3f3f3f);
	}
	return maxflow;
}
bool solve(int x){
	tot=2;memset(head,0,sizeof(head));
	memset(depth,0,sizeof(depth));
	memset(gap,0,sizeof(gap));
	for(int i=1;i<=m;++i){
		if(e[i].w<=x){
			add(e[i].u,e[i].v+n,1);add(e[i].v+n,e[i].u,0);
		}
	}
	for(int i=1;i<=n;++i) add(s,i,1),add(i,s,0),add(i+n,t,1),add(t,i+n,0);
	return ISAP(s,t)==n;
}
int main(){
	n=read(),m=read();
	N=2*n+2;s=0,t=2*n+1;
	for(int i=1;i<=m;++i){
		e[i].u=read(),e[i].v=read(),e[i].w=read();
	}
	int ans=-1;
	int l=0,r=1e9;
	while(l<=r){
		int mid=l+r>>1;
		if(solve(mid)){
			ans=mid;r=mid-1;
		}
		else l=mid+1;
	}
	print(ans);
}