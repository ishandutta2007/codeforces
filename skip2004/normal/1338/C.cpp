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
inline ll cal(ll x) {
	ll i = 0;
	for(;1ll << i <= x;i += 2);
	ll b0 = 1ll << i - 2, b1 = 1ll << i;
	x -= b0;
	const ll a0 = b0 + x / 3;
	ll a1;
	const ll idx = x / 3;
	a1 = a0 + a0;
	for(ll o = idx, step = 1;o;o >>= 2, step <<= 2) {
		const int TT = o % 4;
		if(TT == 2) a1 -= step;
		if(TT == 3) a1 -= step * 5;
	}
	if(x % 3 == 0) return a0;
	if(x % 3 == 1) return a1;
	if(x % 3 == 2) return a0 ^ a1;
}
void naive(){
	const int N=100000;
	set<int>s;vec<int>v;
	rep(i, 1, 5000) {
		static int a = 1;
		for(;s.count(a);)++a;
		rep(b, a + 1, N) {
			int c = a ^ b;
			if(c > b) {
				if(!s.count(b)&&!s.count(c)){
					v.pb(a);
					v.pb(b);
					v.pb(c);
					s.insert(a);
					s.insert(b);
					s.insert(c);
					goto nxt;
				}
			}
		}
		nxt:;
	}
	for(int i:v){ 
		static int c=0; out,i," \n"[++c % 3 == 0];
		if(cal(c) != i) {
			out,"\n debug ",c,' ',i,' ',cal(c),'\n';
		}
	}
	out,v[38],'\n';
}
int main(){
	ios::sync_with_stdio(false),in.tie(0);
//	naive(); return 0;
	int t;
	in,t;
	for(;t--;){
		ll n;in,n;
		out,cal(n),'\n';
	}
}