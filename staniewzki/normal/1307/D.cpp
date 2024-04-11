#include<bits/stdc++.h>
using namespace std;
 
ostream& operator<<(ostream &out, string str) {
	for(char c : str) out << c;
	return out;
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
 
template<class T> int size(T && a) { return a.size(); }
 
using LL = long long;
using PII = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> spec(k);
	REP(i, k) cin >> spec[i], spec[i]--;
	vector<vector<int>> adj(n);
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		adj[a - 1].emplace_back(b - 1);
		adj[b - 1].emplace_back(a - 1);
	}

	auto get_dst = [&](int s) {
		vector<int> dst(n, -1);
		dst[s] = 0;
		deque<int> Q;
		Q.emplace_back(s);

		while(!Q.empty()) {
			int v = Q.front();
			Q.pop_front();
			for(int u : adj[v]) {
				if(dst[u] == -1) {
					dst[u] = dst[v] + 1;
					Q.emplace_back(u);
				}
			}
		}
		return dst;
	};

	auto d1 = get_dst(0), dn = get_dst(n - 1);
	int path = d1[n - 1];

	vector<vector<int>> q(n);
	for(int i : spec) {
		q[d1[i]].emplace_back(dn[i]);
	}

	int worst = 0;
	int min_h = n + 1, max_i = -n;
	REP(i, n) {
		sort(q[i].begin(), q[i].end());
		for(int j : q[i]) {
			if(min_h <= j) {
				cout << path << "\n";
				return 0;
			}
			int val = max_i + j + 1;
			worst = max(val, worst);
			min_h = j;
			max_i = i;
		}
	}

	cout << min(path, worst) << "\n";
}