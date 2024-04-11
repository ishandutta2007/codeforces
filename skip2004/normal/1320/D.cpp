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
const int maxn = 200200;
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
inline int popc(int a){ return __builtin_popcount(a); }
inline int popc(ll a){ return __builtin_popcountll(a); }
inline int ctz(int a){ return __builtin_ctz(a); }
inline int ctz(ll a){ return __builtin_ctzll(a); }
inline int lg2(int a){ return 31 - __builtin_clz(a); }
inline int lg2(ll a){ return 63 - __builtin_clzll(a); }
typedef long long ll;
struct mes { int last, hs; };
char s[maxn], s2[maxn];
int q;
int idx[maxn], go[maxn];
int dfn[maxn], top;
int nxt[maxn], pre[maxn];
int cnt[maxn], lol[maxn];
std::mt19937_64 rd(time(0));
ll bs[maxn];
const int base = 2333;
ll mod = []() {
	for(;;) {
		ll x = rd() % (int) 1e9 + 3e9;
		int flag = 1;
		for(ll i = 2;i * i <= x;++i) if(x % i == 0) {
			flag = 0;
			break;
		}
		if(flag) return x;
	}
}();
ll hs[maxn];
int n;
inline ll o(int l,int r) {
	return (hs[r] + (unsigned long long) (mod - hs[l - 1]) * bs[r - l + 1]) % mod;
}
inline ll get(int l,int len) {
	int r = l + len;
	if(cnt[r - 1] == cnt[l - 1]) return - 1;
	int first = nxt[l] - l & 1;
	return o(cnt[nxt[l]] + 1, cnt[pre[r - 1]]) << 1 | first;
}
int main() {
	ios::sync_with_stdio(false),cin.tie(0);
	cin >> n >> s + 1;
	*bs = 1;
	rep(i, 1, n) bs[i] = bs[i - 1] * base % mod;
	for(int i = 1, x = 0, c = 0;i <= n + 1;++i) {
		if(s[i] == '0') x = i, ++ c;
		pre[i] = x, cnt[i] = c;
	}
	for(int i = n + 1, x = n + 1;i >= 1;--i) {
		if(s[i] == '0') x = i;
		nxt[i] = x;
	}
	for(int i = 1;i <= n;++i) if(s[i] == '0') lol[cnt[i]] = i - pre[i - 1] & 1;
	rep(i, 1, n) hs[i] = (hs[i - 1] * base + lol[i] + 1) % mod;
	cin >> q;
	rep(i, 1, q) {
		int l, r, len;
		cin >> l >> r >> len;
		cout << (get(l,len)==get(r,len) ?"Yes":"No") << '\n';
	}
}