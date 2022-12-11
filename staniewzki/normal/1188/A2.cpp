#include<bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

template<class T> int size(T && a) {
	return a.size();
}

template<class L, class R> ostream& operator<<(ostream &out, pair<L, R> p) {
	return out << "(" << p.first << ", " << p.second << ")";
}

template<class T> auto operator<<(ostream &out, T a) -> decltype(a.begin(), out) {
	out << "{";
	for(auto it = a.begin(); it != a.end(); it = next(it))
		out << (it != a.begin() ? ", " : "") << *it;
	return out << "}";
}

void dump() { cerr << "\n"; }
template<class T, class... Ts> void dump(T a, Ts... x) {
	cerr << a << ", ";
	dump(x...);
}

#ifdef DEBUG
#  define debug(...) cerr << "[" #__VA_ARGS__ "]: ", dump(__VA_ARGS__)
#else
#  define debug(...) false
#endif

#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ST first
#define ND second

mt19937_64 _gen(chrono::system_clock::now().time_since_epoch().count());
LL rd(LL a, LL b) { return uniform_int_distribution<LL>(a, b)(_gen); }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> a(n), b(n), w(n);
	vector<vector<int>> graph(n);
	REP(i, n - 1) {
		cin >> a[i] >> b[i] >> w[i];
		a[i]--, b[i]--;
		graph[a[i]].emplace_back(b[i]);
		graph[b[i]].emplace_back(a[i]);
	}

	REP(i, n) {
		if(size(graph[i]) == 2) {
			cout << "NO\n";
			return 0;
		}
	}

	function<int(int, int)> get_leaf;
	get_leaf = [&](int v, int p) {
		for(int u : graph[v]) if(u != p)
			return get_leaf(u, v);
		return v;
	};

	int ans = 0;
	vector<int> ra, rb, rw;
	auto add_path = [&](int u, int v, int c) {
		ans++;
		ra.emplace_back(u + 1);
		rb.emplace_back(v + 1);
		rw.emplace_back(c);
	};

	auto is_leaf = [&](int v) { return size(graph[v]) == 1; };
	auto get_leaves = [&](int u, int v) {
		vector<int> ret;
		for(int x : graph[u]) {
			if(x != v) {
				ret.emplace_back(get_leaf(x, u));
				if(size(ret) == 2) return ret;
			}
		}
	};

	REP(i, n - 1) {
		if(is_leaf(a[i]) && is_leaf(b[i])) {
			add_path(a[i], b[i], w[i]);
			continue;
		}

		REP(j, 2) {
			if(is_leaf(a[i])) {
				auto leaves = get_leaves(b[i], a[i]);
				add_path(a[i], leaves[0], w[i] / 2);
				add_path(a[i], leaves[1], w[i] / 2);
				add_path(leaves[0], leaves[1], -w[i] / 2);
			}
			swap(a[i], b[i]);
		}

		if(!is_leaf(a[i]) && !is_leaf(b[i])) {
			auto leaves_a = get_leaves(a[i], b[i]);
			auto leaves_b = get_leaves(b[i], a[i]);

			add_path(leaves_a[0], leaves_b[0], w[i] / 2);
			add_path(leaves_a[1], leaves_b[1], w[i] / 2);
			add_path(leaves_a[0], leaves_a[1], -w[i] / 2);
			add_path(leaves_b[0], leaves_b[1], -w[i] / 2);
		}
	}

	cout << "YES\n";
	cout << ans << "\n";
	REP(i, ans)
		cout << ra[i] << " " << rb[i] << " " << rw[i] << "\n";
}