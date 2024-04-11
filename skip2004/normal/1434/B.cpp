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
template<typename t>inline ostream&operator,(ostream&cout,const t&x){return cout<<x;}
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
 
int n;
int rk[N];
int p[N],vs[N];
int x[N];
char opt[N];
int main() {
	ios::sync_with_stdio(false), in.tie(0);
	std::cin>>n;
	std::priority_queue<int> q0;
	rep(i,1,n+n){
		static int c=0;
		cin>>opt[i];
		if(opt[i]=='+')q0.push(++c);
		else {
			if(q0.empty()) { puts("NO"); return 0; }
			cin>>x[i],rk[x[i]]=c,p[q0.top()]=x[i],q0.pop();
		}
	}
	rep(i,1,n)if(!p[i]){
		static int x=n;
		for(;rk[x];)--x;
		p[i]=x--;
	}
	std::priority_queue<int,std::vector<int>,std::greater<int>>q;
	rep(i,1,n+n){
		static int idx=0;
		if(opt[i]=='+')q.push(p[++idx]);
		else {
			if(q.empty()||q.top()!=x[i]){
				puts("NO");
				return 0;
			}
			q.pop();
		}
	}
	cout<<"YES"<<'\n';
	rep(i,1,n)cout<<p[i]<<" \n"[i==n];
}