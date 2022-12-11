#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define REP(i, n) FOR(i, 0, (n) - 1)
template<class T> int size(T &&x) {
	return int(x.size());
}
template<class A, class B> ostream& operator<<(ostream &out, const pair<A, B> &p) {
	return out << '(' << p.first << ", " << p.second << ')';
}
ostream& operator<<(ostream &out, string str) {
	for(char c : str) out << c;
	return out;
}
template<class T> auto operator<<(ostream &out, T &&x) -> decltype(x.begin(), out) {
	out << '{';
	for(auto it = x.begin(); it != x.end(); ++it)
		out << *it << (it == --x.end() ? "" : ", ");
	return out << '}';
}
void dump() {}
template<class T, class... Args> void dump(T &&x, Args... args) {
	cerr << x << ";  ";
	dump(args...);
}
#ifdef DEBUG
  const int seed = 1;
  struct Nl{~Nl(){cerr << '\n';}};
# define debug(x...) cerr << (#x != "" ? #x ":  " : ""), dump(x), Nl(), cerr
#else
  const int seed = chrono::system_clock::now().time_since_epoch().count();
# define debug(...) 0 && cerr
#endif
mt19937_64 rng(seed);
int rd(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

struct Node {
	int val, lazy;
	int size = 1;
};

struct Tree {
	vector<Node> nodes;
	int size = 1;

	Tree(int n) {
		while(size < n) size *= 2;
		nodes.resize(size * 2);
		for(int i = size - 1; i >= 1; i--)
			nodes[i].size = nodes[i * 2].size * 2;
	}

	void add_val(int v, int val) {
		nodes[v].val += val;
		nodes[v].lazy += val;
	}

	void propagate(int v) {
		REP(i, 2) add_val(v * 2 + i, nodes[v].lazy);
		nodes[v].lazy = 0;
	}

	int query(int v = 1) {
		if(nodes[v].size == 1) return 0;
		propagate(v);	
		if(nodes[v * 2 + 1].val < 0) return query(v * 2 + 1) + nodes[v].size / 2;
		else if(nodes[v * 2].val < 0) return query(v * 2);
		else return -1;
	}

	void add(int l, int r, int val, int v = 1) {
		if(l == 0 && r == nodes[v].size - 1) {
			add_val(v, val);
			return;
		}
		propagate(v);
		int m = nodes[v].size / 2;
		if(r < m)
			add(l, r, val, v * 2);
		else if(m <= l)
			add(l - m, r - m, val, v * 2 + 1);
		else
			add(l, m - 1, val, v * 2), add(0, r - m, val, v * 2 + 1);

		nodes[v].val = min(nodes[v * 2].val, nodes[v * 2 + 1].val);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	Tree tree(1e6 + 1);
	REP(i, n) cin >> a[i], tree.add(0, a[i], -1);
	REP(i, m) cin >> b[i], tree.add(0, b[i], 1);

	int q;
	cin >> q;
	REP(i, q)
	{
		int type, id, x;
		cin >> type >> id >> x;
		id--;
		if(type == 1)
		{
			tree.add(0, a[id], 1);
			a[id] = x;
			tree.add(0, a[id], -1);
		}
		else
		{
			tree.add(0, b[id], -1);
			b[id] = x;
			tree.add(0, b[id], 1);
		}

		cout << tree.query() << "\n";
	}
}