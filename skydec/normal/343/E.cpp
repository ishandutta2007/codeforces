#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
typedef set<int>::iterator it;
const int N=205;
const int M=10005;
int head[N],next[M],flow[M],p[M];int tot;
struct edge{int u,v,w;}ori[M];int n,m;int cho;
struct Ans{int u,v,w;}ans[N];int rp=0;
int now[N],tmp[N];int vis[N];
int S,T;int dis[N];
inline void link(int a,int b,int c){
	tot++;p[tot]=b;next[tot]=head[a];head[a]=tot;flow[tot]=c;
	tot++;p[tot]=a;next[tot]=head[b];head[b]=tot;flow[tot]=0;
}
int q[N];
inline int BFS(){
	memset(dis,-1,sizeof dis);
	dis[S]=0;q[q[0]=1]=S;
	rep(i,1,q[0]){
		int x=q[i];
		for(int u=head[x];u;u=next[u])if(dis[p[u]]==-1&&flow[u]){
			dis[p[u]]=dis[x]+1;
			q[++q[0]]=p[u];
		}
	}
	return dis[T];
}
int dinic(int x,int fl){
	if(x==T)return fl;
	int res=0;
	for(int u=head[x];u;u=next[u])if(dis[p[u]]==dis[x]+1&&flow[u]){
		int ret=dinic(p[u],min(flow[u],fl));
		fl-=ret;flow[u]-=ret;flow[u^1]+=ret;res+=ret;
	}
	if(!res)dis[x]=-1;
	return res;
}
int max_flow(int xxx1,int xxx2){
	S=xxx1;T=xxx2;
	tot=1;
	memset(head,0,sizeof head);
	memset(next,0,sizeof next);
	memset(p,0,sizeof p);
	memset(flow,0,sizeof flow);
	rep(i,1,m){
		link(ori[i].u,ori[i].v,ori[i].w);
		link(ori[i].v,ori[i].u,ori[i].w);
	}
	int res=0;
	while(BFS()!=-1){
		int ret=dinic(S,1e9);
		while(ret){
			res+=ret;
			ret=dinic(S,1e9);
		}
	}
	return res;
}
void div(int x){
	vis[x]=cho;
	for(int u=head[x];u;u=next[u])if(flow[u]&&vis[p[u]]!=cho)div(p[u]);
}
int work(int l,int r){
	if(l==r)return now[l];
	int ww=max_flow(now[l],now[r]);
	int ll=l;int rr=r;
	cho++;div(now[l]);
	rep(i,l,r)if(vis[now[i]]==cho)tmp[ll++]=now[i];
	else tmp[rr--]=now[i];
	ll--;rr++;
	rep(i,l,r)now[i]=tmp[i];
	int a1=work(l,ll);
	int a2=work(rr,r);
	ans[++rp]=(Ans){a1,a2,ww};
	return now[l];
}
vector<pii>biu[N];
pii mi;int fr;
int c2=0;int v2[N];
void find_min(int x){
	vis[x]=cho;
	rep(j,0,biu[x].size()-1){
		if(v2[biu[x][j].se]!=c2)continue;
		if(vis[biu[x][j].se]==cho)continue;
		if(biu[x][j]<mi){
			mi=biu[x][j];
			fr=x;
		}
		find_min(biu[x][j].se);
	}
}
void div_2(int x){
	vis[x]=cho;
	rep(j,0,biu[x].size()-1){
		if(v2[biu[x][j].se]!=c2)continue;
		if(vis[biu[x][j].se]==cho)continue;
		div_2(biu[x][j].se);
	}
}
void getans(int l,int r){
	//printf("%d %d\n",l,r);
	//system("pause");
	if(l==r){
		printf("%d ",now[l]);
		return;
	}
	mi=pii(1e9,0);
	c2++;
	rep(i,l,r)v2[now[i]]=c2;
	cho++;
	find_min(now[l]);
	cho++;
	vis[fr]=vis[mi.se]=cho;
	//printf("_%d %d %d\n",fr,mi.se,mi.fi);
	div_2(fr);
	vis[mi.se]=-1;
	int ll=l;int rr=r;
	rep(i,l,r)if(vis[now[i]]==cho)tmp[ll++]=now[i];else tmp[rr--]=now[i];
	ll--;rr++;
	rep(i,l,r)now[i]=tmp[i];
	getans(l,ll);
	getans(rr,r);
}
void outans(){
	rep(i,1,n)now[i]=i;
	rep(i,1,n-1){
		biu[ans[i].u].pb(pii(ans[i].w,ans[i].v));
		biu[ans[i].v].pb(pii(ans[i].w,ans[i].u));
	}
	getans(1,n);
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m)scanf("%d%d%d",&ori[i].u,&ori[i].v,&ori[i].w);
	rep(i,1,n)now[i]=i;
	work(1,n);
	int res=0;
	rep(i,1,rp)res+=ans[i].w;
	printf("%d\n",res);
	outans();
	return 0;
}