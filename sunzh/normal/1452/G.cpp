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
#define pow powl
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
int n;
vector<int>vec[200010];
int siz[200010],maxs[200010];
int dis[200010];
int dep[200010];
bool vis[200010];
queue<int>Q;
int rt;
int ans[200010];
int sum;
int w[200010];
void getsize(int x,int f){
	siz[x]=1;
	maxs[x]=0;
//	printf("X:%d\n",x);
	for(int v:vec[x]){
		if(vis[v]||v==f) continue ;
		getsize(v,x);siz[x]+=siz[v];
	}
}
void getrt(int x,int f){
	for(int v:vec[x]){
		if(vis[v]||v==f) continue ;
		getrt(v,x);
		maxs[x]=max(maxs[x],siz[v]);
	}
	maxs[x]=max(maxs[x],sum-siz[x]);
	if(maxs[x]<maxs[rt]) rt=x;
}

void dfs(int x,int f){
	dep[x]=dep[f]+1;
//	if(dis[x]==0) return ;
	if(dis[x]-dep[x]>=0) w[min(sum,dis[x]-dep[x])]=max(w[min(sum,dis[x]-dep[x])],dis[x]);
	for(int v:vec[x]){
		if(v==f||vis[v]) continue ;
		dfs(v,x);
	}
}
void getans(int x,int f){
//	if(dis[x]==0) return ;
	ans[x]=max(ans[x],w[1+dep[x]]);
	for(int v:vec[x]){
		if(v==f) continue ;
		if(vis[v]) continue ;
		getans(v,x);
	}
}
void calc(int x){
//	printf("X:%d\n",x);
	for(int i=0;i<=sum+1;++i) w[i]=0;
	dfs(x,0);
	for(int i=sum-1;i>=0;--i) w[i]=max(w[i],w[i+1]);
	ans[x]=max(ans[x],w[1]);
	for(int v:vec[x]){
		if(vis[v]) continue ;
		getans(v,x);
	}
}

void solve(int x){
//	printf("x:%d\n",x);
	calc(x);
	vis[x]=1;
	for(int v:vec[x]){
		if(vis[v]) continue ;
		rt=0;
		getsize(v,v);sum=siz[v];
		getrt(v,v);solve(rt);
	}
}
int main(){
	dep[0]=-1;
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		vec[u].pb(v),vec[v].pb(u);
	}
	memset(dis,-1,sizeof(dis));
	int k=read();
	for(int i=1;i<=k;++i){
		int u=read();
		dis[u]=0;Q.push(u);
	}
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		for(int v:vec[u]){
			if(dis[v]==-1){
				dis[v]=dis[u]+1;
				Q.push(v);
			}
		}
	}
	maxs[0]=0x3f3f3f3f;rt=0;
	getsize(1,1);sum=siz[1];
	getrt(1,1);
	solve(rt);
//	if(n>=1000) printf("%d %d\n",dis[317],ans[317]);
	for(int i=1;i<=n;++i) printf("%d ",dis[i]==0?0:max(ans[i],dis[i]));
	return 0;
}