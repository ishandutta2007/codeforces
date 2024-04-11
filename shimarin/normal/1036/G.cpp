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

const int N = 1e6+10;
int n,m,s[N],t[N];
poly e[N],E[N];

inline void GG(){
	puts("NO");exit(0);
}

int d[N],f[N];
inline void bfs1(){
	queue<int>q;
	For(i,1,n) if (!d[i]) q.push(i);
	while (!q.empty()){
		int u=q.front();q.pop();
		for (auto v:e[u]){
			f[v]|=f[u];
			if (--d[v]==0) q.push(v);
		}
	}
}

int g[N];
inline void bfs2(){
	For(i,1,n)
		for (auto j:E[i]) d[j]++;
	queue<int>q;
	For(i,1,n) if (!d[i]) q.push(i);
	while (!q.empty()){
		int u=q.front();q.pop();
		for (auto v:E[u]){
			g[v]|=g[u];
			if (--d[v]==0) q.push(v);
		}
	}
}

int main(){
	n=read(),m=read();
	For(i,1,m){
		int u=read(),v=read();
		e[u].pb(v),E[v].pb(u),d[v]++;
	}
	For(i,1,n){
		if (d[i]==0) s[++*s]=i,f[i]|=(1<<*s-1);
		if (siz(e[i])==0) t[++*t]=i,g[i]|=(1<<*t-1);
	}
	bfs1(),bfs2();
	//For(i,1,n) printf(" %d %d %d\n",i,f[i],g[i]);
	FOR(i,1,(1<<*s)-1){
		int v=0;
		For(j,1,*s) if (i&(1<<j-1)) v|=g[s[j]];
		if (__builtin_popcount(i)==__builtin_popcount(v)) GG();
		v=0;
		For(j,1,*s) if (i&(1<<j-1)) v|=f[t[j]];
		if (__builtin_popcount(i)==__builtin_popcount(v)) GG();
	}
	puts("YES");
}