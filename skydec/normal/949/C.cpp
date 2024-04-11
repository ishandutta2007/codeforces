#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<iostream>
#include<assert.h>
#include<queue>
#include<string>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;
const int N=110000;
int n,m,h;
int d[N];
int c[N][2];
int head[N],np[N<<1],p[N<<1],tot;
void add(int a,int b){
	++tot;p[tot]=b;np[tot]=head[a];head[a]=tot;
}
int fa[N];
int get(int x){
	if(x==fa[x])return x;
	return fa[x]=get(fa[x]);
}
int dfn[N],low[N],vis[N];
int dftot;
bool instk[N];int stk[N],t;
void tarjan(int x){
	dfn[x]=low[x]=++dftot;
	vis[x]=1;
	instk[x]=1;stk[++t]=x;
	for(int u=head[x];u;u=np[u]){
		if(!vis[p[u]]){
			tarjan(p[u]);
			low[x]=min(low[x],low[p[u]]);
		}
		else{
			if(instk[p[u]])low[x]=min(low[x],dfn[p[u]]);
		}
	}
	if(low[x]==dfn[x]){
		while(1){
			int y=stk[t--];
			instk[y]=0;
			fa[get(x)]=get(y);
			if(y==x)break;
		}
	}
}
int du[N];
int sz[N];
int main(){
	scanf("%d%d%d",&n,&m,&h);
	rep(i,1,n)fa[i]=i;
	rep(i,1,n)scanf("%d",&d[i]);
	rep(i,1,m){
		int a,b;scanf("%d%d",&a,&b);
		if((d[a]+1)%h==d[b])add(a,b);
		if((d[b]+1)%h==d[a])add(b,a);
	}
	rep(i,1,n)if(!vis[i])tarjan(i);
	rep(x,1,n)for(int u=head[x];u;u=np[u])if(get(x)!=get(p[u]))++du[get(x)];
	rep(i,1,n)sz[get(i)]++;
	int ans=n;
	int p=0;
	rep(i,1,n)if(get(i)==i)if(du[i]==0){
		if(sz[i]<ans){
			ans=sz[i];
			p=i;
		}
	}
	if(!p){
		printf("%d\n",n);
		rep(i,1,n)printf("%d ",i);puts("");
	}
	else{
		printf("%d\n",ans);
		rep(i,1,n)if(get(i)==p)printf("%d ",i);puts("");
	}
	return 0;
}