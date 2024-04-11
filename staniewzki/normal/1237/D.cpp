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

struct Tree {
	using T = int;
	T f(T a, T b) { return min(a, b); }
	vector<T> nodes;
	int size = 1;

	Tree(int n, T val = 0) {
		while(size < n) size *= 2;
		nodes.resize(size * 2, val);
	}

	void update(int pos, T val) {
		nodes[pos += size] = val;
		while(pos /= 2)
			nodes[pos] = f(nodes[pos * 2], nodes[pos * 2 + 1]);
	}

	T query(int l, int r) {
		l += size, r += size;
		T ret = (l != r ? f(nodes[l], nodes[r]) : nodes[l]);
		while(l + 1 < r) {
			if(l % 2 == 0)
				ret = f(ret, nodes[l + 1]);
			if(r % 2 == 1)
				ret = f(ret, nodes[r - 1]);
			l /= 2, r /= 2;
		}
		return ret;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> a(n);
	int mx = 0, mn = 1e9;
	REP(i, n) {
		cin >> a[i];
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
	}

	if(mx <= mn * 2) {
		REP(i, n) cout << "-1\n";
		return 0;
	}

	Tree tree(n * 2 + 1);
	REP(i, n) {
		tree.update(i, a[i]);
		tree.update(i + n, a[i]);
	}
	tree.update(2 * n, a[0]);

	vector<int> nxt(n * 2);
	REP(i, n) {
		int l = i, r = i + n;
		while(l < r) {
			int m = (l + r + 1) / 2;
			if(a[i] <= tree.query(i, m) * 2)
				l = m;
			else
				r = m - 1;
		}

		nxt[i] = l;
		if(nxt[i] == i + n)
			nxt[i] = 1e9;
		nxt[i + n] = nxt[i] + n;
	}

	debug(nxt);

	int R = 1e9;
	vector<int> ans(n);
	for(int i = 2 * n - 1; i >= 0; i--) {
		R = min(R, nxt[i]);
		if(i < n) ans[i] = R - i + 1;
	}

	REP(i, n) cout << ans[i] << " ";
	cout << "\n";
}