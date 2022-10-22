#include<bits/stdc++.h>
using namespace std;
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 200005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector<int>
const int maxn=MN<<6|5;
int frt[MN],grt[MN],Max[maxn],ls[maxn],rs[maxn],cnt;
int ans,n,m,a[MN],fa[MN],v[MN],N;
vc e[MN];
void pushup(int x){
	Max[x]=max(Max[ls[x]],Max[rs[x]]);
}
#define mid ((l+r)>>1)
void Ins(int &x,int l,int r,int loc,int v){
	if(!x)x=++cnt;
	Max[x]=max(Max[x],v);
	if(l==r){return;}
	if(loc<=mid)Ins(ls[x],l,mid,loc,v);
	else Ins(rs[x],mid+1,r,loc,v);
}
int ask(int x,int l,int r,int b,int e){
	if(!x||l>e||r<b)return 0;
	if(b<=l&&r<=e)return Max[x];
	if(e<=mid)return ask(ls[x],l,mid,b,e);
	if(b>mid) return ask(rs[x],mid+1,r,b,e);
	return max(ask(ls[x],l,mid,b,e),ask(rs[x],mid+1,r,b,e));
}
void Merge(int &x,int y,int l,int r){
	if(!x){x=y;return;}
	if(!y)return;
	if(l==r){Max[x]=max(Max[x],Max[y]);return;}
	Merge(ls[x],ls[y],l,mid);
	Merge(rs[x],rs[y],mid+1,r);
	pushup(x);
}
void getans(int x,int y,int l,int r,int lv,int rv){
	if(!x||!y||l==r)return;	
	ans=max(ans,max(Max[ls[x]],lv)+max(rv,Max[rs[y]]));	
	getans(ls[x],ls[y],l,mid,lv,max(rv,Max[rs[y]]));
	getans(rs[x],rs[y],mid+1,r,max(lv,Max[ls[x]]),rv);
}
void dfs(int x){
	Ins(frt[x],1,N,a[x],1);
	Ins(grt[x],1,N,a[x],1);
	int val=1;
	for(int i=0;i<e[x].size();++i){
		int v=e[x][i];
		if(fa[x]==v)continue;
		fa[v]=x;dfs(v);
		getans(frt[x],grt[v],1,N,0,0);
		getans(frt[v],grt[x],1,N,0,0);
		Merge(frt[x],frt[v],1,N);
		Merge(grt[x],grt[v],1,N);
		Ins(frt[x],1,N,a[x],ask(frt[x],1,N,1,a[x]-1)+1);
		Ins(grt[x],1,N,a[x],ask(grt[x],1,N,a[x]+1,N)+1);
	}
}
signed main(){
	n=read();
	for(int i=1;i<=n;++i)v[i]=a[i]=read();
	sort(v+1,v+1+n);N=unique(v+1,v+1+n)-v-1;
	for(int i=1;i<=n;++i){
		a[i]=lower_bound(v+1,v+1+N,a[i])-v;
	}
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		e[u].pb(v);e[v].pb(u);
	}
	dfs(1);
//	cerr<<"ans: "<<ans<<endl;
	ans=max(ans,Max[frt[1]]);
	ans=max(ans,Max[grt[1]]);
	cout<<ans<<endl;
	return 0;
}