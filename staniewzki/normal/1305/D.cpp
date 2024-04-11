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

	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	REP(i, n - 1) {
		int a, b;
		cin >> a >> b;
		adj[a - 1].emplace_back(b - 1);
		adj[b - 1].emplace_back(a - 1);
	}

	vector<int> deg(n), leaves;

	REP(i, n) {
		deg[i] = size(adj[i]);
		if(deg[i] == 1) leaves.emplace_back(i);
	}

	auto query = [&](int a, int b) {
		cout << "? " << a + 1 << " " << b + 1 << endl;
		int resp;
		cin >> resp;
		return resp - 1;
	};

	auto ans = [&](int a) {
		cout << "! " << a + 1 << endl;
		exit(0);
	};

	while(size(leaves) >= 2) {
		int u = leaves.back();
		leaves.pop_back();
		int v = leaves.back();
		leaves.pop_back();

		int q = query(u, v);
		if(q == u) ans(u);
		if(q == v) ans(v);

		auto prop = [&](int x) {
			for(int y : adj[x])
				if(--deg[y] == 1)
					leaves.emplace_back(y);
		};

		prop(u);
		prop(v);
	}

	ans(leaves.back());
}