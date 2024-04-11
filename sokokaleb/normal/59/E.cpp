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

#define MAX_N 3005
int dizt[MAX_N][MAX_N];
int bef[MAX_N][MAX_N];

using tiii = tuple<int, int, int>;
set<tiii> forbid;
int n, m, k;
vi adj[MAX_N];

using tii = tuple<int, int>;
queue<tii> Q;

int main(int argc, char** argv) {
	__INIT_CC__
	cin >> n >> m >> k;
	FOR (i, 0, m) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	FOR (i, 0, k) {
		int a, b, c;
		cin >> a >> b >> c;
		forbid.insert(mt(a, b, c));
	}

	FORN (i, 1, n) {
		FORN (j, 1, n) {
			dizt[i][j] = INF;
		}
	}

	dizt[1][1] = 0;
	Q.push(mt(1, 1));
	int ansu, ansv = -1;
	while (!Q.empty()) {
		int t, u;
		tie(t, u) = take(Q);
		if (u == n) {
			tie(ansu, ansv) = mt(t, u);
			break ;
		}
		for (const auto& v : adj[u]) {
			if (forbid.find(mt(t, u, v)) == forbid.end() && dizt[t][u] + 1 < dizt[u][v]) {
				dizt[u][v] = dizt[t][u] + 1;
				bef[u][v] = t;
				Q.push(mt(u, v));
			}
		}
	}

	if (ansv == -1) {
		cout << -1 << "\n";
		return 0;
	}

	cout << dizt[ansu][ansv] << "\n";
	vi trace;
	trace.pb(ansv);
	while (ansv != 1) {
		tie(ansu, ansv) = mt(bef[ansu][ansv], ansu);
		trace.pb(ansv);
	}
	reverse(ALL(trace));
	FOR (i, 0, SIZE(trace)) {
		if (i) cout << ' ';
		cout << trace[i];
	}
	cout << '\n';
	return 0;
}