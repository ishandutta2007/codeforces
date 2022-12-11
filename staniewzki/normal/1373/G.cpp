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

/*
 * Opis: Drzewo przedzia-przedzia
 * Czas: O(\log n)
 * Pami : O(n)
 * Uycie:
 *   add(l, r, val) dodaje na przedziale
 *   quert(l, r) bierze maxa z przedziau
 *   Zmieniajc z maxa na co innego trzeba edytowa
 *   funkcje add_val i f
 */

using T = int;
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

	T f(T a, T b) { return min(a, b); }

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

	T query(int l, int r, int v = 1) {
		if(l == 0 && r == tree[v].size - 1)
			return tree[v].val;
		propagate(v);	
		int m = tree[v].size / 2;
		if(r < m)
			return query(l, r, v * 2);
		else if(m <= l)
			return query(l - m, r - m, v * 2 + 1);
		else
			return f(query(l, m - 1, v * 2), query(0, r - m, v * 2 + 1));
	}

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

	int n, m, k;
	cin >> n >> k >> m;

	set<PII> pawns;
	multiset<int> qs;
	int s = n * 2 + 7 + m;
	Tree tree(s);
	REP(i, s) tree.add(i, i, s - i);

	REP(i, m) {
		int x, y;
		cin >> x >> y;
		int q = (x <= k ? y + k - x : y + x - k);
		debug(q);
		if(pawns.count({x, y}) == 0) {
			pawns.emplace(x, y);
			tree.add(0, q, -1);
			qs.emplace(q);
		}
		else {
			pawns.erase({x, y});
			tree.add(0, q, +1);
			qs.erase(qs.find(q));
		}

		auto check = [&](int w) {
			debug(w, tree.query(0, w), (s - w - 1));
			return tree.query(0, w) - (s - w - 1) >= 0;
		};

		int l = max(n, (size(qs) ? *qs.rbegin() : 0)), r = s;
		while(l < r) {
			int mid = (l + r) / 2;
			if(check(mid))
				r = mid;
			else
				l = mid + 1;
		}

		cout << l - n << "\n";
	}
}