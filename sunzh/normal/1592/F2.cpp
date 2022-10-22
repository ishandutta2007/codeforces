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
char str[510][510];
int a[510][510];
int s,t;
int tot=1;
int head[1010],nxt[1000010],to[1000010],w[1000010];
int tmp[1010];
int dep[1010],gap[1010];
void add(int x,int y,int z){
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y,w[tot]=z;
	nxt[++tot]=head[y],head[y]=tot,to[tot]=x,w[tot]=0;
}
bool bfs(){
	queue<int>Q;Q.push(t);dep[t]=gap[1]=1;
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(!dep[v]){
				dep[v]=dep[u]+1;++gap[dep[v]];Q.push(v);
			}
		}
	}
	return dep[s]>0;
}
int dfs(int x,int mxf){
	if(x==t) return mxf;
	int sum=0;
	for(int &i=tmp[x];i;i=nxt[i]){
		int v=to[i];
		if(dep[v]+1==dep[x]&&w[i]){
			int d=dfs(v,min(mxf,w[i]));
			sum+=d;mxf-=d;w[i]-=d,w[i^1]+=d;
			if(!mxf) return sum;
		}
	}
	if(!--gap[dep[x]]) dep[s]=t+1;
	++gap[++dep[x]];return sum;
}
int maxflow(){
	if(!bfs()) return 0;
	int mxf=0;
	while(dep[s]<=t){
		memcpy(tmp,head,sizeof(head));
		mxf+=dfs(s,0x3f3f3f3f);
	}
	return mxf;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		scanf("%s",str[i]+1);
		for(int j=1;j<=m;++j) if(str[i][j]=='B'){
			a[i][j]^=1;a[i-1][j]^=1;a[i-1][j-1]^=1;a[i][j-1]^=1;
		}
	}
	s=n-1+m,t=s+1;
	for(int i=1;i<n;++i) add(s,i,a[i][m]);
	for(int i=1;i<m;++i) add(i+n-1,t,a[n][i]);
	int ans=0;for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) ans+=a[i][j];
	for(int i=1;i<n;++i){
		for(int j=1;j<m;++j){
			add(i,j+n-1,a[i][j]);
		}
	}
	int f=maxflow();
	// printf("%d %d\n",ans,f);
	printf("%d\n",ans-f-(a[n][m]&&(f&1))+(a[n][m]==0&&(f&1)));
}