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

vector<vector<int>> adj;
vector<int> c, pre, pos, ans;
int t = 0, n;

void dfs(int v) {
	pre[v] = t;
	for(int u : adj[v])
		dfs(u);
	pos[v] = t++;

	int k = pre[v] + c[v];
	if(k > pos[v]) {
		cout << "NO\n";
		exit(0);
	}

	REP(i, n) {
		if(k <= ans[i] && ans[i] <= pos[v])
			ans[i]++;
	}
	ans[v] = k;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	vector<int> p(n);
	adj.resize(n);
	pre = pos = c = vector<int>(n);

	int root = -1;
	REP(i, n) {
		cin >> p[i] >> c[i];
		p[i]--;
		if(p[i] == -1) root = i;
		else adj[p[i]].emplace_back(i);
	}

	ans.resize(n, -1);
	dfs(root);

	cout << "YES\n";
	REP(i, n) cout << ans[i] + 1 << " ";
	cout << "\n";
}