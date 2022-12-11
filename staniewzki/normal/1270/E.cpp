#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2")
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

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
int rd(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> x(n), y(n);
	REP(i, n) cin >> x[i] >> y[i];

	vector<LL> w;
	vector<vector<PII>> e;
	map<LL, int> S;
	map<LL, bool> used;

	REP(i, n) REP(j, n) {
		LL _x = x[i] - x[j];
		LL _y = y[i] - y[j];
		LL d = _x * _x + _y * _y;
		if(S.find(d) == S.end()) {
			S[d] = size(e);
			e.emplace_back();
		}

		int id = S[d];
		e[id].emplace_back(i, j);
		w.emplace_back(d);	
	}

	while(true) {
		LL x = w[rd(0, size(w) - 1)];
		while(used[x]) {
			x = w[rd(0, size(w) - 1)];
		}
		used[x] = true;

		vector<vector<int>> graph(n);
		int id = S[x];
		for(PII p : e[id]) {
			int i, j;
			tie(i, j) = p;
			graph[i].emplace_back(j);
			graph[j].emplace_back(i);
		}
		
		vector<int> col(n, -1);
		bool good = true;
		REP(i, n) {
			if(col[i] == -1) {
				vector<int> Q = {i};
				col[i] = 0;

				while(!Q.empty()) {
					int v = Q.back();
					Q.pop_back();

					for(int u : graph[v]) {
						if(col[u] == -1) {
							col[u] = col[v] ^ 1;
							Q.emplace_back(u);
						}
						else if(col[u] == col[v]) {
							good = false;
							break;
						}
					}

					if(!good) break;
				}
			}

			if(!good) break;
		}

		if(!good) continue;

		for(auto &v : e) {
			int q = -1;
			for(PII p : v) {
				int x = col[p.ST] ^ col[p.ND];
				if(q == -1) q = x;
				if(q != x) {
					good = false;
					break;
				}
			}

			if(!good) break;
		}

		if(!good) continue;

		int cnt = 0;
		REP(i, n) if(col[i]) cnt++;
		cout << cnt << "\n";
		REP(i, n) if(col[i]) cout << i + 1 << " ";
		cout << "\n";
		return 0;
	}
}