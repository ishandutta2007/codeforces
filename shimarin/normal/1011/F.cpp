#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) printf("%lld ",i);puts("")
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
int n,son[N][2],opt[N];
char s[10];

int f[N];
inline void dfs(int u){
	if (opt[u]==5) return f[u]=son[u][0],void(0);
	if (son[u][0]) dfs(son[u][0]);
	if (son[u][1]) dfs(son[u][1]);
	if (opt[u]==1) f[u]=f[son[u][0]]&f[son[u][1]];
	if (opt[u]==2) f[u]=f[son[u][0]]|f[son[u][1]];
	if (opt[u]==3) f[u]=f[son[u][0]]^f[son[u][1]];
	if (opt[u]==4) f[u]=!f[son[u][0]];
}

int ans[N];
inline void Dfs(int u){
	if (opt[u]==1){
		if (f[u]){
			Dfs(son[u][0]),Dfs(son[u][1]);
		} else if (f[son[u][0]]+f[son[u][1]]==1){
			if (f[son[u][0]]==0) Dfs(son[u][0]);
				else Dfs(son[u][1]);
		}
	}
	if (opt[u]==2){
		if (!f[u]){
			Dfs(son[u][0]),Dfs(son[u][1]);
		} else if (f[son[u][0]]+f[son[u][1]]==1){
			if (f[son[u][0]]==1) Dfs(son[u][0]);
				else Dfs(son[u][1]);
		}
	}
	if (opt[u]==3){
		Dfs(son[u][0]),Dfs(son[u][1]);
	}
	if (opt[u]==4) Dfs(son[u][0]);
	if (opt[u]==5) ans[u]=f[1]^1;
}

int main(){
	n=read();
	For(i,1,n){
		scanf("%s",s+1);
		int u=i;
		if (s[1]=='A') son[u][0]=read(),son[u][1]=read(),opt[i]=1;
		if (s[1]=='O') son[u][0]=read(),son[u][1]=read(),opt[i]=2;
		if (s[1]=='X') son[u][0]=read(),son[u][1]=read(),opt[i]=3;
		if (s[1]=='N') son[u][0]=read(),opt[i]=4;
		if (s[1]=='I') son[u][0]=read(),opt[i]=5;
	}
	fil(ans,-1);
	dfs(1),Dfs(1);
	For(i,1,n) if (opt[i]==5) printf("%d",ans[i]==-1?f[1]:ans[i]);
}