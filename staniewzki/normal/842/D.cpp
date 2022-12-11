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

vector<array<int, 2>> trie;
vector<int> cnt;

int add_node() {
	trie.emplace_back(array<int, 2>{{0, 0}});
	cnt.emplace_back();
	return size(trie) - 1;
}

int bits = 20;

int add_number(int val) {
	int pos = 0;
	for(int i = bits - 1; i >= 0; i--) {
		debug(i, pos, val);
		bool q = val & (1 << i);
		if(trie[pos][q] == 0) trie[pos][q] = add_node();
		pos = trie[pos][q];
		cnt[pos]++;
	}
}

int get(int val) {
	debug(val);
	int pos = 0, ret = 0;
	for(int i = bits - 1; i >= 0; i--) {
		bool q = val & (1 << i);
		int u = trie[pos][q];
		debug(q, trie[pos], cnt[u]);
		if(u == 0) return ret;
		if(cnt[u] == (1 << i)) {
			u = trie[pos][1 ^ q];
			ret += (1 << i);
		}
		if(u == 0) return ret;
		pos = u;
	}
	return ret;
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	add_node();

	vector<int> a(n);
	REP(i, n) cin >> a[i];
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	REP(i, size(a)) add_number(a[i]);

	int cur_xor = 0;
	REP(i, m) {
		int x;
		cin >> x;
		cur_xor ^= x;
		cout << get(cur_xor) << "\n";
	}
}