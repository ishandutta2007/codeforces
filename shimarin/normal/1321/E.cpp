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
int n,m,k;
pa a[N],b[N];
struct node{
	int x,y,z;
}c[N];

const int M = 1e6+10;
ll f[M],v[M<<2],lazy[M<<2];
inline void Build(int u,int l,int r){
	if (l==r) return v[u]=f[l],void(0);
	int mid=l+r>>1;
	Build(u<<1,l,mid),Build(u<<1^1,mid+1,r);
	v[u]=max(v[u<<1],v[u<<1^1]);
}
inline void upd(int u,ll x){
	v[u]+=x,lazy[u]+=x;
}
inline void push_down(int u){
	if (lazy[u]) upd(u<<1,lazy[u]),upd(u<<1^1,lazy[u]),lazy[u]=0;
}
inline void update(int u,int l,int r,int ql,int qr,ll x){
	if (l>=ql&&r<=qr) return upd(u,x),void(0);
	int mid=l+r>>1;push_down(u);
	if (ql<=mid) update(u<<1,l,mid,ql,qr,x);
	if (qr>mid) update(u<<1^1,mid+1,r,ql,qr,x);
	v[u]=max(v[u<<1],v[u<<1^1]);
}

int main(){
	n=read(),m=read(),k=read();
	For(i,1,n) a[i].fi=read(),a[i].se=read();
	For(i,1,1e6+1) f[i]=-1e15;
	For(i,1,m) b[i].fi=read(),b[i].se=read(),f[b[i].fi]=max(f[b[i].fi],(ll)-b[i].se);
	sort(a+1,a+1+n),sort(b+1,b+1+m);
	For(i,1,k) c[i]=(node){read(),read(),read()};
	sort(c+1,c+1+k,[](node a,node b){
		return a.x<b.x;
	});
	Build(1,1,1e6+1);
	//printf("%lld\n",v[1]);
	int l=0;
	ll ans=-1e15;
	For(i,1,n){
		while (c[l+1].x<a[i].fi&&l<k) ++l,update(1,1,1e6+1,c[l].y+1,1e6+1,c[l].z);
		ans=max(ans,v[1]-a[i].se);
	}
	printf("%lld\n",ans);
}