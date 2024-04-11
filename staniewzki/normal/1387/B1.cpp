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
int ans = 0;
vector<int> out;

void dfs(int v = 0, int p = -1) {
	vector<int> s;
	int son = -1;
	for(int u : adj[v]) if(u != p) {
		son = u;
		dfs(u, v);
		if(out[u] == u)
			s.emplace_back(u);
	}

	for(int i = 0; i + 1 < size(s); i += 2) {
		out[s[i]] = s[i + 1];
		out[s[i + 1]] = s[i];
		ans += 4;
	}

	if(size(s) % 2) {
		out[v] = s.back();
		out[s.back()] = v;
		ans += 2;
	}

	if(out[v] == v && size(s))
		swap(out[s[0]], out[v]);

	if(out[v] == v && p == -1) {
		swap(out[v], out[son]);
		ans += 2;
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

	out.resize(n);
	REP(i, n) out[i] = i;
	dfs();

	cout << ans << "\n";
	REP(i, n) cout << out[i] + 1 << " ";
	cout << "\n";
}