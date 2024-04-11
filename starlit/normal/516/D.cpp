#include<bits/stdc++.h>
const int N=100005;
using namespace std;
typedef long long ll;
ll F[N],G[N],h[N],now;
int n,m,to[N*2],hd[N*2],ln[N*2],lk[N],cnt=1,
f[N],a[N],st[N],t,mn=1,fa[N],sz[N],va[N];
int u,v,w,ans;
inline void add(int u,int v){
	to[++cnt]=v,hd[cnt]=lk[u],ln[cnt]=w,lk[u]=cnt;
}
void dfs(int x,int y=0){
	for(int s,i=lk[x];i;i=hd[i])
	if(i^y){
		G[s=to[i]]=F[x];
		dfs(s,i^1),F[x]=max(F[x],F[s]+ln[i]);
	}
	t=now=0;
	for(int i=lk[x];i;i=hd[i])
	if(i^y)st[++t]=i;
	for(int s;t;t--)
	s=to[st[t]],G[s]=max(G[s],now),
	now=max(now,F[s]+ln[st[t]]);
}
void dfss(int x,int y=0){
	G[x]=max(G[x],G[to[y]])+ln[y];
	h[x]=max(F[x],G[x]);
	if(h[x]<h[mn])mn=x;
	for(int i=lk[x];i;i=hd[i])
	if(i^y)dfss(to[i],i^1);
}
void ssfd(int x){
	a[cnt++]=x,st[x]=cnt;
	for(int s,i=lk[x];i;i=hd[i])
	if((s=to[i])^f[x])f[s]=x,ssfd(s);
}
int get(int x){
	return fa[x]^x?fa[x]=get(fa[x]):x;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	scanf("%d%d%d",&u,&v,&w),
	add(u,v),add(v,u);
	dfs(1),dfss(1);
	cnt=0,ssfd(mn);
	sort(a,a+n,[](int x,int y){return h[x]^h[y]?h[x]>h[y]:st[x]>st[y];});
	for(scanf("%d",&m);m--;){
		for(int i=1;i<=n;i++)fa[i]=i,sz[i]=va[i]=1;
		scanf("%lld",&now);ans=0;
		for(int i=0,j=0;i<n;i++){
			for(;j<n&&h[a[j]]-h[a[i]]>now;j++)
			va[get(a[j])]--;
			ans=max(ans,va[u=get(a[i])]);
			if(i<n-1){
				v=get(f[a[i]]);
				if(sz[u]<sz[v])swap(u,v);
				fa[v]=u,sz[u]+=sz[v],va[u]+=va[v];
			}
		}printf("%d\n",ans);
	}
}