#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 300005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
int n,m,q;
int a[MN],C[MN];
vector<int>e[MN];
struct tree{
	int ls,rs;
	int sum;
}T[MN<<5];
int root[MN],cnt;
int fa[MN],F[MN][21],dep[MN];
#define mid (l+r>>1)
void Ins(int &x,int l,int r,int loc,int v){
	T[++cnt]=T[x];x=cnt;
	T[x].sum^=v;
	if(l==r)return;
	if(loc<=mid)Ins(T[x].ls,l,mid,loc,v);
	else Ins(T[x].rs,mid+1,r,loc,v);
}
int query(int a,int b,int c,int d,int l,int r,int S,int e){
	int v=T[a].sum^T[b].sum^T[c].sum^T[d].sum;
	if(!v||l>e||r<S)return -1;
	if(l==r)return l;
	v=query(T[a].ls,T[b].ls,T[c].ls,T[d].ls,l,mid,S,e);
	if(v!=-1)return v;
	return query(T[a].rs,T[b].rs,T[c].rs,T[d].rs,mid+1,r,S,e);
}
void dfs(int x){
	root[x]=root[fa[x]];
	Ins(root[x],1,n,a[x],C[a[x]]);
	F[x][0]=fa[x];
	for(int i=1;i<=18;++i)F[x][i]=F[F[x][i-1]][i-1];
	for(int i=0;i<e[x].size();++i){
		int v=e[x][i];
		if(fa[x]==v)continue;
		fa[v]=x;dep[v]=dep[x]+1;
		dfs(v);	
	}
}
int LCA(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=18;i>=0;--i)
		if(dep[F[x][i]]>=dep[y])x=F[x][i];
	if(x==y)return x;
	for(int i=18;i>=0;--i)
		if(F[x][i]!=F[y][i])x=F[x][i],y=F[y][i];
	return F[x][0];
}
signed main(){
	n=read();q=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)C[i]=(int)rand()<<32|rand();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	root[0]=1;cnt=1;
	dep[1]=1;dfs(1);
	for(int i=1;i<=q;++i){
		int u=read(),v=read(),l=read(),r=read();
		int g=LCA(u,v);
	//	cerr<<"g: "<<g<<endl;
		printf("%lld\n",query(root[u],root[v],root[g],root[fa[g]],1,n,l,r));
	}
	return 0;
}