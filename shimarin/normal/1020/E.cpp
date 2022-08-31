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
int n,m,vis[N];
poly e[N];
 
int main(){
	n=read(),m=read();
	For(i,1,m){
		int x=read(),y=read();
		e[x].pb(y);
	}
	fil(vis,-1);
	For(i,1,n) if (vis[i]==-1){
		vis[i]=1;
		for (auto v:e[i]) if (vis[v]==-1) vis[v]=0;
	}
	Dow(i,n,1) if (vis[i]==1){
		for (auto v:e[i]) if (vis[v]==1) vis[v]=0;
	}
	poly ans;
	For(i,1,n) if (vis[i]) ans.pb(i);
	printf("%d\n",siz(ans));
	for (auto i:ans) printf("%d ",i);
}