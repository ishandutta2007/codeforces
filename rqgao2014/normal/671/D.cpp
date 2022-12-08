#include<bits/stdc++.h>
#define ls (k<<1)
#define rs (k<<1|1)
#define ll long long
#define pb push_back
using namespace std;

const int N=300005;
const ll inf=1ll<<60,bor=1ll<<50;
struct node{int u,v,c;}b[N];
struct edge{int to,next;}p[N*2];
int n,m,tot,head[N],a[N],l[N],r[N],tmp[N];
ll dp[N],minx[N<<3],flag[N<<3];
bool vis[N],isok=1;
vector<int> ins[N],del[N];
inline bool operator < (const node &x,const node &y){
	return a[x.u]<a[y.u];
}
inline void pushdown(int l,int r,int k){
	if(!flag[k]) return;
	flag[ls]+=flag[k];
	flag[rs]+=flag[k];
	minx[ls]+=flag[k];
	minx[rs]+=flag[k];
	flag[k]=0;
}
inline void build(int l,int r,int k){
	minx[k]=inf;
	if(l==r) return;
	int mid=l+r>>1;
	build(l,mid,ls);build(mid+1,r,rs);
}
inline void change(int l,int r,int x,int y,int k,ll b){
	pushdown(l,r,k);
	if(l==x&&r==y){
		minx[k]+=b;flag[k]+=b;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) change(l,mid,x,min(mid,y),ls,b);
	if(y>mid) change(mid+1,r,max(mid+1,x),y,rs,b);
	minx[k]=min(minx[ls],minx[rs]);
}
inline void change1(int l,int r,int x,int k,ll b){
	pushdown(l,r,k);
	if(l==r){
		minx[k]=b;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) change1(l,mid,x,ls,b); else change1(mid+1,r,x,rs,b);
	minx[k]=min(minx[ls],minx[rs]);	
}
inline ll get(int l,int r,int x,int y,int k){
	pushdown(l,r,k);
	if(l==x&&r==y) return minx[k];
	int mid=l+r>>1;ll res=inf;
	if(x<=mid) res=min(res,get(l,mid,x,min(mid,y),ls));
	if(y>mid) res=min(res,get(mid+1,r,max(mid+1,x),y,rs));
	return res;
}
inline void add(int x,int y){
	p[++tot].to=y;p[tot].next=head[x];head[x]=tot;
	p[++tot].to=x;p[tot].next=head[y];head[y]=tot;
}
inline void dfs(int x){
	vis[x]=1;l[x]=a[x]=++tot;
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		if(vis[y]) continue;
		dfs(y);
	}
	r[x]=tot;
}
inline void get(int x){
	vis[x]=1;
	ll tmp=0;
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		if(vis[y]) continue;
		get(y);tmp+=dp[y];
	}
	for(int i=0;i<ins[x].size();i++){
		int t=ins[x][i];
		change1(1,m,t,1,b[t].c);
	}
	for(int i=0;i<del[x].size();i++){
		int t=del[x][i];
		change1(1,m,t,1,inf);
	}
	change(1,m,l[x],r[x],1,tmp);
	dp[x]=get(1,m,l[x],r[x],1);
	if(dp[x]<=bor) change(1,m,l[x],r[x],1,-dp[x]); else if(x>1) isok=0;
}
inline bool treedp(){
	build(1,m,1);
	memset(vis,0,sizeof(vis));
	get(1);
	ll ans=0;
	for(int i=head[1];i;i=p[i].next)
		ans+=dp[p[i].to];
	if(isok) cout<<ans<<endl; else puts("-1");
	return 0;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	dfs(1);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&b[i].u,&b[i].v,&b[i].c);
	sort(b+1,b+m+1);
	for(int i=1;i<=m;i++) tmp[i]=a[b[i].u];
	for(int i=1;i<=n;i++){
		l[i]=lower_bound(tmp+1,tmp+m+1,l[i])-tmp;
		r[i]=upper_bound(tmp+1,tmp+m+1,r[i])-tmp-1;
		if(l[i]>r[i]){puts("-1");return 0;}
	}
	for(int i=1;i<=m;i++)
		ins[b[i].u].pb(i),del[b[i].v].pb(i);
	return treedp();
}

/*
6 5
1 2
1 3
3 4
4 5
4 6
2 1 2
3 1 4
4 1 3
5 3 1
6 3 2
*/