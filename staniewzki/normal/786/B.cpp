#include<bits/stdc++.h>
using namespace std;
 
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ST first
#define ND second
 
ostream& operator<<(ostream &out, string str) {
	for(char c : str) out << c;
	return out;
}
 
template<class L, class R> ostream& operator<<(ostream &out, pair<L, R> p) {
	return out << "(" << p.ST << ", " << p.ND << ")";
}

template<class T> auto operator<<(ostream &out, T &&x) -> decltype(x.begin(), out) {
	out << '{';
	for(auto &e : x)
        	out << e << (&e == &*--x.end() ? "" : ", ");
	return out << '}';
}

template<class... Args> void dump(Args&&... args) {
	((cerr << args << ";  "), ...);
}
 
#ifdef DEBUG
#  define debug(x...) cerr << "[" #x "]: ", dump(x), cerr << "\n"
#else
#  define debug(...) false
#endif
 
template<class T> int size(T && a) { return (int) a.size(); }
 
using LL = long long;
using PII = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q, s;
	cin >> n >> q >> s;
	s--;

	int sz = 1;
	while(sz < n)
		sz *= 2;

	vector<vector<PII>> adj(sz * 4);
	REP(i, n)
		adj[i + 3 * sz].emplace_back(i + sz, 0);

	for(int i = 2 * sz - 1; i >= 2; i--) {
		adj[i].emplace_back(i / 2, 0);
		adj[i / 2 + 2 * sz].emplace_back(i + 2 * sz, 0);
	}

	REP(i, q) {
		int t;
		cin >> t;
		if(t == 1) {
			int v, u, w;
			cin >> v >> u >> w;
			u--, v--;
			adj[v + sz].emplace_back(u + 3 * sz, w);
		}
		else if(t == 2) {
			int v, l, r, w;
			cin >> v >> l >> r >> w;
			v--, l--, r--;
			l += sz, r += sz;
			adj[v + sz].emplace_back(l + 2 * sz, w);
			adj[v + sz].emplace_back(r + 2 * sz, w);
			while(l + 1 < r) {
				if(l % 2 == 0)
					adj[v + sz].emplace_back(l + 1 + 2 * sz, w);
				if(r % 2 == 1)
					adj[v + sz].emplace_back(r - 1 + 2 * sz, w);
				l /= 2, r /= 2;
			}
		}
		else if(t == 3) {
			int v, l, r, w;
			cin >> v >> l >> r >> w;
			v--, l--, r--;
			l += sz, r += sz;
			adj[l].emplace_back(v + 3 * sz, w);
			adj[r].emplace_back(v + 3 * sz, w);
			while(l + 1 < r) {
				if(l % 2 == 0)
					adj[l + 1].emplace_back(v + 3 * sz, w);
				if(r % 2 == 1)
					adj[r - 1].emplace_back(v + 3 * sz, w);
				l /= 2, r /= 2;
			}
		}
	}

	LL inf = 1e18;
	vector<LL> dst(sz * 4, inf);
	priority_queue<pair<LL, int>> Q;
	dst[s + sz] = 0;
	Q.emplace(0, s + sz);
	while(!Q.empty()) {
		auto [d, v] = Q.top();
		Q.pop();

		if(dst[v] != -d) continue;
		for(auto &[u, w] : adj[v]) {
			debug(u, w);
			if(dst[v] + w < dst[u]) {
				dst[u] = dst[v] + w;
				Q.emplace(-dst[u], u);
			}
		}
	}

	REP(i, n) cout << (dst[i + sz] == inf ? -1 : dst[i + sz]) << " ";
	cout << "\n";
}