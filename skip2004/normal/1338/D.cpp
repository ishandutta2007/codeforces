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
const int mod = 1e9 + 7, maxn = 100020;
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
vec<int>v[maxn];
int dp0[maxn], dp1[maxn], ad[maxn];
struct pop_able{
	std::priority_queue<int> q0, q1;
	inline void push(int x){ q0.push(x); }
	inline void pop(int x){ q1.push(x); }
	inline int top() {
		for(;q1.size()&&q0.top()==q1.top();)q0.pop(),q1.pop();
		return q0.top();
	}
	inline int size(){ return q0.size() - q1.size(); }
} q0[maxn], q1[maxn];
inline void upt(int x) {
	dp0[x] = 1; dp1[x] = 0;
	if(q0[x].size()) {
		up<int>(dp0[x], q0[x].top() + q0[x].size() - 1);
		up<int>(dp0[x], q1[x].top() + std::max<int>(q1[x].size() - 1, 1));
		up<int>(dp1[x], q0[x].top() + q0[x].size() - 1);
	}
}
void dfs0(int x,int fa=0){
	for(int i:v[x])if(i!=fa) {
		dfs0(i, x);
		q0[x].push(dp0[i]);
		q1[x].push(dp1[i]);
	}
	upt(x);
}
int ans;
inline void dfs1(int x, int fa = 0) {
	up(ans, dp0[x]);
	up(ans, dp1[x]);
	for(int i : v[x]) if(i != fa) {
		q0[x].pop(dp0[i]), q1[x].pop(dp1[i]), upt(x);
		q0[i].push(dp0[x]), q1[i].push(dp1[x]), upt(i);
		dfs1(i,x);
		q0[i].pop(dp0[x]), q1[i].pop(dp1[x]), upt(i);
		q0[x].push(dp0[i]), q1[x].push(dp1[i]), upt(x);
	}
}
int n;
int main(){
	ios::sync_with_stdio(false),in.tie(0);
	in,n;
	rep(i,2,n){
		int x,y;
		in,x,y;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs0(1);
	dfs1(1);
	out,ans,'\n';
}