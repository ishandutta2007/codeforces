#include<bits/stdc++.h>
using namespace std;
#define MN 200005
#define int long long
int n,m,deg[MN];
string ch[MN];
vector<int>edge[MN];
#define id hhakioi
int id(int x,int y){
	return (x-1)*m+y;
}
void add(int a,int b,int x){
	if(a<1||a>n||b<1||b>m)return;
	edge[id(a,b)].push_back(x);
	deg[x]++;
}
int cnt,siz[MN],dfn[MN],fa[MN];
void dfs(int x){
	siz[x]=1;dfn[x]=++cnt;
	for(int i=0;i<edge[x].size();++i){
		int v=edge[x][i];
		if(fa[x]==v)continue;
		fa[v]=x;
		dfs(v);
		siz[x]+=siz[v];
	}
}
struct data{
	int x,l,r,op;
	data(int X=0,int L=0,int R=0,int O=0){
		x=X;l=L;r=R;op=O;
	}
	bool friend operator <(data a,data b){
		return a.x<b.x;
	}
}Q[MN<<1];
int tot;
void ADD(int a,int b,int c,int d){	
	Q[++tot]=data(a,b,d,1);
	Q[++tot]=data(c+1,b,d,-1);
}
int sum[MN<<2],tag[MN<<2];
#define Ls (x<<1)
#define Rs (x<<1|1)
#define mid ((l+r)>>1)
void pushup(int x,int l,int r){
	if(tag[x])sum[x]=r-l+1;
	else 
		if(l!=r)sum[x]=sum[Ls]+sum[Rs];
		else sum[x]=0;
}
void change(int x,int l,int r,int b,int e,int v){
	if(l>e||r<b)return;
	if(b<=l&&r<=e){
		tag[x]+=v;
		pushup(x,l,r);
	//	cerr<<"chg: "<<l<<" "<<r<<" "<<sum[x]<<endl;
		return;
	}
	if(b<=mid)change(Ls,l,mid,b,e,v);
	if(e>mid) change(Rs,mid+1,r,b,e,v);
	pushup(x,l,r);
//	cerr<<"? "<<l<<" "<<r<<" "<<sum[x]<<endl;
}
signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i){
		cin>>ch[i];ch[i]=" "+ch[i];
		for(int j=1;j<=m;++j){
			if(ch[i][j]=='L')add(i,j+2,id(i,j));
			if(ch[i][j]=='R')add(i,j-2,id(i,j));
			if(ch[i][j]=='U')add(i+2,j,id(i,j));
			if(ch[i][j]=='D')add(i-2,j,id(i,j));
		}
	}
	for(int i=1;i<=n*m;++i)
		if(!deg[i])dfs(i);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			if(ch[i][j]=='L')
				ADD(dfn[id(i,j)],dfn[id(i,j+1)],dfn[id(i,j)]+siz[id(i,j)]-1,dfn[id(i,j+1)]+siz[id(i,j+1)]-1);
			if(ch[i][j]=='U')
				ADD(dfn[id(i,j)],dfn[id(i+1,j)],dfn[id(i,j)]+siz[id(i,j)]-1,dfn[id(i+1,j)]+siz[id(i+1,j)]-1);
			if(ch[i][j]=='R')
				ADD(dfn[id(i,j)],dfn[id(i,j-1)],dfn[id(i,j)]+siz[id(i,j)]-1,dfn[id(i,j-1)]+siz[id(i,j-1)]-1);
			if(ch[i][j]=='D')
				ADD(dfn[id(i,j)],dfn[id(i-1,j)],dfn[id(i,j)]+siz[id(i,j)]-1,dfn[id(i-1,j)]+siz[id(i-1,j)]-1);
		}
	assert(tot<=n*m*2);
	assert(cnt==n*m);
	sort(Q+1,Q+1+tot);
	long long ans=0;
	for(int i=1;i<=tot;++i){
		change(1,1,cnt,Q[i].l,Q[i].r,Q[i].op);
		if(Q[i].x!=Q[i+1].x)ans=ans+1ll*(Q[i+1].x-Q[i].x)*sum[1];
	}
	printf("%lld\n",ans/2);
	return 0;
}