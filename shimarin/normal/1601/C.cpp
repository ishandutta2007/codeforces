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

const int N = 2e6+10;
struct BIT{
	int b[N],n;
	void init(int _n){
		n=_n;
		For(i,1,_n) b[i]=0;
	}
	inline void Add(int x,int y){
    	for (;x<=n;x+=x&-x) b[x]+=y; 
    }
    inline int Query(int x){
    	int ret=0;
    	for (;x;x-=x&-x) ret+=b[x];
    	return ret;
    }
}BI;
struct Seg{
	int tag[N<<2],v[N<<2];
	inline void Build(int u,int l,int r,int n){
		tag[u]=v[u]=0;
		if (l==r) return v[u]=n-l,void(0);
		int mid=l+r>>1;
		Build(u<<1,l,mid,n),Build(u<<1^1,mid+1,r,n);
		v[u]=max(v[u<<1],v[u<<1^1]);
	}
	inline void upd(int u,int x){
		tag[u]+=x,v[u]+=x;
	}
	inline void push_down(int u){
		if (tag[u]) upd(u<<1,tag[u]),upd(u<<1^1,tag[u]),tag[u]=0;
	}
	inline void update(int u,int l,int r,int ql,int x){
		if (l==r) return v[u]=x,void(0);
		int mid=l+r>>1;push_down(u);
		if (ql<=mid) update(u<<1,l,mid,ql,x);
			else update(u<<1^1,mid+1,r,ql,x);
		v[u]=max(v[u<<1],v[u<<1^1]);
	}
	inline void update(int u,int l,int r,int ql,int qr,int x){
		if (ql>qr) return;
		if (l>=ql&&r<=qr) return upd(u,x),void(0);
		int mid=l+r>>1;push_down(u);
		if (ql<=mid) update(u<<1,l,mid,ql,qr,x);
		if (qr>mid) update(u<<1^1,mid+1,r,ql,qr,x);
		v[u]=max(v[u<<1],v[u<<1^1]);
	}
	inline int Query(int u,int l,int r,int ql,int qr){
		if (ql>qr) return 0;
		if (l>=ql&&r<=qr) return v[u];
		int mid=l+r>>1;push_down(u);
		if (qr<=mid) return Query(u<<1,l,mid,ql,qr);
		if (ql>mid) return Query(u<<1^1,mid+1,r,ql,qr);
		return max(Query(u<<1,l,mid,ql,qr),Query(u<<1^1,mid+1,r,ql,qr));
	}
}T;

int n,m,tot,c[N],a[N],b[N];
pa p[N];
inline void solve(){
	n=read(),m=read(),tot=0;
	For(i,1,n) a[i]=read(),c[++tot]=a[i];
	For(i,1,m) b[i]=read(),c[++tot]=b[i];
	sort(c+1,c+1+tot),tot=unique(c+1,c+1+tot)-c-1;
	For(i,1,n) a[i]=lower_bound(c+1,c+tot+1,a[i])-c,p[i]=mp(a[i],i);
	For(i,1,m) b[i]=lower_bound(c+1,c+tot+1,b[i])-c;
    ll ans=0;
    BI.init(tot);
    For(i,1,n) ans+=BI.Query(a[i]),BI.Add(a[i],1);
    sort(b+1,b+m+1),sort(p+1,p+n+1);
    T.Build(1,0,n,n);
    int p1=1,p2=1;
    For(i,1,m){
		while (p1<=n&&p[p1].fi<=b[i]) T.update(1,0,n,p[p1].se,n,1),++p1;
		while (p2<=n&&p[p2].fi<b[i]) T.update(1,0,n,0,p[p2].se-1,-1),++p2;
		ans+=T.Query(1,0,n,0,n);
	}
	printf("%lld\n",1ll*(n+m)*(n+m-1)/2-ans-1ll*m*(m-1)/2);
}
int main(){
	int T=read();
	while (T--) solve();
}