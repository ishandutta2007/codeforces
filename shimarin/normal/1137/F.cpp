#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cout<<i<<" ";puts("")
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
 
const int N = 2e5+10;
int n,m;
poly e[N];
char s[10];
 
struct BIT{
	int c[N<<1];
	inline void Add(int x,int y){
		for (;x<=n+m;x+=x&-x) c[x]+=y;
	}
	inline int Query(int x){
		int ret=0;
		for (;x;x-=x&-x) ret+=c[x];
		return ret;
	}
}t;
namespace LCT{
	int son[N][2],fa[N],siz[N],tag[N],tagc[N],col[N];
	inline bool isroot(int u){
		return son[fa[u]][0]!=u&&son[fa[u]][1]!=u;
	}
	inline void upd(int u){
		swap(son[u][0],son[u][1]),tag[u]^=1;
	}
	inline void updc(int u,int c){
		col[u]=c,tagc[u]=c;
	}
	inline void push_down(int u){
		if (tag[u]){
			if (son[u][0]) upd(son[u][0]);
			if (son[u][1]) upd(son[u][1]);
			tag[u]=0;
		}
		if (tagc[u]){
			if (son[u][0]) updc(son[u][0],tagc[u]);
			if (son[u][1]) updc(son[u][1],tagc[u]);
			tagc[u]=0;
		}
	}
	inline void push_up(int u){
		siz[u]=1;
		if (son[u][0]) siz[u]+=siz[son[u][0]];
		if (son[u][1]) siz[u]+=siz[son[u][1]];
	}
	inline void rotate(int x){
		int y=fa[x],z=fa[y],k=son[y][1]==x;
		if (!isroot(y)) son[z][y==son[z][1]]=x;fa[x]=z;
		son[y][k]=son[x][k^1],fa[son[x][k^1]]=y;
		fa[y]=x,son[x][k^1]=y;
		push_up(y),push_up(x);
	}
	inline void dfs(int u){
		if (!isroot(u)) dfs(fa[u]);
		push_down(u);
	}
	inline void splay(int x){
		dfs(x);
		while (!isroot(x)){
			int y=fa[x],z=fa[y];
			if (!isroot(y)){
				if ((son[y][0]==x)==(son[z][0]==y)) rotate(y);
					else rotate(x);
			}
			rotate(x);
		}
	}
	inline void Access(int x,int c){
		int y=0;
		for (;x;x=fa[y=x]){
			splay(x);
			if (col[x]) t.Add(col[x],-siz[x]+siz[son[x][1]]);
			son[x][1]=y,push_up(x);
		}
		splay(y),t.Add(c,siz[y]),updc(y,c);
	}
	inline void MakeRoot(int u,int c){
		Access(u,c),splay(u),upd(u);
	}
	inline int Rank(int x){
		splay(x);
		return t.Query(col[x]-1)+siz[son[x][1]]+1;
	}
}
 
int mx[N],son[N];
inline void dfs(int u,int fa){
	for (auto v:e[u]) if (v!=fa){
		dfs(v,u);
		if (!son[u]||mx[v]>mx[son[u]]) son[u]=v;
		LCT::fa[v]=u;
	}	
	if (son[u]||u<mx[son[u]]) LCT::son[u][1]=son[u];
	mx[u]=max(u,mx[son[u]]);
}
 
int main(){
	n=read(),m=read();
	FOR(i,1,n){
		int x=read(),y=read();
		e[x].pb(y),e[y].pb(x);
	}
	dfs(n,0);
	For(i,1,n) LCT::Access(i,i);
	For(i,1,m){
		scanf("%s",s+1);
		if (s[1]=='u'){
			int x=read();
			LCT::MakeRoot(x,n+i);
		} else if (s[1]=='w'){
			int x=read();
			printf("%d\n",LCT::Rank(x));
		} else {
			int x=read(),y=read();
			printf("%d\n",LCT::Rank(x)<LCT::Rank(y)?x:y);
		}
	}
}