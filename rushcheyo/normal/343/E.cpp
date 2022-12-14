#include<bits/stdc++.h>
using namespace std;
const int N=205,M=1005,INF=1000000000;
int n,m,tot=1,nxt[4*M],fst[N],to[4*M],cap[4*M],f[4*M],cur[N],h[N],g[N][N],q[N],p[N],sum,ans[N],ed;
bool v[N];
void adde(int u,int v,int w){
	nxt[++tot]=fst[u];fst[u]=tot;to[tot]=v;cap[tot]=w;
	nxt[++tot]=fst[v];fst[v]=tot;to[tot]=u;cap[tot]=0;
}
bool bfs(int S,int T){
	for(int i=1;i<=n;i++)cur[i]=fst[i],h[i]=-1;
	static int q[N];
	int l=0,r=0;
	q[r++]=S;
	h[S]=0;
	while(l<r){
		int u=q[l++];
		for(int i=fst[u];i;i=nxt[i])
			if(f[i]>0&&h[to[i]]==-1){
				h[to[i]]=h[u]+1;
				if(to[i]==T)return 1;
				q[r++]=to[i];
			}
	}
	return 0;
}
int aug(int u,int T,int fl){
	if(u==T||!fl)return fl;
	int used=0;
	for(int i=cur[u];i;i=nxt[i])
		if(f[i]>0&&h[to[i]]==h[u]+1){
			int t=aug(to[i],T,min(fl-used,f[i]));
			if(f[i]-=t)cur[u]=i;
			f[i^1]+=t;
			if((used+=t)==fl)break;
		}
	if(!used)h[u]=-1;
	return used;
}
int maxflow(int S,int T){
	for(int i=2;i<=tot;i++)f[i]=cap[i];
	int ans=0;
	while(bfs(S,T))ans+=aug(S,T,INF);
	bfs(S,T);
	return ans;
}
void build(int l,int r){
	if(l==r)return;
	int tmp=maxflow(q[l],q[r]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(h[i]==-1^h[j]==-1)g[i][j]=g[j][i]=min(g[i][j],tmp);
	int tl=l-1,tr=r+1;
	for(int i=l;i<=r;i++)
		if(h[q[i]]==-1)p[++tl]=q[i];
		else p[--tr]=q[i];
	for(int i=l;i<=r;i++)q[i]=p[i];
	build(l,tl);
	build(tr,r);
}
void solve(int l,int r){
	if(l==r){ans[++ed]=q[l];return;}
	int mn=q[l+1];
	for(int i=l+2;i<=r;i++)
		if(g[q[l]][q[i]]<g[q[l]][mn])mn=q[i];
	sum+=maxflow(q[l],mn);
	int tl=l-1,tr=r+1;
	for(int i=l;i<=r;i++)
		if(h[q[i]]==-1)p[++tl]=q[i];
		else p[--tr]=q[i];
	for(int i=l;i<=r;i++)q[i]=p[i];
	solve(l,tl);
	solve(tr,r);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		adde(u,v,w);
		adde(v,u,w);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)g[i][j]=INF;
	for(int i=1;i<=n;i++)q[i]=i;
	random_shuffle(q+1,q+1+n);
	build(1,n);
	solve(1,n);
	printf("%d\n",sum);
	for(int i=1;i<=n;i++)printf("%d%c",ans[i]," \n"[i==n]);
	return 0;
}