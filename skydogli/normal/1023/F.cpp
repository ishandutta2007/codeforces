#include<bits/stdc++.h>
using namespace std;
#define inf 1e18
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
#define MN 1000005
struct data{
	int a,b,c;
	bool friend operator<(data a,data b){
		return a.c<b.c;
	}
	data(int A=0,int B=0,int C=0){a=A;b=B;c=C;}
}w[MN];
int F[MN];
int Find(int a){if(a==F[a])return a;return F[a]=Find(F[a]);}
vector<int>G[MN],edge[MN];
int n,m,k,cnt,dep[MN],fa[MN];
int tag[MN],Max[MN];
void build(){	
	sort(w+1,w+1+cnt);
	for(int i=1;i<=n;++i)F[i]=i;
	for(int i=1;i<=cnt;++i){
		int fx=Find(w[i].a),fy=Find(w[i].b);
		if(fx==fy)continue;
		F[fx]=fy;
		G[w[i].a].push_back(w[i].b);
		G[w[i].b].push_back(w[i].a);
	}
}
void dfs(int x){
	for(int i=0;i<G[x].size();++i){
		int v=G[x][i];
		if(fa[x]==v)continue;
		fa[v]=x;dep[v]=dep[x]+1;
		dfs(v);
	}
}
signed main(){
	n=read();k=read();m=read();
	for(int i=1;i<=k;++i){
		int x=read(),y=read();
		w[++cnt]=data(x,y,-inf);
	//	edge[x].push_back(mp(y,-inf));
	//	edge[y].push_back(mp(x,-inf));
	}
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),W=read();
		w[++cnt]=data(u,v,W);
	}
	build();
	dep[1]=1;dfs(1);
	for(int i=1;i<=n;++i){
		F[i]=i;
	//	cerr<<"fk "<<i<<": "<<fa[i]<<endl;
	}
	for(int i=1;i<=k;++i){
		if(fa[w[i].a]==w[i].b)tag[w[i].a]=i;
		else tag[w[i].b]=i;
		Max[i]=1e18;
	}
	for(int i=k+1;i<=cnt;++i){
		int x=w[i].a,y=w[i].b;
		while(x!=y){
			if(dep[x]<dep[y])swap(x,y);
			if(Find(x)==x){
				Max[tag[x]]=w[i].c;
				F[x]=Find(fa[x]);
			}
			x=Find(x);
		}
	}
	int ans=0;
	for(int i=1;i<=k;++i){
		if(Max[i]>1e17){puts("-1");return 0;}
		ans+=Max[i];
	}
	printf("%lld\n",ans);
	return 0;
}