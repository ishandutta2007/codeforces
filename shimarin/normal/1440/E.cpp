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

int v[N<<2],tag[N<<2];
ll s[N<<2];
inline void Build(int u,int l,int r){
	if (l==r) return v[u]=a[l],s[u]=a[l],void(0);
	int mid=l+r>>1;
	Build(u<<1,l,mid),Build(u<<1^1,mid+1,r);
	v[u]=min(v[u<<1],v[u<<1^1]);
	s[u]=s[u<<1]+s[u<<1^1];
}
inline void upd(int u,int l,int r,int x){
	v[u]=x,s[u]=1ll*(r-l+1)*x,tag[u]=x;
}
inline void push_down(int u,int l,int r,int mid){
	if (tag[u]) upd(u<<1,l,mid,tag[u]),upd(u<<1^1,mid+1,r,tag[u]),tag[u]=0;
}
inline int Find(int u,int l,int r,int ql,int qr,int x){
	if (v[u]>x) return -1;
	if (l==r) return l;
	int mid=l+r>>1;push_down(u,l,r,mid);
	if (qr<=mid) return Find(u<<1,l,mid,ql,qr,x);
	if (ql>mid) return Find(u<<1^1,mid+1,r,ql,qr,x);
	int ret=Find(u<<1,l,mid,ql,qr,x);
	if (ret!=-1) return ret;
	return Find(u<<1^1,mid+1,r,ql,qr,x);
}
inline void update(int u,int l,int r,int ql,int qr,int x){
	if (l>=ql&&r<=qr) return upd(u,l,r,x),void(0);
	int mid=l+r>>1;push_down(u,l,r,mid);
	if (ql<=mid) update(u<<1,l,mid,ql,qr,x);
	if (qr>mid) update(u<<1^1,mid+1,r,ql,qr,x);
	v[u]=min(v[u<<1],v[u<<1^1]);
	s[u]=s[u<<1]+s[u<<1^1];
}
int S;
inline int Find2(int u,int l,int r,int ql){
	if (l>=ql&&S>=s[u]) return S-=s[u],r;
	if (l==r) return -1;
	int mid=l+r>>1;push_down(u,l,r,mid);
	if (ql>mid) return Find2(u<<1^1,mid+1,r,ql);
	int ret=Find2(u<<1,l,mid,ql);
	if (ret==mid){
		int ret2=Find2(u<<1^1,mid+1,r,ql);
		if (ret2!=-1) return ret2;
			else return ret;
	}
	return ret;
}

inline void upd(int x,int y){
	int tmp=Find(1,1,n,1,x,y);
	if (tmp==-1) return;
	update(1,1,n,tmp,x,y);
}
inline int Query(int x,int y){
	int ans=0;
	while (x<=n){
		int nxt=Find(1,1,n,x,n,y);
		if (nxt==-1) break;
		x=nxt;
		S=y,nxt=Find2(1,1,n,x);
		y=S,ans+=nxt-x+1,x=nxt+1;
	}
	return ans;
}

int main(){
	n=read(),q=read();
	For(i,1,n) a[i]=read();
	Build(1,1,n);
	For(i,1,q){
		int opt=read(),x=read(),y=read();
		if (opt==1) upd(x,y);
		if (opt==2) printf("%d\n",Query(x,y));
	}
}