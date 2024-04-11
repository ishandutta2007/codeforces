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
const int mod = 1e9 + 7, maxn = 300200;
mt19937 rd(time(0));
inline void flush(){cout.flush();fflush(stdout);}
#define def(a,b) using a = b
def(u64,unsigned long long);def(u32,unsigned);def(ll,long long);
def(ld,long double);def(db,double);def(str,string);
using pr = pair<int,int>;
#define tree tr
struct TEMP6_AK{} ed;
template<typename t>using vec=vector<t>;
template<typename t>using heap=__gnu_pbds::priority_queue<t>;
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
int p[maxn], q[maxn];
int ip[maxn];
struct fc {
	ll add, tag;
	// x -> max(x + add, x)
}a[maxn],tree[maxn<<2];
inline fc mg(fc x, fc y) {
	// max(max(x + adx, tgx) + ady, tgy)
	return {x.add + y.add, std::max(x.tag + y.add, y.tag)};
}
inline void upt(int pos,int cur=1,int l=1,int r=n){
	if(l==r)return void(tree[cur]=a[pos]);
	int mid=l+r>>1;
	pos<=mid?upt(pos,cur<<1,l,mid):upt(pos,cur<<1|1,mid+1,r);
	tree[cur]=mg(tree[cur<<1],tree[cur<<1|1]);
}
int main() {
	ios::sync_with_stdio(false),cin.tie(0);
	cin >> n;
	rep(i, 1, n) {
		cin >> p[i];
		ip[p[i]]=i;
	}
	int max = n;
	++a[ip[n]].add,upt(ip[n]);
	rep(i, 1, n-1) {
		out,max,'\n';
		cin>>q[i];
		--a[q[i]].add;
		upt(q[i]);
		for(;tree[1].add<1&&tree[1].tag<1;) {
			--max;
			++a[ip[max]].add,upt(ip[max]);
		}
	}
	out,max,'\n';
}