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
const int N=110000;
struct jab{
	int u,v,w;
	int link,use,pang,pre;
}q[N*20],e[N];int tot;
int n,m;int root;vector<int>p[N];
int in[N],prev[N],dfn[N],low[N],be[N],M;int TAT;bool vis[N];int stack[N];int top;
void tarjan(int x){
	stack[++top]=x;vis[x]=1;
	dfn[x]=low[x]=++TAT;
	for(vector<int>::iterator it=p[x].begin();it!=p[x].end();it++){
		int v=*it;
		if(!dfn[v]){
			tarjan(v);
			if(low[v]<low[x])low[x]=low[v];
		}
		else if(vis[v]){if(dfn[v]<low[x])low[x]=dfn[v];}
	}
	if(low[x]==dfn[x]){
		++M;
		while(1){
			int v=stack[top];
			vis[v]=0;
			be[v]=M;
			top--;
			if(v==x)break;
		}
	}
}
int last[N];
inline void fail(){
	printf("-1\n");
	exit(0);
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		++tot;e[tot].u=u;e[tot].v=v;e[tot].w=w;q[tot]=e[tot];e[tot].link=tot;
	}
	int ret=0;root=1;
	while(1){
		memset(in,63,sizeof in);
		memset(prev,0,sizeof prev);
		TAT=0;M=0;top=0;
		memset(be,0,sizeof be);
		memset(dfn,0,sizeof dfn);
		memset(low,0,sizeof low);
		memset(last,0,sizeof last);
		rep(i,1,n)while(p[i].size())p[i].pop_back();
		rep(i,1,m)if(e[i].u^e[i].v)if(e[i].v!=root)if(e[i].w<in[e[i].v]){
			in[e[i].v]=e[i].w;prev[e[i].v]=i;last[e[i].v]=e[i].link;
		}
	
		
		rep(i,1,n)if(i^root){
			ret+=in[i];
			q[e[prev[i]].link].use++;
			p[e[prev[i]].u].pb(i);
			if(!prev[i])fail();
			
		}
		
		rep(i,1,n)if(!dfn[i])tarjan(i);
		
		if(n==M)break;
		
		rep(i,1,m){
			int v=e[i].v;
			e[i].u=be[e[i].u];
			e[i].v=be[e[i].v];
			
			if(e[i].u^e[i].v){
				e[i].w-=in[v];
				tot++;
				q[tot]=e[i];
				q[tot].use=0;
				q[tot].pang=last[v];
				q[tot].pre=e[i].link;
				e[i].link=tot;
			}
		}
		
		n=M;root=be[root];
	}
	per(i,tot,m+1){
		q[q[i].pre].use+=q[i].use;
		q[q[i].pang].use-=q[i].use;
	}
	printf("%d\n",ret);
	rep(i,1,m)if(q[i].use>0&&q[i].w>0)printf("%d ",i);
	return 0;
}