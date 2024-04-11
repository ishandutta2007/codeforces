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
int n,q,a[N];

const ll inf = 1e15;
struct node{
	ll vl,vr,s,mn0,mn1;
	ll a,z;
	bool flag;
	inline node operator + (const node &p)const{
		node ret;
		ret.mn0=min(mn0,p.mn0);
		ret.mn1=min(mn1,p.mn1);
//		ret.p=ret.q=0;
		if (a) ret.a=a,ret.z=z;
			else ret.a=p.a,ret.z=p.z;
		ret.vl=vl,ret.vr=p.vr;
		ret.s=s+p.s,ret.flag=flag|p.flag;
		if (vr>=0&&p.vl<=0) ret.flag=1;
		if (vr<=0&&p.vl>=0) ret.a=vr,ret.z=p.vl;
		if (vr<=0&&p.vl<=0) ret.mn0=min(ret.mn0,abs(vr));
		if (vr>=0&&p.vl>=0) ret.mn1=min(ret.mn1,abs(p.vl));
		return ret;
	}
};
node v[N<<2];
inline void Build(int u,int l,int r){
	if (l==r){
		v[u].vl=v[u].vr=a[l]-a[l-1],v[u].s=abs(a[l]-a[l-1]);
		v[u].flag=0;
//		if (v[u].vl<=0) v[u].mn0=abs(v[u].vl);
//			else v[u].mn0=inf;
//		if (v[u].vl>=0) v[u].mn1=abs(v[u].vl);
//			else v[u].mn1=inf;
		v[u].mn0=v[u].mn1=inf;
		v[u].a=v[u].z=0;
		return;
	}
	int mid=l+r>>1;
	Build(u<<1,l,mid),Build(u<<1^1,mid+1,r);
	v[u]=v[u<<1]+v[u<<1^1];
}
inline void update(int u,int l,int r,int ql,int x){
	if (l==r){
		ll y=v[u].vl+x;
		v[u].vl=v[u].vr=y,v[u].s=abs(y);
		v[u].flag=0;
//		if (v[u].vl<=0) v[u].mn0=abs(v[u].vl);
//			else v[u].mn0=inf;
//		if (v[u].vl>=0) v[u].mn1=abs(v[u].vl);
//			else v[u].mn1=inf;
		v[u].mn0=v[u].mn1=inf;
		v[u].a=v[u].z=0;
		return;
	}
	int mid=l+r>>1;
	if (ql<=mid) update(u<<1,l,mid,ql,x);
		else update(u<<1^1,mid+1,r,ql,x);
	v[u]=v[u<<1]+v[u<<1^1];
}
inline node Query(int u,int l,int r,int ql,int qr){
	if (l>=ql&&r<=qr) return v[u];
	int mid=l+r>>1;
	if (qr<=mid) return Query(u<<1,l,mid,ql,qr);
	if (ql>mid) return Query(u<<1^1,mid+1,r,ql,qr);
	return Query(u<<1,l,mid,ql,qr)+Query(u<<1^1,mid+1,r,ql,qr);
}

int main(){
	n=read();
	For(i,1,n) a[i]=read();
	Build(1,2,n);
	q=read();
	int cnt=0;
	For(i,1,q){
		int opt=read(),l=read(),r=read(),x=read();
		if (opt==2){
			if (l>1) update(1,2,n,l,x);
			if (r<n) update(1,2,n,r+1,-x);
		}
		if (opt==1){
			++cnt;
			node ret=Query(1,2,n,max(l,2),min(n,r+1));
			ll ans=0;
			if (ret.flag) ans=v[1].s+2*x;
			else {
				if (ret.mn0!=inf) ans=max(ans,v[1].s-ret.mn0+x+abs(-ret.mn0+x));
				if (ret.mn1!=inf) ans=max(ans,v[1].s-ret.mn1+x+abs(ret.mn1-x));
				if (ret.a&&ret.z) ans=max(ans,v[1].s-abs(ret.a)-abs(ret.z)+abs(ret.a+x)+abs(ret.z-x));
			}
			if (l==1) ans=max(ans,v[1].s-ret.vl+abs(ret.vl-x));
			if (r==n) ans=max(ans,v[1].s-ret.vr+abs(ret.vr+x));
			printf("%lld\n",ans);
		}
	}
}