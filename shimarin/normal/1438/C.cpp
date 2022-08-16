#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cerr<<i<<" ";puts("")
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

const int N = 110;
int n,m,a[N][N],id[N][N];

vector<pa>e[N*N];
inline void Add(int a,int b,int x,int y){
	if (x==y) e[a].ep(b,1),e[b].ep(a,1);
	else if (x==y+1){
		e[a].ep(b,0),e[b].ep(a,0);
	} else if (y==x+1){
		e[a].ep(b,0),e[b].ep(a,0);
	} else {

	}
}
int col[N*N];
inline void dfs(int u,int c){
	col[u]=c;
	for (auto v:e[u]) if (col[v.fi]==-1) dfs(v.fi,c^v.se);
}
inline void solve(){
	n=read(),m=read();
	For(i,1,n) For(j,1,m) a[i][j]=read();
	int cnt=0;
	For(i,1,n) For(j,1,m) id[i][j]=++cnt;
	For(i,1,cnt) e[i].clear();
	For(i,1,n) FOR(j,1,m) Add(id[i][j],id[i][j+1],a[i][j],a[i][j+1]);
	FOR(i,1,n) For(j,1,m) Add(id[i][j],id[i+1][j],a[i][j],a[i+1][j]);
	For(i,1,cnt) col[i]=-1;
	For(i,1,cnt) if (col[i]==-1) dfs(i,0);
	For(i,1,n){
		For(j,1,m) printf("%d ",a[i][j]+col[id[i][j]]);
		puts("");
	}
}

int main(){
	int T=read();
	while (T--) solve();
}