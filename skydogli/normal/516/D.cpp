#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
#define MN 100005
#define LL long long
#define mp make_pair
#define x first
#define y second
int n,q;
int fa[MN],rt;
int tag[MN];
LL dep[MN],f[MN];
vector<pair<int,int> >edge[MN];
void dfs(int x){
	for(int i=0;i<edge[x].size();++i){
		int v=edge[x][i].x,w=edge[x][i].y;
		if(fa[x]==v)continue;
		fa[v]=x;dep[v]=dep[x]+w;
		dfs(v);
	}
	if(dep[x]>dep[rt])rt=x;
}
void work(int x,LL tmp){
	f[x]=max(dep[x],tmp);
//	cerr<<"f "<<x<<": "<<f[x]<<endl;
	for(int i=0;i<edge[x].size();++i){
		int v=edge[x][i].x,w=edge[x][i].y;
		if(fa[x]==v)continue;
		if(tag[v])work(v,tmp-w);
		else work(v,tmp+w);
	}
}
int F[MN],siz[MN];
pair<LL,int>v[MN];
int Find(int x){if(F[x]==x)return x;return F[x]=Find(F[x]);}
void Merge(int x,int y){
	int fx=Find(x),fy=Find(y);
	assert(fx!=fy);
	if(siz[fx]<siz[fy])swap(x,y);
	siz[fx]+=siz[fy];
	F[fy]=fx;
}
signed main(){
	n=read();
	for(int i=1;i<n;++i){
		int x=read(),y=read(),z=read();
	//	cerr<<"? "<<x<<" "<<y<<endl;
		edge[x].push_back(mp(y,z));
		edge[y].push_back(mp(x,z));
	}
	dep[1]=0;dfs(1);
	dep[rt]=0;fa[rt]=0;int tmp=rt;dfs(rt);
	swap(tmp,rt);
	int x=tmp;
	while(x){
		tag[x]=1;
		x=fa[x];
	}
	work(rt,dep[tmp]);
	int RT=1;
	for(int i=1;i<=n;++i){
		if(f[RT]>f[i])RT=i;
		v[i]=mp(f[i],i);
	}
	sort(v+1,v+1+n);
	dep[RT]=0;fa[RT]=0;dfs(RT);
//	cerr<<"RT: "<<RT<<endl;
	q=read();
	while(q--){
		int len=read();
		int r=n,ans=0;
		for(int i=1;i<=n;++i)F[i]=i,siz[i]=1;
		for(int l=n;l;--l){
			int x=v[l].y;
			for(int i=0;i<edge[x].size();++i){
				int v=edge[x][i].x;
				if(fa[x]==v)continue;
				Merge(x,v);
			}
			while(v[r].x-v[l].x>len){siz[Find(v[r].y)]--;r--;}
			ans=max(ans,siz[Find(v[l].y)]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}