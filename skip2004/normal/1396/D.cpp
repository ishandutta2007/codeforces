#include<bits/extc++.h>
#include<bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
using namespace __gnu_pbds;
using namespace std;
#pragma warning("mod is 1e9 + 7")
const int mod = 1e9 + 7, N = 10002;
mt19937 rd(114514),&gen = rd;
inline void flush() { cout.flush(), fflush(stdout); }
typedef unsigned long long u64;
typedef unsigned u32;
typedef double db;
typedef long long ll;
typedef pair<int, int> pr;
struct TEMP6_AK{} ed;
template<typename t>using vec=vector<t>;
template<typename t>using heap=__gnu_pbds::priority_queue<t>;
template<typename t>using rbt=tree<t,null_type,less<t>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename t>inline istream&operator,(istream&cin,t&x){return cin>>x;}
template<typename t>inline ostream&operator,(ostream&cout,const t&x){return cout<<x;}
template<typename t>inline istream&operator>>(istream&cin,t&x){ for(auto & u : x) cin >> u; return cin; }
inline void operator,(istream&cin,TEMP6_AK){ return ; }
inline void operator,(ostream&cout,TEMP6_AK){ return ; }
template<typename _1,typename _2>inline void up(_1&a,const _2&b){if(a<b)a=b;}
template<typename _1,typename _2>inline void down(_1&a,const _2&b){if(a>b)a=b;}
istream&in=cin;ostream&out=cout;
inline void reduce(int & x){ x += x >> 31 & mod; }
inline void add(int & x, int y) { if((x += y) >= mod) x -= mod; }
inline void sub(int & x, int y) { if((x -= y) < 0) x += mod; }
inline void mul(int & x,int y){ x = u64(x) * y % mod; }
inline int pow(int a,int b){ int p=1; for(;b;b>>=1,mul(a,a))if(b&1)mul(p,a); return p; }
inline int inv(int a){return pow(a,mod-2);}
inline int popc(int a){ return __builtin_popcount(a); }
inline int popc(u32 a){ return __builtin_popcount(a); }
inline int popc(ll a){ return __builtin_popcountll(a); }
inline int popc(u64 a){ return __builtin_popcountll(a); }
inline int ctz(int a){ return __builtin_ctz(a); }
inline int ctz(u32 a){ return __builtin_ctz(a); }
inline int ctz(ll a){ return __builtin_ctzll(a); }
inline int ctz(u64 a){ return __builtin_ctzll(a); }
inline int lg2(int a){ return 31 - __builtin_clz(a); }
inline int lg2(ll a){ return 63 - __builtin_clzll(a); }
 
int n, k, L;
struct nd{ int x,y,lx,ly,c; };
vec<int>v0,v1;
vec<nd>a[N];
inline int operator<(nd x,nd y){ return x.x<y.x; }
struct evt{ int l,r,h; };
vec<evt>opt[N];
 
ll su[N<<2],sl[N<<2];
int mn[N<<2],mx[N<<2],tag[N<<2];
inline void update(int o){
	su[o]=su[o<<1]+su[o<<1|1];
	mn[o]=min(mn[o<<1],mn[o<<1|1]);
	mx[o]=max(mx[o<<1],mx[o<<1|1]);
}
inline void bs_update(int o) {
	sl[o]=sl[o<<1]+sl[o<<1|1];
	update(o);
}
inline void build(int o,int l=0,int r=v0.size()-1){
	tag[o]=-1;
	if(l==r){
		mn[o]=mx[o]=1e9+10;
		sl[o]=l?v0[l]-v0[l-1]:v0[0]+1;
		su[o]=(ll)sl[o]*mx[o];
		return ;
	}
	int mid=l+r>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	bs_update(o);
}
inline void put(int x,int l){
	mn[x]=mx[x]=l,su[x]=(ll)l*sl[x],tag[x]=l;
}
inline void pd(int x){
	if(tag[x]!=-1){
		put(x<<1,tag[x]);
		put(x<<1|1,tag[x]);
		tag[x]=-1;
	}
}
inline void mk(int ql,int qr,int v,int o=1,int l=0,int r=v0.size()-1){
	if(v>=mx[o])return;
	if(ql<=l&&r<=qr){
		if(v<=mn[o])return put(o,v);
	}
	int mid=l+r>>1;
	pd(o);
	if(ql<=mid)mk(ql,qr,v,o<<1,l,mid);
	if(mid<qr)mk(ql,qr,v,o<<1|1,mid+1,r);
	update(o);
}
int main() {
	ios::sync_with_stdio(false), in.tie(0);
	in, n, k, L;
	vec<nd>vc;
	rep(i,1,n){
		nd x; in,x.x,x.y,x.c;
		vc.pb(x);
		v0.pb(x.x);
		v1.pb(x.y);
	}
	sort(all(v0)),v0.erase(unique(all(v0)),v0.end());
	sort(all(v1)),v1.erase(unique(all(v1)),v1.end());
	for(nd&x:vc){
		x.lx=lower_bound(all(v0),x.x)-v0.begin();
		x.ly=lower_bound(all(v1),x.y)-v1.begin();
	}
	sort(all(vc));
	u64 out=0;
	for(int id=0;id<v1.size();++id){
		int x=v1[id],yes=0;
		for(nd u:vc)if(u.y<=x) a[u.c].pb(u);
		rep(i,1,k)if(a[i].size()){
			static nd st[N];st->lx=-1;
			int top=0;
			for(const nd&p:a[i]){
				opt[p.lx].pb((evt){st[top].lx+1,p.lx,0});
				for(;top&&p.y>=st[top].y;--top) opt[p.lx].pb((evt){st[top-1].lx+1, st[top].lx, st[top].y+1});
				st[++top]=p;
			}
			a[i].clear();
			rep(i,1,top) opt[v0.size()].pb((evt){st[i-1].lx+1,st[i].lx,st[i].y+1});
			opt[v0.size()].pb((evt){st[top].lx+1,v0.size()-1,0});
		}else{
			yes=1;
			break;
		}
		if(yes) {
			rep(i,1,k)a[i].clear();
			rep(i,0,v0.size())opt[i].clear();
			continue;
		}
		build(1);
		for(const auto&x:opt[v0.size()])if(x.l<=x.r)mk(x.l,x.r,x.h);
		opt[v0.size()].clear();
		u64 res=0;
		for(int i=v0.size() - 1;i>=0;--i){
			int cnt=(i==v0.size()-1?L:v0[i+1])-v0[i];
			res=(res+(u64)cnt*(su[1]%mod))%mod;
			for(const auto&x:opt[i])if(x.l<=x.r)mk(x.l,x.r,x.h);
			opt[i].clear();
		}
		out=(out+u64((id==v1.size()-1?L:v1[id+1])-x)*res)%mod;
	}
	cout<<out<<'\n';
}