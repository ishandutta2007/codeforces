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
	T f(T a, T b) { return a + b; }
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

	int get(int x) {
		int v = 0;
		while(v < size) {
			if(x <= nodes[v * 2]) v *= 2;
			else x -= nodes[v * 2], v = v * 2 + 1;
		}
		return v - size;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> a(n);
	vector<PII> x(n);
	REP(i, n) {
		cin >> a[i];
		x[i] = {a[i], i};
	}

	sort(x.begin(), x.end(), [&](PII i, PII j) {
		if(i.ST != j.ST) return i.ST > j.ST;
		return i.ND < j.ND;
	});

	int m;
	cin >> m;

	struct que { int id, k, pos; };
	vector<que> q(m);
	REP(i, m) {
		cin >> q[i].k >> q[i].pos;
		q[i].id = i;
	}

	sort(q.begin(), q.end(), [&](que i, que j) { return i.k < j.k; });
	vector<int> ans(m);

	Tree tree(n);

	int pos = 0;
	REP(i, n) {
		tree.update(x[i].ND, 1);
		while(pos < m && q[pos].k == i + 1) {
			ans[q[pos].id] = tree.get(q[pos].pos);
			pos++;
		}
	}

	REP(i, m) cout << a[ans[i]] << "\n";
}