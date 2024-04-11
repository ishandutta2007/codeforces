#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(v) (v).begin(),(v).end()
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
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
std::map<int, int> mp[maxn],L[maxn];
int dis[maxn];
vec<int> v[maxn];
queue<int> q;
void link(int x,int y){
	v[y].push_back(x);
}
int x[maxn], y[maxn], fr[maxn], n, m;
int main() {
	ios::sync_with_stdio(false),cin.tie(0);
	cin >> n >> m;
	rep(i, 1, m) {
		cin >> x[i] >> y[i];
		link(x[i], y[i]);
	}
	std::queue<int> q;
	vec<int> vec; int k; in,k;
	rep(i,1,k){
		int x;in,x,ed,vec.pb(x);
	}
	rep(i,1,n)dis[i]=1e9;
	dis[vec.back()]=0; q.push(vec.back());
	for(;!q.empty();){
		int t = q.front();q.pop();
		for(int i : v[t]){
			if(dis[i] > dis[t] + 1) {
				dis[i] = dis[t] + 1;
				mp[i][t] = 1;
				L[i][t] = 1;
				q.push(i);
				fr[i]=t;
			} else {
				if(dis[i] == dis[t] + 1) {
					mp[i][t] = 1;
					L[i][t] = 0;
					L[i][fr[i]] = 0;
				}
			}
		}
	}
	int lol = 0, lp = 0;
	for(int i = 1;i < vec.size();++i) {
		lol+=!mp[vec[i-1]][vec[i]];
		lp+=L[vec[i-1]][vec[i]];
	}
	out,lol,' ',vec.size()-lp-1,'\n';
}