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

constexpr int dr[] = { 1, 0,-1, 0, 1, 1,-1,-1};
constexpr int dc[] = { 0, 1, 0,-1, 1,-1,-1, 1};
constexpr double eps = 1e-9;
constexpr int kInf = 0x7FFFFFFF;
constexpr ll kInfll = 0x7FFFFFFFFFFFFFFFLL;
constexpr double pi = acos(-1);

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

//using sokokaleb's template v5.0

constexpr int MAX_N = 300'005;
int cnt[3], len[3];
ii vec[MAX_N];
int val[3][MAX_N];
ll ans;

inline ll calc(ll a, ll b, ll c) {
	ll x = (a - b), y = (b - c), z = (c - a);
	return x * x + y * y + z * z;
}

inline void check(int a, int b, int c, int lvalue, int rvalue) {
	if (cnt[a] == 1 && cnt[b] == 1) {
		int mid = lvalue + ((rvalue - lvalue) >> 1);
		auto it = lower_bound(val[c], val[c] + len[c], mid);
		if (it != (val[c] + len[c])) {
			ans = min(ans, calc(lvalue, rvalue, *it));
		}
		if (it > val[c]) {
			--it;
			ans = min(ans, calc(lvalue, rvalue, *it));
		}
	}
}

void solve() {
	int N;
	ii* ptr_read = vec;
	FOR (i, 0, 3) {
		cin >> len[i];
	}
	FOR (i, 0, 3) {
		FOR (j, 0, len[i]) {
			cin >> val[i][j];
			ptr_read->first = val[i][j];
			ptr_read->second = i;
			++ptr_read;
		}
	}
	N = len[0] + len[1] + len[2];
	SSORT(vec, N);
	FOR (i, 0, 3) {
		SSORT(val[i], len[i]);
		cnt[i] = 0;
	}
	ans = kInfll;
	ii* l = vec;
	ii* r = vec;
	const ii* ujung = vec + N;
	bool mov = true;
	while (r < ujung) {
		++cnt[r->second];
		++r;
		if (cnt[0] == 0 || cnt[1] == 0 || cnt[2] == 0) continue;
		while (l < r && cnt[l->second] - 1 > 0) {
			--cnt[l->second];
			++l;
		}
		check(0, 1, 2, l->first, (r - 1)->first);
		check(0, 2, 1, l->first, (r - 1)->first);
		check(1, 2, 0, l->first, (r - 1)->first);
	}
	cout << ans << "\n";
}

int main(int argc, char** argv) {
	__INIT_CC__
	int T;
	cin >> T;
	FORN (tc, 1, T) {
		solve();
	}
}