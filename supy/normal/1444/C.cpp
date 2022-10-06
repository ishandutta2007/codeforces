#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
mt19937 R(chrono::system_clock().now().time_since_epoch().count());

const int N = 5e5+11;
int n,m,k,c[N];vector<Pii> a[N];bool gg[N];ll res;
struct node{
	int a,b,u,v;
	bool operator<(const node&x)const{
		if(a!=x.a)return a<x.a;
		if(b!=x.b)return b<x.b;
		return 0;
	}
}b[N];int len;
int sz[N],f[N],val[N];Pii sta[6666666];int top;
int find(int x){
	return f[x]==x?x:find(f[x]);
}
int qry(int x){
	return f[x]==x?val[x]:(qry(f[x])^val[x]);
}
int merge(int u, int v){
	int x=find(u),y=find(v);
	if(x==y){
		if((qry(u)^qry(v))==0)return -1;
		return 0;
	}
	if(sz[x]>sz[y])swap(x,y),swap(u,v);
	val[x]=qry(u)^qry(v)^1;
	f[x]=y;sz[y]+=sz[x];
	sta[++top]=mp(x,y);
	return 1;
}
int ck(int l, int r){
	if(gg[b[l].a]||gg[b[l].b])return 1;
	top=0;int res=1;
	rep(i,l,r)if(merge(b[i].u,b[i].v)==-1){res=0;break;}
	while(top){
		int x=sta[top].fi,y=sta[top].se;
		sz[y]-=sz[x];
		f[x]=x;
		val[x]=0;
		top--;
	}
	return res;
}

int main() {
	read(n);read(m);read(k);
	rep(i,1,n)f[i]=i,sz[i]=1;
	rep(i,1,n)read(c[i]);
	rep(i,1,m){
		int u,v;read(u);read(v);
		if(c[u]==c[v])a[c[u]].pb(mp(u,v));
		else{
			if(c[u]>c[v])swap(u,v);
			b[++len]=(node){c[u],c[v],u,v};
		}
	}
	sort(b+1,b+len+1);
	int zs=0;
	rep(i,1,k){
		top=0;
		for(Pii x:a[i])if(merge(x.fi,x.se)==-1){
			while(top){
				int x=sta[top].fi,y=sta[top].se;
				sz[y]-=sz[x];
				f[x]=x;
				val[x]=0;
				top--;
			}
			gg[i]=1;break;
		}
		zs+=!gg[i];
	}
//	rep(i,1,n)cerr<<find(i)<<' ';cerr<<endl;
	res=1ll*zs*(zs-1)/2;
	rep(l,1,len){
		int r=l;while(r+1<=len&&b[l].a==b[r+1].a&&b[l].b==b[r+1].b)r++;
	//	if(b[l].a==1&&b[l].b==3)cerr<<l<<':'<<r<<endl;
		res--;res+=ck(l,r);
		l=r;
	}
	cout<<res;
	return 0;
}