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

int b;
ll dp[65][11][1 << 10];
int len;
int nums[65];

inline void add(ll& res, ll val) {
	res += val;
}

ll fdp(int sisa, int b, int mask) {
	if (sisa < 0) return 0;
	ll& res = dp[sisa][b][mask];
	if (res != -1) return res;
	if (sisa == 0) {
		res = (mask == 0 ? 1 : 0);
		return res;
	}
	res = 0;

	FORN (i, 0, b - 1) {
		add(res, fdp(sisa - 1, b, mask ^ (1 << i)));
	}

	return res;
}

ll dpfull[11][65];

ll full(int b, int len) {
	ll& res = dpfull[b][len];
	if (res != -1) return res;
	res = 0;
	FORD (i, len - 1, 1) {
		if (i & 1) {
			FORN (dig, 1, b - 1) {
				add(res, fdp(i, b, 1 << dig));
			}
		}
	}
	return res;
}

ll process(ll x) {
	len = 0;
	while (x || len == 0) {
		nums[len++] = x % b;
		x /= b;
	}
	reverse(nums, nums + len);
	ll res = 0;
	add(res, full(b, len - 1));

	int mask = 0;
	int digits = len;
	FOR (i, 0, len) {
		--digits;
		// less
		FOR (j, (i == 0 ? 1 : 0), nums[i]) {
			mask ^= 1 << j;
			add(res, fdp(digits, b, mask));
			mask ^= 1 << j;
		}
		mask ^= 1 << nums[i];
	}
	add(res, fdp(0, b, mask));
	return res;
}

int main(int argc, char** argv) {
	__INIT_CC__

	RESET(dp, -1);
	RESET(dpfull, -1);

	int n;
	cin >> n;
	FORN (tc, 1, n) {
		cin >> b;
		ll x, y;
		cin >> x >> y;
		--x;

		ll ans = process(y);
		ans -= process(x);

		cout << ans << "\n";
	}
}