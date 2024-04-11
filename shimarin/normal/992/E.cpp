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

const int N = 2e5+10;
int n,q,a[N];

ll c[N];
inline void Add(int x,int y){
	for (;x<=n;x+=x&-x) c[x]+=y;
}
inline ll Query(int x){
	ll ret=0;
	for (;x;x-=x&-x) ret+=c[x];
	return ret;
}

int v[N<<2];
inline void Build(int u,int l,int r){
	if (l==r) return v[u]=a[l],void(0);
	int mid=l+r>>1;
	Build(u<<1,l,mid),Build(u<<1^1,mid+1,r);
	v[u]=max(v[u<<1],v[u<<1^1]);
}
inline void update(int u,int l,int r,int ql,int x){
	if (l==r) return v[u]=x,void(0);
	int mid=l+r>>1;
	if (ql<=mid) update(u<<1,l,mid,ql,x);
		else update(u<<1^1,mid+1,r,ql,x);
	v[u]=max(v[u<<1],v[u<<1^1]);
}
inline int Find(int u,int l,int r,int ql,int qr,ll x){
	if (v[u]<x) return -1;
	if (l==r) return l;
	int mid=l+r>>1;
	if (ql>mid) return Find(u<<1^1,mid+1,r,ql,qr,x);
	int ret=Find(u<<1,l,mid,ql,qr,x);
	if (ret!=-1) return ret;
	return Find(u<<1^1,mid+1,r,ql,qr,x);
}

inline int Query(){
	if (!a[1]) return 1;
	ll x=a[1];
	int now=1;
	while (now<=n){
		int nxt=Find(1,1,n,now+1,n,x);
		if (nxt==-1) return -1;
		x=Query(nxt-1);
		if (a[nxt]==x) return nxt;
		x+=a[nxt],now=nxt;
	}
	return -1;
}

int main(){
	n=read(),q=read();
	For(i,1,n) a[i]=read(),Add(i,a[i]);
	Build(1,1,n);
	while (q--){
		int x=read(),y=read();
		Add(x,-a[x]),a[x]=y,Add(x,a[x]);
		update(1,1,n,x,y);
		printf("%d\n",Query());
	}
}