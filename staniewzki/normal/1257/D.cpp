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
	T f(T a, T b) { return max(a, b); }
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
		if(l > r) return 0;
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

	int t;
	cin >> t;
	REP(it, t) {
		int n, m;
		cin >> n;
		Tree tree(n);
		REP(i, n) {
			int a;
			cin >> a;
			tree.update(i, a);
		}

		cin >> m;
		vector<PII> h(m);
		REP(i, m) cin >> h[i].ST >> h[i].ND;
		sort(h.begin(), h.end());
		vector<PII> q;
		for(int i = m - 1; i >= 0; i--)
			if(q.empty() || q.back().ND < h[i].ND)
				q.emplace_back(h[i]);

		vector<int> dp(n + 1, 1e9);
		dp[0] = 0;
		REP(i, n) {
			int l = 0, r = size(q) - 1;
			while(l < r) {
				int mid = (l + r) / 2;
				int b = max(i - q[mid].ND + 1, 0);
				if(tree.query(b, i)	< q[mid].ST)
					l = mid + 1;
				else
					r = mid;
			}

			int pos = l;
			debug(i);
			debug(pos, q[pos]);
			if(pos) debug(pos, q[pos - 1]);
			if(pos) dp[i + 1] = dp[max(0, i + 1 - q[pos - 1].ND)] + 1;
			debug(dp[i + 1]);
			l = 0, r = min(q[pos].ND, i + 1);
			while(l < r) {
				int mid = (l + r + 1) / 2;
				if(tree.query(i - mid + 1, i) > q[pos].ST)
					r = mid - 1;
				else
					l = mid;
			}

			debug(l, i - l);

			dp[i + 1] = min(dp[i + 1], dp[i + 1 - l] + 1);
			debug(i + 1, dp[i + 1]);
		}

		if(dp[n] >= 1e9) cout << "-1\n";
		else cout << dp[n] << "\n";
	}
}