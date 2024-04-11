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

	int n, m;
	cin >> n >> m;
	vector<vector<PII>> adj(n);
	REP(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a - 1].emplace_back(b - 1, c * 2);
		adj[b - 1].emplace_back(a - 1, c * 2);
	}

	bool defined;
	int x;
	vector<int> rel(n), sign(n), ans(n), comp;
	function<void(int)> dfs = [&](int v) {
		comp.emplace_back(v);
		for(auto &[u, w] : adj[v]) {
			if(!sign[u]) {
				sign[u] = -sign[v];
				rel[u] = w - rel[v];
				dfs(u);
			}
			else {
				if(sign[u] != sign[v] && rel[u] + rel[v] != w)
					cout << "NO\n", exit(0);
				else if(sign[u] == sign[v]) {
					int _x = (w - rel[u] - rel[v]) / (2 * sign[v]);
					if(defined && x != _x)
						cout << "NO\n", exit(0);
					defined = true, x = _x;
				}
			}
		}
	};


	REP(i, n) {
		if(sign[i] == 0) {
			comp.clear();
			defined = x = false;
			sign[i] = +1;
			dfs(i);

			if(defined) {
				for(int j : comp)
					ans[j] = rel[j] + sign[j] * x;
			}
			else {
				vector<int> s;
				for(int j : comp)
					s.emplace_back(rel[j] * sign[j]);
				sort(s.begin(), s.end());
				x = -s[size(s) / 2];
				for(int j : comp)
					ans[j] = rel[j] + sign[j] * x;
			}
		}
	}


	cout << "YES\n";
	REP(i, n) 
		cout << (double) ans[i] / 2 << " ";
	cout << "\n";
}