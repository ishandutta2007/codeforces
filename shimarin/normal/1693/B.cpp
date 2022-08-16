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

const int N = 2e5+10;
int n,fa[N],l[N],r[N];
poly e[N];
int ans,a[N];
inline void dfs(int u){
	if (e[u].empty()){
		a[u]=r[u],++ans;
		return;
	}
	ll s=0;
	for (auto v:e[u]){
		dfs(v),s+=a[v];
	}
	if (s<l[u]) ++ans,a[u]=r[u];
		else a[u]=min(s,(ll)r[u]);
}
inline void solve(){
	n=read();
	For(i,1,n) e[i].clear();
	For(i,2,n){
		fa[i]=read();
		e[fa[i]].pb(i);
	}
	For(i,1,n) l[i]=read(),r[i]=read();
	ans=0,dfs(1);
	printf("%d\n",ans);
}

int main(){
	int T=read();
	while (T--) solve(); 
}
/*
1
4
1 2 1
6 9
5 6
4 5
2 4

*/