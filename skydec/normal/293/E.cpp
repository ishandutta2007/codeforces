#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
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
const int MAXN=110000;
int q[MAXN],size[MAXN],dis[MAXN];LL hev[MAXN];
int n,WWW,l;vector<pii>p[MAXN];LL ans;bool vis[MAXN],inq[MAXN];int fa[MAXN];
inline void bfs(int y){
	q[q[0]=1]=y;dis[y]=0;hev[y]=0;inq[y]=1;
	rep(i,1,q[0]){
		int x=q[i];
		rep(j,0,p[x].size()-1){
			int to=p[x][j].fi;
			int w=p[x][j].se;
			if(vis[to]||inq[to])continue;
			inq[to]=1;dis[to]=dis[x]+1;hev[to]=hev[x]+w;
			q[++q[0]]=to;
		}
	}
	rep(i,1,q[0])inq[q[i]]=0;
}
inline int getroot(int y){
	q[q[0]=1]=y;inq[y]=1;fa[y]=0;
	rep(i,1,q[0]){
		int x=q[i];
		rep(j,0,p[x].size()-1){
			int to=p[x][j].fi;
			if(inq[to]||vis[to])continue;
			fa[to]=x;q[++q[0]]=to;inq[to]=1;
		}
	}
	int M1,M2;M1=0;M2=210000000;
	per(i,q[0],1){
		int x=q[i];size[x]=1;
		int Ma=0;
		rep(j,0,p[x].size()-1){
			int to=p[x][j].fi;
			if(fa[x]==to||vis[to])continue;
			size[x]+=size[to];
			if(size[to]>Ma)Ma=size[to];
		}
		if(q[0]-size[x]>Ma)Ma=q[0]-size[x];
		if(Ma<M2){
			M1=x;M2=Ma;
		}
	}
	rep(i,1,q[0])inq[q[i]]=0;
	return M1;
}
inline void bfs1(int y){
	q[q[0]=1]=y;inq[y]=1;
	rep(i,1,q[0]){
		int x=q[i];
		rep(j,0,p[x].size()-1){
			int to=p[x][j].fi;
			if(vis[to]||inq[to])continue;
			inq[to]=1;q[++q[0]]=to;
		}
	}
	rep(i,1,q[0])inq[q[i]]=0;
}
int cnt[MAXN];int ta[MAXN];int cho;
inline bool cmpw(const int &a,const int &b){return hev[a]<hev[b];}
inline void relax(int x){if(ta[x]!=cho){ta[x]=cho;cnt[x]=0;}}
inline void add(int x,int v){
	x++;if(x<=0)return;
	for(;x<=100001;x+=x&-x){
		relax(x);cnt[x]+=v;
	}
}
inline LL ask(int x){
	x++;if(x<=0)return 0;
	LL res=0;
	for(;x;x-=x&-x){
		relax(x);res+=cnt[x];
	}
	return res;
}
inline void work(int x,int v){
	cho++;
	bfs1(x);sort(q+1,q+1+q[0],cmpw);
	int p1=0;
	per(i,q[0],1){
		int x=q[i];
		while(p1<q[0]&&hev[q[p1+1]]+hev[x]<=WWW){
			p1++;add(dis[q[p1]],1);
		}
		ans+=v*1ll*ask(l-dis[x]);
	}
}
void dfs(int y){
	int x=getroot(y);vis[x]=1;bfs(x);work(x,1);
	rep(i,0,p[x].size()-1)if(!vis[p[x][i].fi])work(p[x][i].fi,-1);
	rep(i,0,p[x].size()-1)if(!vis[p[x][i].fi])dfs(p[x][i].fi);
}
int main(){
	scanf("%d%d%d",&n,&l,&WWW);
	rep(i,2,n){
		int x,y;scanf("%d%d",&x,&y);
		p[i].pb(pii(x,y));
		p[x].pb(pii(i,y));
	}
	dfs(1);
	printf("%I64d\n",(ans-n)/2);
	return 0;
}