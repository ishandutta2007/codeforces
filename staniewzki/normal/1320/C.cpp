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

using T = LL;
struct Node {
	T val, lazy;
	int size = 1;
};

struct Tree {
	vector<Node> tree;
	int size = 1;

	void add_val(int v, T val) {
		tree[v].val += val;
		tree[v].lazy += val;
	}

	T f(T a, T b) { return max(a, b); }

	Tree(int n) {
		while(size < n) size *= 2;
		tree.resize(size * 2);
		for(int i = size - 1; i >= 1; i--)
			tree[i].size = tree[i * 2].size * 2;
	}

	void propagate(int v) {
		REP(i, 2)
			add_val(v * 2 + i, tree[v].lazy);
		tree[v].lazy = 0;
	}

	T query() { return tree[1].val; }

	void add(int l, int r, T val, int v = 1) {
		if(l == 0 && r == tree[v].size - 1) {
			add_val(v, val);
			return;
		}
		propagate(v);
		int m = tree[v].size / 2;
		if(r < m)
			add(l, r, val, v * 2);
		else if(m <= l)
			add(l - m, r - m, val, v * 2 + 1);
		else
			add(l, m - 1, val, v * 2), add(0, r - m, val, v * 2 + 1);

		tree[v].val = f(tree[v * 2].val, tree[v * 2 + 1].val);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, p;
	cin >> n >> m >> p;

	vector<PII> w(n);
	REP(i, n) {
		cin >> w[i].ST >> w[i].ND;
	}

	sort(w.begin(), w.end());

	auto mono = [&](vector<PII> v) {
		vector<PII> ret;
		REP(i, size(v)) {
			while(size(ret) && ret.back().ND >= v[i].ND)
				ret.pop_back();
			if(size(ret) == 0 || ret.back().ST != v[i].ST)
				ret.emplace_back(v[i]);
		}
		return ret;
	};

	Tree tree(1e6 + 1);	
	auto add = [&](int x, LL val) {
		debug(x, val);
		tree.add(x, tree.size - 1, val);
	};


	w = mono(w);
	int last = 0, cost = 0;
	debug(w);
	REP(i, size(w)) {
		add(last, cost - w[i].ND);
		last = w[i].ST;
		cost = w[i].ND;
	}
	add(last, -1e18);

	struct Event {
		int x, y, c;
		Event(int x, int y, int c)
			: x(x), y(y), c(c) {}
	};

	vector<Event> events;

	REP(i, m) {
		int y, z;
		cin >> y >> z;
		events.emplace_back(-1, y, z);
	}

	REP(i, p) {
		int x, y, z;
		cin >> x >> y >> z;
		events.emplace_back(x, y, z);
	}

	sort(events.begin(), events.end(), [&](Event &i, Event &j) {
		return tie(i.y, i.x) < tie(j.y, j.x);
	});

	LL ans = -1e18;
	for(auto &e : events) {
		if(e.x == -1)
			ans = max(ans, tree.query() - e.c);
		else
			add(e.x, e.c);
	}

	cout << ans << "\n";
}