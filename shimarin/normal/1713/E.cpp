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

const int N = 1010;
int n,a[N][N];

int fa[N];
inline int Find(int x){
	return fa[x]==x?x:fa[x]=Find(fa[x]);
}

vector<pa>e[N];
inline void Add(int x,int y,int z){
	if (Find(x)==Find(y)) return;
	fa[Find(x)]=Find(y);
	e[x].ep(y,z),e[y].ep(x,z);
}

int col[N];
bool vis[N];
inline void dfs(int u,int c){
	vis[u]=1,col[u]=c;
	for (auto [v,w]:e[u]) if (!vis[v]) dfs(v,c^w);
}

inline void solve(){
	n=read();
	For(i,1,n) For(j,1,n) a[i][j]=read();
	For(i,1,n) fa[i]=i,e[i].clear();
	For(i,1,n) For(j,1,n){
		if (i==j||a[i][j]==a[j][i]) continue;
		if (i<j){
			if (a[i][j]>a[j][i]) Add(i,j,1);
				else Add(i,j,0);
		}
	}
	For(i,1,n) vis[i]=0;
	For(i,1,n) if (!vis[i]){
		dfs(i,0);
	}
	For(i,1,n) For(j,i+1,n){
		if (col[i]^col[j]) swap(a[i][j],a[j][i]);
	}
	For(i,1,n){
		For(j,1,n) printf("%d ",a[i][j]);
		puts("");
	}
}

int main(){
	int T=read();
	while (T--) solve();
}