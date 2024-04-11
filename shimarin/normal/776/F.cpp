#include<bits/stdc++.h>
#define For(i,x,y) for (int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (int i=(x);i<(y);i++)
#define Dow(i,x,y) for (int i=(x);i>=(y);i--)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fil(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
typedef pair<ll,ll> PA;
typedef vector<int> poly;
inline ll read(){
	ll x=0,f=1;char c=getchar();
	while ((c<'0'||c>'9')&&(c!='-')) c=getchar();
	if (c=='-') f=-1,c=getchar();
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}

const int N = 1e5+10;
int n,m,tmp[N],rid[N];
pa ed[N];

int cnt,pos[N],bel[N],nxt[N];
map<pa,poly>id;
poly vec[N];
inline void Add(int x,int y,int z){
	if (x>y) swap(x,y);
	id[mp(x,y)].pb(z);
}
inline void Build(pa *e){
	For(i,1,m) if (e[i].fi>e[i].se) swap(e[i].fi,e[i].se);
	sort(e+1,e+1+m,[](pa x,pa y){
		if (x.fi!=y.fi) return x.fi>y.fi;
		return x.se<y.se;
	});
	For(i,1,n) nxt[i]=i+1;
	e[++m]=mp(1,n);
	For(i,1,m){
		poly v;
		for (int j=e[i].fi;j<=e[i].se;){
			v.pb(j);
			j=nxt[j];
		}
		nxt[e[i].fi]=e[i].se;
		vec[++cnt]=v;
		FOR(j,0,siz(v)) Add(v[j],v[j==siz(v)-1?0:j+1],cnt);
	}
}

poly e[N];
int siz[N],mx[N],rt,Siz,col[N];
bool vis[N];
inline void Add(int x,int y){
	e[x].pb(y),e[y].pb(x);
}
inline void FindRoot(int u,int fa){
	siz[u]=1,mx[u]=0;
	for (auto v:e[u]) if (v!=fa&&!vis[v]){
		FindRoot(v,u),siz[u]+=siz[v];
		mx[u]=max(mx[u],siz[v]);
	}
	mx[u]=max(mx[u],Siz-siz[u]);
	if (!rt||mx[u]<mx[rt]) rt=u;
}
inline void getsiz(int u,int fa){
	siz[u]=1;
	for (auto v:e[u]) if (v!=fa&&!vis[v]){
		getsiz(v,u),siz[u]+=siz[v];
	}
}
inline void solve(int u,int dep){
	vis[u]=1,col[u]=dep;
	getsiz(u,0);
	for (auto v:e[u]) if (!vis[v]){
		Siz=siz[v],rt=0,FindRoot(v,u),solve(rt,dep+1);
	}
}

int main(){
	n=read(),m=read();
	For(i,1,m){
		int x=read(),y=read();
		ed[i]=mp(x,y);
	}
	Build(ed);
	For(i,1,cnt){
		tmp[i]=i;
		sort(all(vec[i]));
		reverse(all(vec[i]));
	}
	sort(tmp+1,tmp+1+cnt,[](int x,int y){
		FOR(i,0,min(siz(vec[x]),siz(vec[y]))){
			if (vec[x][i]!=vec[y][i]){
				return (vec[x][i]<vec[y][i]);
			}
		}
		return siz(vec[x])<siz(vec[y]);
	}); 
	For(i,1,cnt){
		rid[tmp[i]]=i;
//		printf("wdnmd ");
//		for (auto j:vec[tmp[i]]) printf("%d ",j);
//		puts("");
	}
	for (auto i:id){
		assert(siz(i.se)<=2);
		if (siz(i.se)<=1) continue;
		Add(rid[i.se[0]],rid[i.se[1]]);
	}
	rt=0,Siz=n,FindRoot(1,0),solve(rt,1);
	For(i,1,cnt) printf("%d ",col[i]);
}