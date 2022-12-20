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

constexpr int MAXN = 200'010;
int dp[MAXN][2];
int S[MAXN], C[MAXN];
int base_parity[MAXN];

vi adj[MAXN];
int n;

int f(int u, int p) {
	if (u == -1) {
		return p == 0;
	}
	int& res = dp[u][p];
	if (res != -1) return res;
	res = 0;
	// ancurin duluan
	res |= f(S[u], p ^ 1) && f(C[u], base_parity[u]);
	// ancurin belakangan
	res |= f(S[u], p) && f(C[u], base_parity[u] ^ 1);
	return res;
}

void dfs(int u, int par = -1) {
	int lst = -1;
	for (const auto& v : adj[u]) {
		if (v == par) continue;
		dfs(v, u);
		if (lst == -1) {
			C[u] = v;
		} else {
			S[lst] = v;
		}
		lst = v;
	}
}

vi ans;
bitset<MAXN> flags;

void bt(int u, int p, int par = -1) {
	if (u == -1) return;
	const int& res = dp[u][p];
	if (f(S[u], p ^ 1) && f(C[u], base_parity[u])) {
		flags.set(u, 1);
		bt(S[u], p ^ 1);
		bt(C[u], base_parity[u]);
		return;
	}
	bt(S[u], p);
	bt(C[u], base_parity[u] ^ 1);
}

queue<int> Q;

void bt_jawab(int u, int par = -1) {
	for (const auto& v : adj[u]) {
		if (v == par) continue;
		if (flags.test(v)) {
			bt_jawab(v, u);
		}
	}
	cout << u + 1 << "\n";
	for (const auto& v : adj[u]) {
		if (v == par) continue;
		if (!flags.test(v)) {
			bt_jawab(v, u);
		}
	}
}

int main(int argc, char** argv) {
	__INIT_CC__
	RESET(dp, -1);
	RESET(C, -1);
	RESET(S, -1);

	cin >> n;

	if (n == 1) {
		cout << "YES\n1\n";
		return 0;
	}

	FOR (i, 0, n) {
		int p;
		cin >> p;
		if (p == 0);
		else {
			--p;
			adj[p].pb(i);
			adj[i].pb(p);
		}
	}
	FOR (i, 0, n) base_parity[i] = SIZE(adj[i]) & 1;
	dfs(0);

	if (!f(C[0], base_parity[0])) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	flags.reset();
	bt(C[0], base_parity[0], 0);
	bt_jawab(0);
}