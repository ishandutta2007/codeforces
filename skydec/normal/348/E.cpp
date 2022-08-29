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
const int MAXN=310000;
struct LCA_System{
	vector<int>p[MAXN];
	int fa[21][MAXN];
	int n;int dep[MAXN];
	void dfs(int x,int y){
		//printf("_%d %d\n",x,y);
		dep[x]=dep[y]+1;
		rep(j,0,p[x].size()-1)if(p[x][j]!=y){
			fa[0][p[x][j]]=x;
			dfs(p[x][j],x);
		}
	}
	void init(){
		dfs(1,0);
		rep(i,1,20)rep(j,1,n)
		fa[i][j]=fa[i-1][fa[i-1][j]];
	}
	inline int lca(int x,int y){
		if(dep[x]<dep[y])swap(x,y);
		per(i,20,0)if((1<<i)&(dep[x]-dep[y]))x=fa[i][x];
		if(x==y)return x;
		per(i,20,0)if(fa[i][x]^fa[i][y]){
			x=fa[i][x];
			y=fa[i][y];
		}
		//printf("_%d %d\n",x,fa[0][x]);
		return fa[0][x];
	}
}gt;
int n,m;vector<pii>p[MAXN];bool fuck[MAXN];
struct info{
	int far,lca;
	inline info(int _far=0,int _lca=0){far=_far;lca=_lca;}
}up[MAXN],down[MAXN];
int q[MAXN],fa[MAXN];
int tmp[MAXN];int way[MAXN];
info suf[MAXN],pre[MAXN];
int tag[MAXN];int sum[MAXN];
void DFS(int x,int y){
	rep(i,0,p[x].size()-1)if(p[x][i].fi^y){
		DFS(p[x][i].fi,x);
		tag[x]+=tag[p[x][i].fi];
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		int v;scanf("%d",&v);fuck[v]=1;
	}
	rep(i,1,n-1){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		p[a].pb(pii(b,c));
		p[b].pb(pii(a,c));
		gt.p[a].pb(b);
		gt.p[b].pb(a);
	}
	gt.n=n;
	gt.init();
	q[q[0]=1]=1;
	rep(i,1,q[0]){
		int x=q[i];
		rep(j,0,p[x].size()-1)if(p[x][j].fi!=fa[x]){
			q[++q[0]]=p[x][j].fi;
			fa[p[x][j].fi]=x;
		}
	}
	per(i,q[0],1){
		int x=q[i];
		if(fuck[x])down[x]=info(0,x);
		else down[x]=info(0,0);
		rep(j,0,p[x].size()-1)if(p[x][j].fi!=fa[x]){
			int y=p[x][j].fi;int w=p[x][j].se;
			if(down[y].lca){
				if(down[y].far+w>down[x].far){
					down[x]=down[y];
					down[x].far+=w;
				}
				else if(down[y].far+w==down[x].far){
					down[x].lca=x;
				}
			}
		}
		//printf("___%d %d %d\n",x,down[x].lca,down[x].far);
	}
	rep(i,1,q[0]){
		int x=q[i];
		if(fuck[x]&&!up[x].lca)up[x]=info(0,x);
		
		//printf("gt_%d %d %d\n",x,up[x].lca,up[x].far);
		
		int N=0;
		rep(j,0,p[x].size()-1)if(p[x][j].fi!=fa[x]){tmp[++N]=p[x][j].fi;way[N]=p[x][j].se;}
		
		pre[1]=down[tmp[1]];
		if(pre[1].lca)pre[1].far+=way[1];
		rep(j,2,N){
			pre[j]=down[tmp[j]];
			if(pre[j].lca)pre[j].far+=way[j];
			//if(x==6)printf("_>< %d %d %d\n",j,pre[j].lca,pre[j].far);
			if(pre[j-1].lca){
				if(pre[j-1].far==pre[j].far)pre[j].lca=x;
				else if(pre[j-1].far>pre[j].far)pre[j]=pre[j-1];
			}
		}
		
		suf[N]=down[tmp[N]];
		if(suf[N].lca)suf[N].far+=way[N];
		per(j,N-1,1){
			suf[j]=down[tmp[j]];
			if(suf[j].lca)suf[j].far+=way[j];
			if(suf[j+1].lca){
				if(suf[j+1].far==suf[j].far)suf[j].lca=x;
				else if(suf[j+1].far>suf[j].far)suf[j]=suf[j+1];
			}
		}
		
		rep(j,1,N){
			int y=tmp[j];
			up[y]=up[x];
			if(up[y].lca)up[y].far+=way[j];
			if(j>1){
				if(pre[j-1].lca&&pre[j-1].far+way[j]>up[y].far){
					up[y]=pre[j-1];
					up[y].far+=way[j];
				}
				else if(pre[j-1].lca&&pre[j-1].far+way[j]==up[y].far)
				up[y].lca=x;
			}
			if(j<N){
				if(suf[j+1].lca&&suf[j+1].far+way[j]>up[y].far){
					up[y]=suf[j+1];
					up[y].far+=way[j];
				}
				else if(suf[j+1].lca&&suf[j+1].far+way[j]==up[y].far)
				up[y].lca=x;
			}
		}
	}
	rep(i,1,n)if(fuck[i]){
		if(!fa[i]){
			if(down[i].lca){
				tag[down[i].lca]++;
				tag[i]++;
				tag[fa[gt.lca(i,down[i].lca)]]-=2;
				sum[gt.lca(i,down[i].lca)]--;
			}
		}
		else{
			if(up[i].far==down[i].far){
				sum[i]++;
			}
			else if(up[i].far>down[i].far){tag[up[i].lca]++;tag[i]++;tag[fa[gt.lca(up[i].lca,i)]]-=2;sum[gt.lca(up[i].lca,i)]--;}
			else {
				tag[i]++;
				tag[down[i].lca]++;
				tag[fa[gt.lca(i,down[i].lca)]]-=2;
				sum[gt.lca(i,down[i].lca)]--;
			}
		}
	}
	DFS(1,0);
	rep(i,1,n)sum[i]+=tag[i];
	int ans=-1;int rp=0;
	rep(i,1,n)if(!fuck[i]){
		if(sum[i]>ans){ans=sum[i];rp=1;}
		else if(sum[i]==ans)rp++;
	}
	printf("%d %d\n",ans,rp);
	return 0;
}