#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
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
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n;
int a[3010];
int S,T;
int tot=1;
int head[3010],nxt[200010],to[200010],w[200010];
void add(int x,int y,int z){
//	printf("z:%d\n",z);
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y,w[tot]=z;
}
int depth[3010],gap[3010];
int lst[110];
int ans=0;
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
//	printf("%d\n",depth[s]);
	if(depth[s]==0) return 0;
	return 1;
}
int dfs(int x,int maxf){
//	printf("%d %d\n",x,maxf);
	if(x==T) return maxf;
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
	if(--gap[depth[x]]==0) depth[S]=n+4;
	++gap[++depth[x]];
	return sum;
}
int ISAP(int s,int t){
	int maxflow=0;
	if(bfs(s,t)==0) return 0;
	while(depth[s]<=n+3) {
		maxflow+=dfs(s,0x3f3f3f3f);
	}
//	printf("%d\n",maxflow);
	return maxflow;
}

int main(){
	n=read();S=0,T=n+1;
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i){
		int x=read();
		if(x>=0) add(S,i,x),add(i,S,0);
		else add(i,T,-x),add(T,i,0);
		ans+=max(0,x);
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=100;++j){
			if(a[i]%j==0){
				if(lst[a[i]/j]){
//					printf("i:%d,%d\n",i,a[i]/j);
					add(i,lst[a[i]/j],0x3f3f3f3f);
					add(lst[a[i]/j],i,0);
				}
			}
		}
		lst[a[i]]=i;
	}
	printf("%d\n",ans-ISAP(S,T));
	return 0;
}