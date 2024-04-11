#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(v) (v).begin(),(v).end()
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
#define mp make_pair
#define pb emplace_back
#define ff first
#define ss second
#define iter iterator
using namespace __gnu_pbds;
using namespace std;
#pragma warning("mod is 1e9 + 7")
const int mod = 1e9 + 7, maxn = 1000200;
mt19937 rd(time(0));
inline void flush(){cout.flush();fflush(stdout);}
#define def(a,b) using a = b
def(u64,unsigned long long);def(u32,unsigned);def(ll,long long);
def(ld,long double);def(db,double);def(str,string);
using pr = pair<int,int>;
struct TEMP6_AK{} ed;
template<typename t>using vec=vector<t>;
template<typename t>using heap=__gnu_pbds::priority_queue<t>;
template<typename t>using rbt=tree<t,null_type,less<t>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename t>inline istream&operator,(istream&cin,t&x){return cin>>x;}
template<typename t>inline ostream&operator,(ostream&cout,const t&x){return cout<<x;}
inline void operator,(istream&cin,TEMP6_AK){ return ; }
inline void operator,(ostream&cout,TEMP6_AK){ return ; }
template<typename _1,typename _2>inline void up(_1&a,const _2&b){if(a<b)a=b;}
template<typename _1,typename _2>inline void down(_1&a,const _2&b){if(a>b)a=b;}
istream&in=cin;ostream&out=cout;
inline void reduce(int & x){ x += x >> 31 & mod; }
inline void dec(int & x,int y){ reduce(x -= y); }
inline void mul(int & x,int y){ x = ll(x) * y % mod; }
inline int pow(int a,int b){ int p=1; for(;b;b>>=1,mul(a,a))if(b&1)mul(p,a); return p; }
inline int inv(int a){return pow(a,mod-2);}
inline int popc(int a){ return __builtin_popcount(a); }
inline int popc(ll a){ return __builtin_popcountll(a); }
inline int ctz(int a){ return __builtin_ctz(a); }
inline int ctz(ll a){ return __builtin_ctzll(a); }
inline int lg2(int a){ return 31 - __builtin_clz(a); }
inline int lg2(ll a){ return 63 - __builtin_clzll(a); }
typedef long long ll;
ll tr[maxn << 2], ad[maxn << 2];
const int N = 1e6 + 1;
inline void put(int x,ll v) { ad[x] += v,tr[x] += v; }
inline void pd(int x){ put(x<<1,ad[x]),put(x<<1|1,ad[x]),ad[x]=0; }
void up(int cur){ tr[cur]=max(tr[cur<<1],tr[cur<<1|1]); }
void add(int ql,int qr,int v,int cur=1,int l = 1,int r = N) {
	if(ql<=l&&r<=qr)return put(cur,v);
	int mid =l+r>>1;pd(cur);
	if(ql<=mid)add(ql,qr,v,cur<<1,l,mid);
	if(mid<qr)add(ql,qr,v,cur<<1|1,mid+1,r);
	up(cur);
}
ll qry(int ql,int qr,int cur = 1,int l = 1,int r = N) {
	if(ql<=l&&r<=qr)return tr[cur];
	int mid = l +r >> 1;ll ret = -1e18;pd(cur);
	if(ql<=mid)up(ret,qry(ql,qr,cur<<1,l,mid));
	if(mid<qr)up(ret,qry(ql,qr,cur<<1|1,mid+1,r));
	return ret;
}
ll tag[N + 100];
void bd(int cur=1,int l=1,int r = N){
	if(l==r) return void(tr[cur]=tag[l]);
	int mid=l+r>>1;
	bd(cur<<1,l,mid),bd(cur << 1 | 1,mid+1,r);
	up(cur);
}
vec<pr> v0,v1,v3[N+10];
int n, m, p;
int main() {
	ios::sync_with_stdio(false),cin.tie(0);
	cin >> n >> m >> p;
	rep(i,1,n){ int x,y;in,x,y;v0.pb(x,y); }
	rep(i,1,N)tag[i]=-1e18;
	rep(i,1,m){ int x,y;in,x,y;up(tag[x],-y);}
	rep(i,1,p) {int x,y,k; cin>>x>>y>>k; v3[x+1].pb(y+1,k);}
	bd();
	sort(all(v0));
	ll ans = -1e18;
	for(auto i : v0) {
		static int x = 0;
		for(;x<=i.first;++x) for(auto j:v3[x]) add(j.first,N,j.second);
		up(ans,tr[1]-i.second);
	}
	cout<<ans<<'\n';
}