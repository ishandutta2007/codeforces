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
const int N = 5e5+10;
int n,m,f[N],cnt,c[N];
pa a[N],b[N];
 
/*inline int calc(int l,int r,int x){
	int ret=0;
	For(i,l,r) ret+=a[i].fi>=x;
	return ret;
}
inline void force(){	
	For(i,l+1,n){
		FOR(j,l,i) f[i]=max(f[i],f[j]+calc(j+1,i-1,a[i].se)+(a[i].fi>=a[j].se));
	}
}*/
 
int t[N];
inline void Add(int x,int y){
	for (;x;x-=x&-x) t[x]+=y;
}
inline int Query(int x){
	int ret=0;
	for (;x<=n;x+=x&-x) ret+=t[x];
	return ret;
}
 
int tag[N<<2],v[N<<2];
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
 
int main(){
	n=read(),m=read();
	For(i,1,n) a[i].fi=read(),a[i].se=read();
	sort(a+1,a+1+n,[=](pa a,pa b){
		return a.se<b.se;
	});
	int l=0;
	For(i,1,n) if (a[i].se<=m) l=i;
	For(i,1,l) f[l]+=(a[i].fi>=m);
	a[0].se=m;
	update(1,0,n,l,f[l]+(n-l));
	For(i,l+1,n) b[++cnt]=mp(a[i].fi,i),Add(i,1);
	For(i,0,n) c[i]=max(a[i].se,m);
	sort(b+1,b+1+cnt);
	int p=1;
	For(i,l+1,n){
		while (p<=cnt&&b[p].fi<a[i].se){
			update(1,0,n,l,b[p].se-1,-1),Add(b[p].se,-1);
			++p;
		}
		int mid=min(int(upper_bound(c,c+1+n,a[i].fi)-c),i);
		f[i]=max(mid-1<0?-1:(Query(1,0,n,l,mid-1)+1),Query(1,0,n,mid,i-1))-Query(i);
		update(1,0,n,i,f[i]+Query(i+1));
	}	
	printf("%d\n",f[n]);
}