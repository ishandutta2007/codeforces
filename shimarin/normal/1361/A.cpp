//
#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) cout<<#v<<":";for (auto i:v) cout<<i<<" ";puts("")
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
 
const int N = 5e5+10;
int n,m,p[N];
pa a[N];
vector<int>e[N];
bool vis[N];
 
inline void GG(){
	puts("-1");exit(0);
}
 
int main(){
	n=read(),m=read();
	For(i,1,m){
		int x=read(),y=read();
		e[x].pb(y),e[y].pb(x);
	}
	For(i,1,n) a[i]=mp(read(),i);
	sort(a+1,a+1+n);
	For(i,1,n){
		if (a[i].fi>siz(e[a[i].se])+1) GG();
		For(j,1,a[i].fi) vis[j]=0;
		for (auto v:e[a[i].se]) vis[p[v]]=1;
		FOR(j,1,a[i].fi) if (!vis[j]) GG();
		if (vis[a[i].fi]) GG();
		p[a[i].se]=a[i].fi;
	}
	For(i,1,n) printf("%d ",a[i].se);
}