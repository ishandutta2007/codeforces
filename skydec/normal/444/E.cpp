#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int inf=23333333;
const int N=15005;int n;
inline int Min(const int &a,const int &b){if(a<b)return a;return b;}
inline int Max(const int &a,const int &b){if(a>b)return a;return b;}
int head[N*2],p[N*4],np[N*4],flow[N*4];int q[N*4],dis[N*4],tot=1;int S=0;int T=12005;
inline void link(const int &u,const int &v,const int &w){
	tot++;p[tot]=v;np[tot]=head[u];head[u]=tot;flow[tot]=w;
	tot++;p[tot]=u;np[tot]=head[v];head[v]=tot;flow[tot]=0;
}
int dinic(int x,int fl){
	if(x==T)return fl;
	int ret=0;
	for(int u=head[x];u;u=np[u])if(dis[p[u]]==dis[x]+1&&flow[u]){
		int rp=dinic(p[u],Min(fl,flow[u]));
		flow[u]-=rp;flow[u^1]+=rp;
		ret+=rp;fl-=rp;
	}
	if(!ret)dis[x]=-1;
	return ret;
}
inline int BFS(){
	memset(dis,-1,sizeof dis);q[q[0]=1]=S;dis[S]=0;
	rep(i,1,q[0]){
		int x=q[i];
		for(int u=head[x];u;u=np[u])if(dis[p[u]]==-1&&flow[u]){
			dis[p[u]]=dis[x]+1;
			q[++q[0]]=p[u];
		}
	}
	return dis[T];
}
int fa[N];int id[N],u[N],v[N],w[N],xx[N],yy[N];
inline int get(int x){
	if(x==fa[x])return x;
	fa[x]=get(fa[x]);
	return fa[x];
}
inline bool cmp(const int &a,const int &b){return w[a]<w[b];}
int solve(){
	int bo=n;
	rep(i,1,n){
		link(S,i*2,1);
		int dd;scanf("%d",&dd);
		link(i*2+1,T,dd);
		fa[i]=i;
	}
	rep(i,1,n-1){
		int X=get(u[id[i]]);
		int Y=get(v[id[i]]);
		fa[++bo]=bo;
		xx[id[i]]=X;yy[id[i]]=Y;
		link(X*2,bo*2,inf);link(Y*2,bo*2,inf);
		link(bo*2+1,X*2+1,inf);link(bo*2+1,Y*2+1,inf);
		fa[X]=bo;fa[Y]=bo;
	}
	int ans=0;
	per(i,n-1,1){
		link(xx[id[i]]*2,yy[id[i]]*2+1,inf);
		link(yy[id[i]]*2,xx[id[i]]*2+1,inf);
		while(BFS()!=-1)ans+=dinic(S,inf);
		if(ans==n)return w[id[i]];
	}
}
int main(){
	scanf("%d",&n);
	if(n==1){
		printf("%d\n",0);
		return 0;
	}
	rep(i,1,n-1){
		id[i]=i;
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	}
	sort(id+1,id+1+n-1,cmp);
	printf("%d\n",solve());
	return 0;
}