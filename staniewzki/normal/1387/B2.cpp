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

vector<vector<int>> adj;
vector<int> sub, dep, comp;
void dfs(int v = 0, int p = -1) {
	comp.emplace_back(v);
	for(int u : adj[v]) if(u != p) {
		dep[u] = dep[v] + 1;
		dfs(u, v);
		sub[v] += sub[u];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	adj.resize(n);
	REP(i, n - 1) {
		int a, b;
		cin >> a >> b;
		adj[a - 1].emplace_back(b - 1);
		adj[b - 1].emplace_back(a - 1);
	}

	auto get_centro = [&]() {
		REP(v, n) {
			bool good = true;
			for(int u : adj[v]) {
				if(sub[u] > sub[v]) {
					if((n - sub[v]) * 2 > n)
						good = false;
				}
				else {
					if(sub[u] * 2 > n)
						good = false;
				}
			}
			if(good) return v;
		}
		assert(false);
	};

	sub = dep = vector<int>(n, 1);
	dfs();
	int centro = get_centro();
	dep = vector<int>(n);
	dfs(centro);

	LL ans = 0;
	REP(i, n) ans += dep[i] * 2;

	vector<vector<int>> under = {{centro}};
	vector<int> resp(n);
	for(int v : adj[centro]) {
		comp.clear();
		dfs(v, centro);
		for(int u : comp)
			resp[u] = size(under);
		under.emplace_back(comp);
	}

	vector<int> out(n);
	priority_queue<PII> Q;
	REP(i, size(under)) 
		Q.emplace(size(under[i]), i);

	for(int i = n; i >= 2; i -= 2) {
		if(i != 3) {
			auto a = Q.top(); Q.pop();
			auto b = Q.top(); Q.pop();
			int x = under[a.ND].back(); under[a.ND].pop_back();
			int y = under[b.ND].back(); under[b.ND].pop_back();
			out[x] = y;
			out[y] = x;
			Q.emplace(a.ST - 1, a.ND);
			Q.emplace(b.ST - 1, b.ND);
		}
		else {
			auto a = Q.top(); Q.pop();
			auto b = Q.top(); Q.pop();
			auto c = Q.top(); Q.pop();
			int x = under[a.ND].back(); under[a.ND].pop_back();
			int y = under[b.ND].back(); under[b.ND].pop_back();
			int z = under[c.ND].back(); under[c.ND].pop_back();
			out[x] = y;
			out[y] = z;
			out[z] = x;
			Q.emplace(a.ST - 1, a.ND);
			Q.emplace(b.ST - 1, b.ND);
			Q.emplace(c.ST - 1, c.ND);
		}
	}

	REP(i, n) assert(resp[i] != resp[out[i]]);
	// cout << "OK\n";
	cout << ans << "\n";
	REP(i, n) cout << out[i] + 1 << " ";
	cout << "\n";
}