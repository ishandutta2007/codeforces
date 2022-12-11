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
vector<PII> c;
vector<int> pre, pos, l;
int t = -1;

void dfs(int v = 0, int p = -1) {
	pre[v] = ++t;
	for(int u : adj[v]) if(u != p) dfs(u, v);
	if(size(adj[v]) == 1 && p != -1)
		l.emplace_back(pre[v]);
	pos[v] = t;
}

vector<int> rep;
int find(int x) {
	return rep[x] == x ? x : rep[x] = find(rep[x]);
}

void join(int x, int y) {
	x = find(x), y = find(y);
	rep[x] = y;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	c.resize(n);
	REP(i, n) {
		cin >> c[i].ST;
		c[i].ND = i;
	}

	adj.resize(n);
	REP(i, n - 1) {
		int a, b;
		cin >> a >> b;
		adj[a - 1].emplace_back(b - 1);
		adj[b - 1].emplace_back(a - 1);
	}

	pre = pos = vector<int>(n);
	dfs();

	l.emplace_back(n);
	sort(l.begin(), l.end());

	REP(v, n) {
		pre[v] = *lower_bound(l.begin(), l.end(), pre[v]);
		pos[v] = *upper_bound(l.begin(), l.end(), pos[v]);
		debug(pre[v], pos[v]);
	}

	sort(c.begin(), c.end());
	rep.resize(n + 1);
	REP(i, n + 1) rep[i] = i;

	vector<int> ans, stk;
	int last = -1;
	LL cost = 0;
	REP(i, n + 1) {
		if(i == n || c[i].ST != last) {
			for(int j : stk) {
				int v = c[j].ND;
				if(find(pre[v]) != find(pos[v])) {
					cost += c[j].ST;
					join(pre[v], pos[v]);
				}
			}
			stk.clear();
		}
		if(i != n) {
			int v = c[i].ND;
			if(find(pre[v]) != find(pos[v])) {
				ans.emplace_back(c[i].ND + 1);
				stk.emplace_back(i);
				last = c[i].ST;
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << cost << " " << size(ans) << "\n";
	for(int i : ans) cout << i << " ";
	cout << "\n";
}