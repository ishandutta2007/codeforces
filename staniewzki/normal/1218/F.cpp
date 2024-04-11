#include<bits/stdc++.h>
using namespace std;
 
 
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
	using T = PII;
	T f(T a, T b) { return min(a, b); }
	vector<T> nodes;
	int size = 1;

	Tree(int n, T val = {1e9, -1}) {
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

	int n, k, a;
	cin >> n >> k;
	vector<int> x(n), c(n);
	REP(i, n) cin >> x[i];
	cin >> a;
	REP(i, n) cin >> c[i];

	Tree tree(n);
	REP(i, n) tree.update(i, {c[i], i});

	LL ans = 0;
	REP(i, n) {
		while(k < x[i]) {
			auto ret = tree.query(0, i);
			if(ret.ND == -1) {
				cout << "-1\n";
				return 0;
			}
			ans += ret.ST;
			k += a;
			tree.update(ret.ND, {1e9, -1});
		}
	}

	cout << ans << "\n";
}