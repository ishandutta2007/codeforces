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

const int N = 4e5+10, mod = 1e9+7;
int n,f[N],g[N],tot,b[N];
pa a[N];

inline void upd(int &x,int y){
	x+=y;
	if (x>=mod) x-=mod;
}

int v[N<<2],s[N<<2];
inline void Build(int u,int l,int r){
	v[u]=2e9,s[u]=0;
	if (l==r) return;
	int mid=l+r>>1;
	Build(u<<1,l,mid),Build(u<<1^1,mid+1,r);
}
inline void update(int u,int l,int r,int ql,int x,int y){
	if (l==r){
		if (x<v[u]) v[u]=x,s[u]=y;
		else if (x==v[u]) upd(s[u],y);
		return;
	}
	int mid=l+r>>1;
	if (ql<=mid) update(u<<1,l,mid,ql,x,y);
		else update(u<<1^1,mid+1,r,ql,x,y);
	v[u]=min(v[u<<1],v[u<<1^1]),s[u]=0;
	if (v[u<<1]==v[u]) upd(s[u],s[u<<1]);
	if (v[u<<1^1]==v[u]) upd(s[u],s[u<<1^1]);
}
inline pa Query(int u,int l,int r,int ql,int qr){
	if (l>=ql&&r<=qr) return mp(v[u],s[u]);
	int mid=l+r>>1;
	if (qr<=mid) return Query(u<<1,l,mid,ql,qr);
	if (ql>mid) return Query(u<<1^1,mid+1,r,ql,qr);
	pa L=Query(u<<1,l,mid,ql,qr),R=Query(u<<1^1,mid+1,r,ql,qr);
	int ret=min(L.fi,R.fi),s=0;
	if (L.fi==ret) upd(s,L.se);
	if (R.fi==ret) upd(s,R.se);
	return mp(ret,s);
}

int main(){
	n=read();
	For(i,1,n) a[i].se=read(),a[i].fi=read(),b[++tot]=a[i].fi,b[++tot]=a[i].se;
	sort(a+1,a+1+n),sort(b+1,b+1+tot),tot=unique(b+1,b+1+tot)-b-1;
//	puts("");
	For(i,1,n){
		a[i].fi=lower_bound(b+1,b+1+tot,a[i].fi)-b;
		a[i].se=lower_bound(b+1,b+1+tot,a[i].se)-b;
//		printf("%d %d %d\n",i,a[i].fi,a[i].se);
	}
//	puts("");
	Build(1,0,tot);
	g[0]=1;
	update(1,0,tot,0,0,1);
	For(i,1,n){
//		f[i]=1e9;
//		FOR(j,0,i) if (a[j].se<=a[i].fi) f[i]=min(f[i],f[j]);
//		FOR(j,0,i) if (a[j].se<=a[i].fi&&f[j]==f[i]) upd(g[i],g[j]); 
		pa tmp=Query(1,0,tot,0,a[i].fi);
		f[i]=tmp.fi,g[i]=tmp.se;
		f[i]+=b[a[i].fi];
		if (a[i].se<=a[n].fi) f[i]-=b[a[i].se];
//		printf("%d %d %d\n",i,f[i],g[i]);
		update(1,0,tot,a[i].se,f[i],g[i]);
	}
	int ans=2e9;
	For(i,1,n) if (a[i].se>a[n].fi) ans=min(ans,f[i]);
	int s=0;
	For(i,1,n) if (a[i].se>a[n].fi&&ans==f[i]) upd(s,g[i]);
	printf("%d\n",s);
}