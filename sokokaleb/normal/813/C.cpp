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

#define N 200005
int V, x;
vi adj[N];
int dist[2][N];

void bfs(int st, int ref[N], int isi[N]) {
	isi[st] = 0;
	queue<int> Q;
	Q.push(st);
	while (!Q.empty()) {
		int u = take(Q);
		for (const auto& v : adj[u]) {
			if (isi[v] == -1 && isi[u] + 1 < ref[v]) {
				isi[v] = isi[u] + 1;
				Q.push(v);
			}
		}
	}
	return ;
}

int depth[N];
int urutan[N];
int ans;

void dfs(int u, int par) {
	bool gerak = 0;
	urutan[depth[u]] = u;
	for (const auto& v : adj[u]) {
		if (v == par) continue ;
		depth[v] = depth[u] + 1;
		dfs(v, u);
		gerak = 1;
	}

	if (!gerak && dist[0][u] != -1 && dist[1][u] != -1) {
		int jarak = depth[u] - depth[urutan[dist[1][u]]];
		ans = max(ans, dist[1][u] * 2 + jarak * 2);
	}
	return ;
}

int main(int argc, char** argv) {
	__INIT_CC__
	cin >> V >> x;
	FOR (i, 0, V - 1) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	RESET(dist[0], -1);
	fill(dist[1], dist[1] + N, INF);
	bfs(1, dist[1], dist[0]);
	RESET(dist[1], -1);
	bfs(x, dist[0], dist[1]);

	ans = -1;
	dfs(1, -1);

	cout << ans << "\n";
}