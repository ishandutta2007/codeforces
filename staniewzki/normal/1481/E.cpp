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

struct Tree {
	using T = int;
	T f(T a, T b) { return max(a, b); }
	vector<T> tree;
	int sz = 1;

	Tree(int n, T val = 0) {
		while(sz < n) sz *= 2;
		tree.resize(sz * 2, val);
	}

	void update(int pos, T val) {
		pos += sz;
		tree[pos] = max(tree[pos], val);
		while(pos /= 2)
			tree[pos] = f(tree[pos * 2], tree[pos * 2 + 1]);
	}

	T query(int l, int r) {
		l += sz, r += sz;
		T ret = (l != r ? f(tree[l], tree[r]) : tree[l]);
		while(l + 1 < r) {
			if(l % 2 == 0)
				ret = f(ret, tree[l + 1]);
			if(r % 2 == 1)
				ret = f(ret, tree[r - 1]);
			l /= 2, r /= 2;
		}
		return ret;
	}

	T query(int pos) {
		if(pos < 0) return 0;
		return query(0, pos);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> a(n);
	REP(i, n) cin >> a[i], a[i]--;

	vector<int> pier(n, n), ost(n, -1);
	REP(i, n) 
		ost[a[i]] = i;
	for(int i = n - 1; i >= 0; i--)
		pier[a[i]] = i;

	Tree tree(n);
	vector<int> ile(n), eli(n);
	int ans = 0;
	REP(i, n)
		eli[a[i]]++;

	REP(i, n) {
		ile[a[i]]++;
		int r = tree.query(pier[a[i]] - 1);
		if(i == ost[a[i]])
			tree.update(i, r + ile[a[i]]);
		ans = max(ans, tree.query(i - 1) + eli[a[i]] - ile[a[i]] + 1);
	}

	ans = max(ans, tree.query(n - 1));
	cout << n - ans << "\n";
}