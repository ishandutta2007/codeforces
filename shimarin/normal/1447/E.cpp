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

const int N = 2e5+10;
int n,a[N];

int cnt,son[N*30][2],t[N*30];
inline void insert(int x){
	int u=0;
	Dow(i,29,0){
		int v=(x&(1<<i))>0;
		if (!son[u][v]) son[u][v]=++cnt;
		u=son[u][v];
	}
	t[u]=1;
}

int f[N];
inline void dfs(int u){
	if (son[u][0]) dfs(son[u][0]);
	if (son[u][1]) dfs(son[u][1]);
	f[u]=max(f[son[u][0]]+(son[u][1]>0),f[son[u][1]]+(son[u][0]>0));
	if (t[u]) f[u]=max(f[u],1);
}

int main(){
	n=read();
	For(i,1,n) a[i]=read(),insert(a[i]);
	dfs(0),printf("%d\n",n-f[0]);
}