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

const int N = 1e5+10, maxn = N*50;
int n,m,d,tot,f[maxn],rd[maxn],hd,tl,q[maxn];
char s[N][55];

inline int id(int i,int j){
	return (i-1)*d+j;
}
inline pa invid(int x){
	if (x%d==0) return mp(x/d,d);
	return mp(x/d+1,x%d);
}

int Tot,fir[maxn],to[maxn],las[maxn];
inline void Addedge(int x,int y){
	to[++Tot]=y,las[Tot]=fir[x],fir[x]=Tot;
}
int em,u[N],v[N];
inline void Add(int x,int y){
	Addedge(x,y);
}

int Tim,dfn[maxn],low[maxn],top,stk[maxn],bel[maxn],val[maxn],cnt;
bool vis[maxn],flag[N];
inline void dfs(int u){
	dfn[u]=++Tim,low[u]=dfn[u];
	stk[++top]=u,vis[u]=1;
	for (int i=fir[u];i;i=las[i]){
		int v=to[i];
		if (!dfn[v]) dfs(v),low[u]=min(low[u],low[v]);
		else if (vis[v]) low[u]=min(low[u],dfn[v]);
	}
	if (low[u]==dfn[u]){
		++cnt;
		int las=top;
		while (stk[top+1]!=u){
			vis[stk[top]]=0,bel[stk[top]]=cnt;
			pa tmp=invid(stk[top]);
			if (s[tmp.fi][tmp.se]=='1'){
				if (!flag[tmp.fi]) ++val[cnt],flag[tmp.fi]=1;
			}
			--top;
		}
		For(i,top+1,las) flag[invid(stk[i]).fi]=0;
	}
}

int main(){
	n=read(),m=read(),d=read();
	//For(i,1,n) For(j,1,d) id[i][j]=++tot,invid[tot]=mp(i,j);
	tot=n*d;
	For(i,1,m){
		int x=read(),y=read();
		For(j,1,d) Add(id(x,j),id(y,j%d+1));
		u[i]=x,v[i]=y;
	}
	For(i,1,n) scanf("%s",s[i]+1);
	dfs(1);
	fil(fir,0),Tot=0;
	For(i,1,m){
		For(j,1,d){
			int x=id(u[i],j),y=id(v[i],j%d+1);
			if (bel[x]!=bel[y]) Addedge(bel[y],bel[x]),++rd[bel[x]];
		}
	}
	For(i,1,tot) if (!rd[i]) q[++tl]=i,f[i]=val[i];
	while (hd<tl){
		int u=q[++hd];
		for (int i=fir[u];i;i=las[i]){
			int v=to[i];
			f[v]=max(f[v],f[u]+val[v]);
			if (--rd[v]==0) q[++tl]=v;
		}
	}
	printf("%d\n",f[bel[1]]);
}