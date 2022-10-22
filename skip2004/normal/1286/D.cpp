#include<bits/extc++.h>
#include<bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
#define mp make_pair
#define pb emplace_back
#define ff first
#define ss second
#define iter iterator
using namespace __gnu_pbds;
using namespace std;
const int mod = 998244353, maxn = 1000200;
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
inline void add(int & x,int y){ reduce(x += y - mod); }
inline void dec(int & x,int y){ reduce(x -= y); }
inline void mul(int & x,int y){ x = ll(x) * y % mod; }
inline int pow(int a,int b){ int p=1; for(;b;b>>=1,mul(a,a))if(b&1)mul(p,a); return p; }
inline int inv(int a){return pow(a,mod-2);}
inline int pct(int a){ return __builtin_popcount(a); }
inline int pct(ll a){ return __builtin_popcountll(a); }
inline int ctz(int a){ return __builtin_ctz(a); }
inline int ctz(ll a){ return __builtin_ctzll(a); }
inline int lg2(int a){ return 31 - __builtin_clz(a); }
inline int lg2(ll a){ return 63 - __builtin_clzll(a); }
typedef long long ll;
int t[maxn][2][2];
int o[maxn][2][2];
int n;
inline void up(int cur){
	memset(t[cur],0,sizeof t[cur]);
	rep(i,0,1)rep(j,0,1)rep(k,0,1) t[cur][i][k]=(t[cur][i][k]+(ll)t[cur<<1][i][j]*t[cur<<1|1][j][k])%mod;
}
inline void mdf(int o,int p,int l=1,int r=n){
	if(l==r) return void(memcpy(t[o],::o[p],sizeof t[o]));
	int mid = l + r >> 1;
	if(p<=mid)mdf(o<<1,p,l,mid);
	else mdf(o<<1|1,p,mid+1,r);
	up(o);
}
struct T{ int pos,v0,v1,a,b,v; };
std::vector<T> v;
struct O { int x,v,p; } a[maxn];
inline int p(){ return (t[1][0][0] + t[1][0][1]) % mod; }
int main(){
	ios::sync_with_stdio(),in.tie(0);
	in,n;
	rep(i,1,n){
		in,a[i].x,a[i].v,a[i].p;
		a[i].p = (ll) a[i].p * pow(100,mod - 2) % mod;
	}
	sort(a + 1,a + n + 1,[](const O & x,const O & y){ return x.x < y.x; });
	rep(i,1,n){
		o[i][0][0]=o[i][1][0] = a[i].p;
		o[i][0][1]=o[i][1][1] = mod + 1 - a[i].p;
		mdf(1,i);
	}
	rep(i,1,n-1) {
		v.push_back({i,0,1,a[i+1].x-a[i].x,a[i].v+a[i+1].v,(ll) a[i].p * (mod + 1 - a[i + 1].p) % mod});
		if(a[i].v > a[i + 1].v)
			v.push_back({i,0,0,a[i+1].x-a[i].x,a[i].v-a[i+1].v,(ll) a[i].p * a[i + 1].p % mod});
		if(a[i].v < a[i + 1].v)
			v.push_back({i,1,1,a[i+1].x-a[i].x,a[i + 1].v-a[i].v,(ll) (mod + 1 - a[i].p) * (mod + 1 - a[i + 1].p) % mod});
	}
	sort(v.begin(),v.end(),[](const T & x,const T &y){ return (ll) x.a * y.b < (ll) y.a * x.b; });
	ll ans = 0;
	for(auto&i:v){
		ll o = p();
		::o[i.pos + 1][i.v0][i.v1] = 0;
		mdf(1,i.pos + 1);
		ans = (ans + (ll) (mod + o - p()) * i.a % mod * pow(i.b,mod - 2) % mod) % mod;
	}
	out,ans,'\n';
}