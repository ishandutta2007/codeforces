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

vector<array<int, 3>> trie = {{0, 0, 0}};

void add(int val) {
	int pos = 0;
	for(int i = 30 - 1; i >= 0; i--) {
		bool x = (val & (1 << i));
		if(!trie[pos][x]) {
			trie[pos][x] = size(trie);
			trie.emplace_back();
			trie.back()[2] = trie[pos][2] + (1 << i) * x;
		}
		pos = trie[pos][x];
	}
}

LL inf = 1e18;
LL find(int a, int b) {
	if(!a || !b) return inf;
	LL ret = inf;	
	REP(j, 2) {
		REP(i, 2) ret = min(ret, find(trie[a][i], trie[b][i ^ j]));
		if(ret != inf) return ret;
	}
	return trie[a][2] ^ trie[b][2];
}

LL dfs(int v) {
	LL ret = 0;
	REP(i, 2) if(trie[v][i])
		ret += dfs(trie[v][i]);
	LL x = find(trie[v][0], trie[v][1]);
	if(x != inf) ret += x;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	REP(i, n) {
		int x;
		cin >> x;
		add(x);
	}

	cout << dfs(0) << "\n";
}