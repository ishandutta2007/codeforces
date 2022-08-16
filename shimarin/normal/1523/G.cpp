/*
.....
.../.|
./ /|
.|.  |
 }F...
  . --.._
  > 
/ 
 p_.
r ` .
{^ 
__--  |
_= _
          

*/
#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cout<<i<<" ";puts("")
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

const int N = 1e5+10;
int n,m,ans[N];
pa a[N];
poly vec[N];

const int M = 4e7, inf = 1e9;
int tot,rt[N],v[M],lson[M],rson[M];
inline void update(int &u,int l,int r,int ql,int x){
	if (!u) u=++tot,v[u]=inf;
	if (l==r) return v[u]=x==inf?inf:min(v[u],x),void(0);
	int mid=l+r>>1;
	if (ql<=mid) update(lson[u],l,mid,ql,x);
		else update(rson[u],mid+1,r,ql,x);
	v[u]=inf;
	if (lson[u]) v[u]=min(v[u],v[lson[u]]);
	if (rson[u]) v[u]=min(v[u],v[rson[u]]);
}
inline int Query(int u,int l,int r,int qr){
	if (!u) return inf;
	if (r<=qr) return v[u];
	int mid=l+r>>1,ret=Query(lson[u],l,mid,qr);
	if (mid<qr) ret=min(ret,Query(rson[u],mid+1,r,qr));
	return ret;
}
inline void insert(int l,int r,int x){
	for (int i=l;i;i-=i&-i) update(rt[i],1,n,r,x);
}
inline void erase(int l,int r){
	for (int i=l;i;i-=i&-i) update(rt[i],1,n,r,inf);
}
inline int Query(int l,int r){
	int ret=inf;
	for (int i=l;i<=n;i+=i&-i) ret=min(ret,Query(rt[i],1,n,r));
	return ret;
}
inline int calc(int l,int r){
	int tmp=Query(l,r);
	if (tmp==inf) return 0;
	return a[tmp].se-a[tmp].fi+1+calc(l,a[tmp].fi-1)+calc(a[tmp].se+1,r);
}

int main(){
	n=read(),m=read();
	For(i,1,m) a[i].fi=read(),a[i].se=read(),vec[a[i].se-a[i].fi+1].pb(i);
	Dow(i,n,1){
		for (auto j:vec[i]) insert(a[j].fi,a[j].se,j);
		ans[i]=calc(1,n);
	}
	For(i,1,n) printf("%d\n",ans[i]);
}