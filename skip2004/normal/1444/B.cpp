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
const int mod = 998244353, N = 1000200;
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
 
int n,a[N];
int fac[N],ifac[N],inv[N];
inline int calc(int a,int b){
	if(a+b&1)return 0;
	if(b>a)return 0;
	int n=a+b>>1;
	return (u64)fac[a]*ifac[n]%mod*ifac[a-n]%mod;
}
inline int cb(int n,int m){
	return (u64)fac[n+m]*ifac[n]%mod*ifac[m]%mod;
}
int va[N],vb[N];
int main() {
	ios::sync_with_stdio(false), in.tie(0);
	fac[0]=ifac[0]=fac[1]=ifac[1]=inv[1]=1;
	for(int i=2;i<N;++i){
		inv[i]=u64(mod-mod/i)*inv[mod%i]%mod;
		fac[i]=(u64)fac[i-1]*i%mod;
		ifac[i]=(u64)ifac[i-1]*inv[i]%mod;
	}
	in,n;
	rep(i,1,n+n)in,a[i];
	std::sort(a+1,a+n+n+1);
	u64 ans=0;
	rep(i,0,n)va[i]=(u64)ifac[i]*ifac[n-1-i]%mod;
	rep(i,1,n)a[i]=a[n+n+1-i]-a[i];
	u64 s=0;
	rep(b,0,n-1) s += (u64) cb(0,b)*cb(n-0-1,n-b-1)%mod;
	rep(a,0,n-1) ans+=s%mod*::a[a+1]%mod;
	cout<<ans*2%mod<<'\n';
}