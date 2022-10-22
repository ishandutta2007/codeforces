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
const int mod = 1e9 + 7, maxn = 2002000;
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
inline int popc(int a){ return __builtin_popcount(a); }
inline int popc(ll a){ return __builtin_popcountll(a); }
inline int ctz(int a){ return __builtin_ctz(a); }
inline int ctz(ll a){ return __builtin_ctzll(a); }
inline int lg2(int a){ return 31 - __builtin_clz(a); }
inline int lg2(ll a){ return 63 - __builtin_clzll(a); }
typedef long long ll;
const int mod0 = 1e9 + 7;
const int mod1 = 1e9 + 9;
int pw1[maxn];
int pw2[maxn];
int s0[maxn], r0[maxn];
int s1[maxn], r1[maxn];
char buf[maxn];
inline std::pair<int,int> sub(int l,int r) {
	return {
		(s0[r] + (ll) (mod0 - s0[l - 1]) * pw1[r-l+1])%mod0,
		(s1[r] + (ll) (mod1 - s1[l - 1]) * pw2[r-l+1])%mod1
	};
}
inline std::pair<int,int> rsub(int l,int r) {
	return {
		(r0[l] + (ll) (mod0 - r0[r + 1]) * pw1[r-l+1])%mod0,
		(r1[l] + (ll) (mod1 - r1[r + 1]) * pw2[r-l+1])%mod1
	};
}
inline str getmax(str s) {
	if(s.empty()) return "";
	static std::mt19937 rd(time(0));
	const ll h1 = rd() % 1000 + 1000;
	const ll h2 = rd() % 1000 + 1000;
	*pw1 = *pw2 = 1;
	for(int i = 1;i <= s.size();++i) {
		pw1[i] = pw1[i - 1] * h1 % mod0;
		pw2[i] = pw2[i - 1] * h2 % mod1;
		buf[i] = s[i - 1];
	}
	const int N = s.size(), n = N;
	rep(i, 1, N) {
		s0[i] = (s0[i - 1] * h1 + buf[i]) % mod0;
		s1[i] = (s1[i - 1] * h2 + buf[i]) % mod1;
	}
	for(int i = N;i >= 1;--i) {
		r0[i] = (r0[i + 1] * h1 + buf[i]) % mod0;
		r1[i] = (r1[i + 1] * h2 + buf[i]) % mod1;
	}
	for(int i = N;i >= 1;--i) {
		if(sub(1, i) == rsub(1, i)) return str(buf + 1, buf + i + 1);
		if(sub(n - i + 1, n) == rsub(n - i + 1, n)) return str(buf + n - i + 1, buf +n + 1);
	}
}
inline str solve(str s) {
	str p;
	int i = 0, j = s.size() - 1;
	for(;i < j && s[i] == s[j];++ i, --j) p += s[i];
	s = getmax(str(s.begin() + i, s.begin() + j + 1));
	s = p + s, reverse(all(p));
	return s + p;
}
int main() {
	ios::sync_with_stdio(false),cin.tie(0);
	int t;
	in,t;
	for(;t--;){
		str s;
		in,s;
		out,solve(s),'\n';
	}
}