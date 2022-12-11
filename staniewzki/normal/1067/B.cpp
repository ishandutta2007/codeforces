#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define REP(i, n) FOR(i, 0, (n) - 1)
template<class T> int size(T &&x) {
	return int(x.size());
}
template<class A, class B> ostream& operator<<(ostream &out, const pair<A, B> &p) {
	return out << '(' << p.first << ", " << p.second << ')';
}
ostream& operator<<(ostream &out, string str) {
	for(char c : str) out << c;
	return out;
}
template<class T> auto operator<<(ostream &out, T &&x) -> decltype(x.begin(), out) {
	out << '{';
	for(auto it = x.begin(); it != x.end(); ++it)
		out << *it << (it == --x.end() ? "" : ", ");
	return out << '}';
}
void dump() {}
template<class T, class... Args> void dump(T &&x, Args... args) {
	cerr << x << ";  ";
	dump(args...);
}
#ifdef DEBUG
  const int seed = 1;
  struct Nl{~Nl(){cerr << '\n';}};
# define debug(x...) cerr << (#x != "" ? #x ":  " : ""), dump(x), Nl(), cerr
#else
  const int seed = chrono::system_clock::now().time_since_epoch().count();
# define debug(...) 0 && cerr
#endif
mt19937_64 rng(seed);
int rd(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

vector<vector<int>> graph;
vector<int> dist;

void dfs(int v, int p = -1) {
	if(p == -1) dist[v] = 0;
	for(int u : graph[v]) if(u != p) {
		dist[u] = dist[v] + 1;
		dfs(u, v);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	if(n == 1) {
		cout << "No\n";
		return 0;
	}

	graph.resize(n);
	REP(i, n - 1) {
		int u, v;
		cin >> u >> v;
		graph[u - 1].emplace_back(v - 1);
		graph[v - 1].emplace_back(u - 1);
	}

	dist.resize(n);
	auto get = [&](int v) {
		int max_d = 0, ret = -1;
		dfs(v);
		REP(i, n) {
			if(max_d < dist[i]) {
				max_d = dist[i];
				ret = i;
			}
		}
		return ret;
	};

	int a = get(0);
	int b = get(a);
	int r = dist[b];

	if(r % 2 == 1) {
		cout << "No\n";
		return 0;
	}

	dfs(a);
	auto dist_a = dist;
	dfs(b);
	auto dist_b = dist;

	int m = -1;
	REP(i, n) {
		if(dist_a[i] == r / 2 && dist_b[i] == r / 2) {
			m = i;
			break;
		}
	}

	debug(m);

	dfs(m);
	REP(i, n) {
		if(size(graph[i]) == 1 && dist[i] != k) {
			cout << "No\n";
			return 0;
		}

		if(i != m && size(graph[i]) != 1 && size(graph[i]) <= 3) {
			cout << "No\n";
			return 0;
		}

		if(i == m && size(graph[i]) < 3) {
			cout << "No\n";
			return 0;
		}
	}

	cout << "Yes\n";
}