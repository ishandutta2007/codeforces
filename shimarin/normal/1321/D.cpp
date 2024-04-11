//    
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

const int N = 2e5+10;
int n,m,k,a[N],x[N],y[N];
vector<int>e[N];

int vis[N];
ll dis[N];
inline void Dij(int s){
	For(i,1,n) vis[i]=0,dis[i]=1e15;
	priority_queue<pa>q;
	dis[s]=0,q.push(mp(0,s));
	while (!q.empty()){
		int u=q.top().se;q.pop();
		if (vis[u]) continue;vis[u]=1;
		for (auto v:e[u]){
			if (dis[u]+1<dis[v]){
				dis[v]=dis[u]+1;
				q.push(mp(-dis[v],v));
			}
		}
	}
}

int main(){
	n=read(),m=read();
	For(i,1,m){
		int x=read(),y=read();
		::x[i]=x,::y[i]=y;
		e[y].pb(x);
	}
	k=read();
	For(i,1,k) a[i]=read();
	Dij(a[k]);
//	For(i,1,n) printf("%lld ",dis[i]);puts("");
	For(i,1,n) e[i].clear();
	For(i,1,m){
		e[x[i]].pb(y[i]);
	}
	int ans1=0,ans2=0;
	For(i,1,k-1){
		int cnt=0,flag=0;
		for (auto j:e[a[i]]){
			if (dis[a[i]]-1==dis[j]){
				if (j==a[i+1]) flag=1;
				++cnt;
			}
		}
		if (!flag) ++ans1,++ans2;
		else if (cnt>1) ++ans2;
	}
	printf("%d %d\n",ans1,ans2);
}