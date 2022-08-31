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
int n,m,dis[N];
poly e[N],E[N];
bool vis[N];

const int M = 1e7+10, inf = 1e9;
int tot,rt[N],cnt[M],v[M],ls[M],rs[M];
inline void push_up(int u){
	int L=inf,R=inf;
	if (ls[u]) L=v[ls[u]]+cnt[rs[u]];
	if (rs[u]) R=v[rs[u]];
	v[u]=min(L,R);
	cnt[u]=cnt[ls[u]]+cnt[rs[u]];
}
inline void update(int &u,int l,int r,int ql,int x){
	if (!u) u=++tot;
	if (l==r){
		cnt[u]+=x;
		if (cnt[u]==0) v[u]=inf;
			else v[u]=l;
		return;
	}
	int mid=l+r>>1;
	if (ql<=mid) update(ls[u],l,mid,ql,x);
		else update(rs[u],mid+1,r,ql,x);
	push_up(u);
}

int main(){
	n=read(),m=read();
	For(i,1,m){
		int x=read(),y=read();
		e[x].pb(y);
		E[y].pb(x);
	}
	For(i,1,n) update(rt[i],1,m,m,siz(e[i]));
	For(i,1,n) dis[i]=inf;
	priority_queue<pa>q;
	dis[n]=0,q.push(mp(0,n));
	while (!q.empty()){
		int u=q.top().se;q.pop();
		if (vis[u]) continue;
		vis[u]=1;
		for (auto v:E[u]) if (!vis[v]){
			update(rt[v],1,m,m,-1);
			update(rt[v],1,m,dis[u]+1,1);
			int tmp=::v[rt[v]];
			if (tmp<dis[v]){
				dis[v]=tmp;
				q.push(mp(-dis[v],v));
			}
		}
	}
	printf("%d\n",dis[1]);
}