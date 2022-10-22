#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(v) (v).begin(),(v).end()
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
#define ff first
#define ss second
#define iter iterator
using namespace __gnu_pbds;
using namespace std;
#pragma warning("mod is 1e9 + 7")
const int mod = 1e9 + 7, maxn = 20;
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
int n;
int s[maxn];
int dp[14][1 << 9][1 << 14];
int DFS(int node, int last, int edge) {
	if(!(node & node - 1)) return 1;
	if(~dp[last][edge][node]) return dp[last][edge][node];
	int&ret=dp[last][edge][node]=0;
	int S = node ^ 1 << last;
	if(edge & 1) S &= s[last];
	else S &= ~s[last];
	for(int t = S;t;t &= t - 1) {
		ret += DFS(node ^ 1 << last, __builtin_ctz(t), edge >> 1);
	}
	return ret;
}
ll dfs(int node, int last, int edge) {
	if(popc(node) < 13 && edge < 1 << 9) return DFS(node, last, edge);
	ll ret = 0;
	int S = node ^ 1 << last;
	if(edge & 1) S &= s[last];
	else S &= ~s[last];
	for(int t = S;t;t &= t - 1) {
		ret += dfs(node ^ 1 << last, __builtin_ctz(t), edge >> 1);
	}
	return ret;
}
int main() {
	memset(dp, -1, sizeof dp);
	ios::sync_with_stdio(false),cin.tie(0);
	std::mt19937 rd(time(0));
	cin >> n;
	rep(i,0,n-1)rep(j,0,n-1){
		char c;cin>>c;
		s[i]|=(c&1)<<j;
	}
	// freopen("1.out", "w", stdout);
	for(int j = 0;j < 1 << n - 1;++j) {
		ll ans = 0;
		rep(i, 0, n - 1) ans += dfs((1 << n) - 1, i, j);
		cout << ans << ' ';
	}
	// std::cerr << double(clock()) / CLOCKS_PER_SEC << '\n';
}