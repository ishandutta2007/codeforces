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

	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(n);
	vector<PII> edges(m);
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
		edges[i] = {a, b};
	}

	vector<int> id(n, -1);
	int cnt = 0;
	vector<int> sz;
	REP(i, n) {
		if(id[i] == -1) {
			if(cnt == 3) {
				cout << "-1\n";
				return 0;
			}
			vector<bool> adj(n);
			for(int u : graph[i])
				adj[u] = true;
			sz.emplace_back();
			REP(j, n)
				if(!adj[j])
					id[j] = cnt, sz.back()++;
			cnt++;
		}
	}

	if(size(sz) != 3) {
		cout << "-1\n";
		return 0;
	}

	LL needed = 0;
	REP(i, 3) {
		int j = (i + 1) % 3;
		needed += (LL) sz[i] * sz[j];
	}

	if(m != needed) {
		cout << "-1\n";
		return 0;
	}

	for(PII p : edges) {
		if(id[p.ST] == id[p.ND]) {
			cout << "-1\n";
			return 0;
		}
	}

	REP(i, n)
		cout << id[i] + 1 << " ";
	cout << "\n";
}