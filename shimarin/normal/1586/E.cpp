#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
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

const int N = 1e6+10;
int n,m,q;
poly e[N];

bool vis[N];
poly E[N];
int dep[N],f[N];
inline void gett(int u){
	vis[u]=1;
	for (auto v:e[u]){
		if (vis[v]) continue;
		dep[v]=dep[u]+1,f[v]=u;
		gett(v),E[u].pb(v),E[v].pb(u);
	}
}

int c[N];
inline poly upd(int x,int y){
	poly a,b;
	while (x!=y)
		if (dep[x]>dep[y]){
			c[x]^=1,a.pb(x),x=f[x];
		} else {
			c[y]^=1,b.pb(y),y=f[y];
		}
	a.pb(x);
	reverse(all(b));
	for (auto i:b) a.pb(i);
	return a;
}


int Ans;
inline int calc(int u,int fa){
	int ret=0;
	for (auto v:E[u]) if (v!=fa) ret+=calc(v,u);
	Ans+=ret/2,ret%=2;
	if (c[u]) return 1;
	return Ans+=ret,0;
}

int main(){
	n=read(),m=read();
	For(i,1,m){
		int x=read(),y=read();
		e[x].pb(y),e[y].pb(x);
	}
	gett(1);
	vector<poly>ans;
	q=read();
	For(i,1,q){
		int x=read(),y=read();
		ans.pb(upd(x,y));
	}
	bool flag=0;
	For(i,1,n) flag|=c[i];
	if (!flag){
		puts("YES");
		for (auto i:ans){
			printf("%d\n",siz(i));
			for (auto j:i) printf("%d ",j);
			puts("");
		}
		return 0;
	}
	puts("NO");
	calc(1,0),printf("%d\n",Ans);
}