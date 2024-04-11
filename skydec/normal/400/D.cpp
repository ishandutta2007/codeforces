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
int n,m,k,bel[MAXN];
int q[MAXN];bool inq[MAXN];
vector<pii>self[MAXN];
int d[505][505];bool vis[MAXN];
void dfs(int x){
	vis[x]=1;
	for(int i=0;i<self[x].size();i++)
	if(self[x][i].se==0&&!vis[self[x][i].fi])dfs(self[x][i].fi);
}
inline bool IsVaild(){
	rep(i,1,k){
		memset(vis,0,sizeof vis);
		int st=0;
		rep(j,1,n)if(bel[j]==i)st=j;
		dfs(st);
		rep(j,1,n)if(!vis[j]&&bel[j]==i)return 0;
	}
	return 1;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);int last=0;
	memset(d,63,sizeof d);
	rep(i,1,k){
		int c;scanf("%d",&c);
		rep(j,last+1,last+c)bel[j]=i;
		last+=c;
	}
	rep(i,1,m){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		if(d[bel[u]][bel[v]]>w)d[bel[u]][bel[v]]=w;
		if(d[bel[v]][bel[u]]>w)d[bel[v]][bel[u]]=w;
		self[u].pb((pii){v,w});
		self[v].pb((pii){u,w});
	}
	if(!IsVaild()){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	rep(i,1,k)d[i][i]=0;
	rep(p,1,k)rep(i,1,k)rep(j,1,k)d[i][j]=min(d[i][j],d[i][p]+d[p][j]);
	rep(i,1,k){
		rep(j,1,k)if(d[i][j]>1000000000)printf("-1 ");else printf("%d ",d[i][j]);
		printf("\n");
	}
	return 0;
}