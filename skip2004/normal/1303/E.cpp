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
const int mod = 1e9 + 7, maxn = 501;
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
int a[maxn], *can = a + 1;
inline bool chk(str s,str s0,str s1) {
	if(s0.size() < s1.size()) s0.swap(s1);
	if(s1.empty()) {
		auto x = s0.begin();
		for(int i : s) if( x < s0.end() && *x == i) ++ x;
		return x == s0.end();
	}
	for(int i = 0;i < s1.size();++i) can[i] = -1e9;
	can[-1] = -1;
	for(int i : s) {
		for(int j = s1.size() - 1;j >= -1;--j) {
			if(can[j] >= -1 && can[j] + 1 < s0.size() && s0[can[j] + 1] == i) ++ can[j];
			if(i == s1[j] && j >= 0) up(can[j], can[j - 1]);
		}
	}
	return can[s1.size() - 1] == s0.size() - 1;
}
int main() {
	ios::sync_with_stdio(false),cin.tie(0);
	int t; in, t;
	for(;t--;) {
		str s, t;
		cin >> s >> t;
		int ok = 0;
		for(int i = 0;i < t.size();++i) {
			ok = ok || chk(s, str(t.begin(), t.begin() + i), str(t.begin() + i, t.end()));
		}
		cout << (ok ? "yes" : "no") << '\n';
	}
}