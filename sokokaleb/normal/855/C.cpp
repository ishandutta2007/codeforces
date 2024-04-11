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

const int MAX_V = 100005;
const int MOD = 1000000007;
int dp[MAX_V][3][11]; // -1, 0, 1
int kurang, lebih;
int child[MAX_V], sibling[MAX_V];
vi adj[MAX_V];
int V, M;

void add(int& res, int val) {
	res += val;
	if (res >= MOD) res -= MOD;
	if (res < 0) res += MOD;
}

int f(int, int, int);

void debug(int a, int b, int c) {
	cerr << f(a, b, c) << "\n";
}

int f(int u, int par, int xleft) {
	int& res = dp[u][par + 1][xleft];
	if (res != -1) return res;

	int& _c = child[u];
	int& _s = sibling[u];
	res = 0;

	if (_c != -1 && _s != -1) {
		FORN (x, 0, xleft) {
			if (kurang > 0) {
				add(res, 1LL * kurang * f(_c, -1, x) % MOD * f(_s, par, xleft - x) % MOD);
			}
			if (lebih != 0 && (par == -1 || par == 1)) {
				add(res, 1LL * lebih * f(_c, 1, x) % MOD * f(_s, par, xleft - x) % MOD);
			}
			if (x > 0) {
				if (par == -1) {
					add(res, 1LL * f(_c, 0, x - 1) * f(_s, par, xleft - x) % MOD);
				}
			}
		}
	} else if (_c != -1) {
		if (kurang != 0) {
			add(res, 1LL * kurang * f(_c, -1, xleft) % MOD);
		}
		if (lebih != 0 && (par == -1 || par == 1)) {
			add(res, 1LL * lebih * f(_c, 1, xleft) % MOD);
		}
		if (xleft > 0) {
			if (par == -1) {
				add(res, 1LL * f(_c, 0, xleft - 1));
			}
		}
	} else if (_s != -1) {
		if (kurang != 0) {
			add(res, 1LL * kurang * f(_s, par, xleft) % MOD);
		}
		if (lebih != 0 && (par == -1 || par == 1)) {
			add(res, 1LL * lebih * f(_s, par, xleft) % MOD);
		}
		if (xleft > 0) {
			if (par == -1) {
				add(res, 1LL * f(_s, par, xleft - 1));
			}
		}
	} else {
		if (xleft == 0) {
			add(res, kurang);
		}
		if (par == -1 || par == 1) {
			if (xleft == 0) {
				add(res, lebih);
			}
		}
		if (xleft == 1) {
			if (par == -1) {
				add(res, 1);
			}
		}
	}

	return res;
}

void parsib(int u, int par) {
	int lst = -1;
	for (const auto& v : adj[u]) {
		if (v == par) continue ;
		if (lst == -1) {
			child[u] = v;
			//cerr << "CHILD " << u << " = " << v << endl;
		} else {
			sibling[lst] = v;
			//cerr << "SIBLING " << lst << " = " << v << endl;
		}
		parsib(v, u);
		lst = v;
	}
	return ;
}

int main(int argc, char** argv) {
	__INIT_CC__
	cin >> V >> M;
	FOR (i, 0, V - 1) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	RESET(dp, -1);
	RESET(child, -1);
	RESET(sibling, -1);
	int k, x;
	cin >> k >> x;
	kurang = k - 1;
	lebih = M - k;
	parsib(1, -1);

	int ans = 0;
	FORN (i, 0, x) {
		add(ans, f(1, -1, i));
	}
	cout << ans << "\n";
}