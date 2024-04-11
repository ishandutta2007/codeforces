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
const int mod = 1e9 + 7, maxn = 200200;
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
int a[maxn];
int main() {
	ios::sync_with_stdio(false),cin.tie(0);
	int n,m;
	in,n,m;
	ll s = 0;
	rep(i,1,n) s += (i - 1) >> 1;
	if(s < m) {
		out,-1,'\n';
		return 0;
	}
	ll now = 0;
	rep(i, 1, n) {
		if(i - 1 >> 1 <= m) {
			m -= i - 1 >> 1;
			a[i] = i;
		} else {
			a[i] = i - 1 - m << 1 | 1;
			const int N = 5000;
			rep(j, i + bool(m), n) a[j] = 1e9 - n * N + j * N;
			break;
		}
	}
	rep(i, 1, n) {
		out,a[i],' ';
	}
}