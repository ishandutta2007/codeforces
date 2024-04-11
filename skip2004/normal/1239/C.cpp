
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#include<bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define iter iterator
using namespace __gnu_pbds;
using namespace std;
#pragma warning("mod is 1e9 + 7")
const int mod = 1e9 + 7, maxn = 200200;
mt19937 rd(time(0));
inline void flush(){cout.flush(),fflush(stdout);}
#define def(a,b) using a = b
def(u64,unsigned long long);def(u32,unsigned);def(ll,long long);def(ld,long double);def(db,double);
def(str,string);
using pr = pair<int,int>;
struct TEMP6_AK{} ed;
template<typename t>using vec=vector<t>;
template<typename t>using heap=__gnu_pbds::priority_queue<t>;
template<typename t>using rbt=tree<t,null_type,less<t>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename t>inline istream&operator,(istream&cin,t&x){return cin>>x;}
template<typename t>inline ostream&operator,(ostream&cout,const t&x){return cout<<x;}
inline void operator,(istream&,TEMP6_AK){ return ; }
inline void operator,(ostream&,TEMP6_AK){ return ; }
template<typename _1,typename _2>inline void up(_1&a,const _2&b){if(a<b)a=b;}
template<typename _1,typename _2>inline void down(_1&a,const _2&b){if(a>b)a=b;}
istream&in=cin;ostream&out=cout;
inline void reduce(int & x){ x += x >> 31 & mod; }
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
ll n,p;
ll t[maxn],ans[maxn];
int rk[maxn];
 
int tr[maxn],que[maxn];
inline void add(int pos,int v){ while(pos) tr[pos] = min(tr[pos],v),pos &= pos - 1; }
inline int query(int pos,int ret = 1e9){ for(;pos<maxn;pos+=pos&-pos)ret = min(ret,tr[pos]); return ret; }
int L,R;
inline void ps(int x){ que[++R] = x; add(R,x); }
inline bool et(){ return L > R; }
inline int pp(){ return que[L++]; }
inline int mn(){ return query(L); }
main() {
	ios::sync_with_stdio(false),in.tie(0);
	in,n,p;
	rep(i,1,n) in,t[i],ed,rk[i] = i;
	sort(rk + 1,rk + n + 1,[](int x,int y){ return t[x] < t[y]; });
	for(int & i : tr) i = 1e9;
	ll now = 0; int pos = 1;
	std::priority_queue<int,vec<int>,greater<int>> q;
	L = 1; t[0] = -1;
	for(int i = 1,l = 1e9;i <= n;++i){
		if(et() && q.empty()) now = max(now,t[rk[pos]]);
		while(pos <= n && t[rk[pos]] == now) q.push(rk[pos++]);
		if(q.size() && q.top() < mn()) ps(q.top()),q.pop();
		while(pos <= n && t[rk[pos]] < now + p){
			q.push(rk[pos]);
			if(t[rk[pos]] != t[rk[pos + 1]]) if(q.top() < mn()) ps(q.top()),q.pop();
			++ pos;
		}
		ans[l = pp()] = now += p;
	}
	rep(i,1,n) out,ans[i],' ';
}