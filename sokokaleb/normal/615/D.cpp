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

#define MAX_N 200005
constexpr int MOD = 1000000007;
constexpr int MOD5 = 1000000006;
map<int, int> counter;
vii prime_factors;
int prefix[MAX_N], suffix[MAX_N];
int p, a;

int pkt(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (1LL * res * a) % MOD;
		b >>= 1;
		a = (1LL * a * a) % MOD;
	}
	return res;
}

int main(int argc, char** argv) {
	__INIT_CC__
	cin >> p;
	FOR (i, 0, p) {
		cin >> a;
		if (counter.find(a) == counter.end()) {
			counter[a] = 0;
		}
		++counter[a];
	}
	for (const auto& prime_factor : counter) {
		prime_factors.pb(prime_factor);
	}
	FOR (i, 0, SIZE(prime_factors)) {
		prefix[i] = prime_factors[i].ss + 1;
		suffix[i] = prime_factors[i].ss + 1;
	}
	FOR (i, 1, SIZE(prime_factors)) {
		prefix[i] = (1LL * prefix[i - 1] * prefix[i]) % MOD5;
	}
	FORD (i, SIZE(prime_factors) - 2, 0) {
		suffix[i] = (1LL * suffix[i + 1] * suffix[i]) % MOD5;
	}

	int ans = 1LL;
	FOR (i, 0, SIZE(prime_factors)) {
		ll mul = 1LL;
		if (i) mul = (mul * prefix[i - 1]) % MOD5;
		if (i + 1 < SIZE(prime_factors)) mul = (mul * suffix[i + 1]) % MOD5;
		int lol = 1;
		FORN (j, 0, prime_factors[i].ss) {
			ans = (1LL * ans * pkt(lol, mul)) % MOD;
			lol = (1LL * lol * prime_factors[i].ff) % MOD;
		}
	}

	cout << ans << "\n";
}