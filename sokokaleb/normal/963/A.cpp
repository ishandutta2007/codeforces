#include <bits/stdc++.h>

#define __INIT_CC__ ios::sync_with_stdio(false); \
	cin.tie(0);

#ifdef __WIN32__
	char getchar_unlocked() {return getchar();}
#endif

#define FOR(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<(_t);++(_i))
#define FORN(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<=(_t);++(_i))
#define FORD(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i>=(_t);--(_i))
#define RESET(_a,_value) memset(_a,_value,sizeof(_a))
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second
#define mp make_pair
#define SIZE(_a) (int)_a.size()
#define VSORT(_a) sort(_a.begin(),_a.end())
#define SSORT(_a,_val) sort(_a,_a+(_val))
#define ALL(_a) _a.begin(),_a.end()
#define mt make_tuple
#define _get(_tuple,_i) get<_i>(_tuple)
#define eb emplace_back
 
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll,ll>;
using vpll = vector<pll>;
using vll = vector<ll>;
using pdd = pair<double,double>;
using vpdd = vector<pdd>;
template <typename T> using uset = unordered_set<T>;
template <typename T> using umultiset = unordered_multiset<T>;
template <typename K, typename V> using umap = unordered_map<K, V>;
template <typename K, typename V> using umultimap = unordered_multimap<K, V>;

const int dr[] = { 1, 0,-1, 0, 1, 1,-1,-1};
const int dc[] = { 0, 1, 0,-1, 1,-1,-1, 1};
const double eps = 1e-9;
const int INF = 0x7FFFFFFF;
const ll INFLL = 0x7FFFFFFFFFFFFFFFLL;
const double pi = acos(-1);

template <typename T> T take(queue<T> &O) {T tmp=O.front();O.pop();return tmp;}
template <typename T> T take(stack<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <typename T> T take(priority_queue<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <typename T>
inline bool inRange(const T& z, const T& a, const T& b){return a <= z && z <= b;}

void OPEN(const string& in = "input.txt", const string& out = "output.txt")
{
	freopen(in.c_str(), "r", stdin);
	freopen(out.c_str(), "w", stdout);
	return ;
}

//using sokokaleb's template v4.0

constexpr ll MOD = 1'000'000'009;
ll ans, a, b, n, k;
string s;

ll pkt(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1LL) res = (1LL * res * a) % MOD;
		a = (1LL * a * a) % MOD;
		b >>= 1;
	}
	return res;
}

int main(int argc, char** argv) {
	__INIT_CC__
	cin >> n >> a >> b >> k >> s;
	ll tmp = 0;
	ll aa = pkt(a, n);
	ll bb = 1;
	a = pkt(a, MOD - 2);
	FOR (i, 0, k) {
		ll z = (s[i] == '+' ? 1 : -1);
		ll zz = (1LL * aa * bb) % MOD;
		tmp += 1LL * z * zz % MOD;
		tmp %= MOD;
		if (tmp < 0) tmp += MOD;
		aa = (1LL * aa * a) % MOD;
		bb = (1LL * bb * b) % MOD;
	}
	ll res = tmp;
	ll cc = (1LL * pkt(a, k) * bb) % MOD;
	if (cc == 1LL) {
		res = (1LL * res * ((n + 1) / k)) % MOD;
	} else {
		ll zz = pkt(cc, (n + 1) / k) - 1;
		zz %= MOD;
		if (zz < 0) zz += MOD;
		res = (1LL * res * zz) % MOD;
		cc -= 1;
		cc %= MOD;
		if (cc < 0) cc += MOD;
		res = (1LL * res * pkt(cc, MOD - 2)) % MOD;
	}
	cout << res << endl;
}