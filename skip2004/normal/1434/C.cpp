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
const int mod = 1e9 + 7, N = 1000200;
mt19937 gen(114514);
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
 
int t,a,b,c,d;
typedef __int128 LL;
inline ll sum(ll l, ll r) {
	return (l + r) * (r - l + 1) >> 1;
}
inline bool chk(ll x) {
	if(x<=a)return 1;
	if((ll)b*c<a)return 1;
	ll max=a/b;
	ll M=max/d;
	ll p = (ll) M * d;
	LL dt = x - (M + 1) * a;
	const ll qwq=std::max(std::min<ll>((p-c+d)/d-1,M),-1ll);
	dt+=b*c*(qwq+1);
	dt+=LL(M-qwq)*p*b;
	dt-=(LL)b*d*sum(qwq+1,M);
	return dt <= 0;
}
inline ll calc(){
	ll l=0,r=1e18;
	if(chk(1e18))return -1;
	for(;l+1!=r;){
		ll mid=l+r>>1;
		if(chk(mid))l=mid;
		else r=mid;
	}
	return l;
}
int main() {
	ios::sync_with_stdio(false), in.tie(0);
	in,t;
	rep(i,1,t){
		cin>>a>>b>>c>>d;
		cout<<calc()<<'\n';
	}
}