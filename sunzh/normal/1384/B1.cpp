#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int T;
int n,k,l;
int s,t;
int tot=2;
int d[20010],p[20010];
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
	if(--gap[depth[x]]==0) depth[s]=t+1;
	++gap[++depth[x]];
	return sum;
}
inline int ISAP(int s,int t){
	int maxflow=0;
	if(bfs(s,t)==0) return 0;
	while(depth[s]<=t) {
		maxflow+=dfs(s,0x3f3f3f3f);
	}
	return maxflow;
}
int main(){
	T=read();
	while(T--){
		n=read(),k=read(),l=read();
		memset(head,0,sizeof(head));
		memset(depth,0,sizeof(depth));
		memset(gap,0,sizeof(gap));
		tot=2;
		s=0,t=n*k<<1|1;
		for(int i=1;i<=n;++i) d[i]=read();
		for(int i=0;i<=k;++i) p[i]=i;
		for(int i=k+1;i<=2*k-1;++i) p[i]=k-(i-k); 
		for(int i=1;i<=2*k;++i) add(s,i,1),add(i,s,0);
		for(int i=1;i<n;++i){
			for(int j=0;j<=2*k-1;++j){
				if(d[i]+p[j]<=l){
					add((i-1)*2*k+j+1,i*2*k+(j==2*k-1?1:j+2),1);
					add(i*2*k+(j==2*k-1?1:j+2),(i-1)*2*k+j+1,0);
					if(j&&d[i]+p[j-1]<=l){ 
						add((i-1)*2*k+j,(i-1)*2*k+j+1,1);
						add((i-1)*2*k+j+1,(i-1)*2*k+j,0);
					}
					else if(d[i]+1<=l){
						add(i*k<<1,(i-1)*k<<1|1,1);
						add((i-1)*k<<1|1,i*k<<1,0);
					}
				}
			}
		}
		for(int i=0;i<=2*k-1;++i) if(d[n]+p[i]<=l) add((n-1)*2*k+i+1,t,1),add(t,(n-1)*2*k+i+1,0);
		int ans=ISAP(s,t);
		if(ans==0) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}