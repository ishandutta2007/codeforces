#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cour<<i<<" ";puts("")
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
int n,m,k,d[N];
poly e[N];
pa E[N];

bool vis[N],flag[N];
inline bool check(poly v){
	for (auto i:v) if (siz(e[i])<k-1) return 0;
	FOR(i,0,siz(v)){
		FOR(j,i+1,siz(v)){
			int x=v[i],y=v[j];
			if (x>y) swap(x,y);
			if (!binary_search(E+1,E+1+m,mp(x,y))) return 0; 
		}
	}
	return 1;
}
inline bool doit(){
	if (k==1) return puts("2\n1"),1;
	sort(E+1,E+1+m);
	For(i,1,n) d[i]=siz(e[i]),vis[i]=flag[i]=0;
	queue<int>q;
	For(i,1,n) if (d[i]<k) q.push(i),vis[i]=1;
	while (!q.empty()){
		int u=q.front();q.pop();
		if (d[u]==k-1){
			poly ans={u};
			for (auto v:e[u]) if (!flag[v]) ans.pb(v);
			if (siz(ans)==k&&1ll*k*(k-1)/2<=m&&check(ans)){
				printf("%d\n",2);
				for (auto i:ans) printf("%d ",i);puts("");
				return 1;
			}
		}
		flag[u]=1;
		for (auto v:e[u]){
			--d[v];
			if (d[v]<k&&!vis[v]) q.push(v),vis[v]=1;
		}
	}
	poly ans;
	For(i,1,n) if (!vis[i]) ans.pb(i);
	if (siz(ans)){
		printf("1 %d\n",siz(ans));
		for (auto i:ans) printf("%d ",i);puts("");
		return 1;
	}
	return 0;
}
inline void solve(){
	n=read(),m=read(),k=read();
	For(i,1,n) e[i].clear();
	For(i,1,m){
		int x=read(),y=read();
		e[x].pb(y),e[y].pb(x);
		if (x>y) swap(x,y);
		E[i]=mp(x,y);
	}
	if (!doit()) puts("-1");
}

int main(){
	int T=read();
	while (T--) solve();
}