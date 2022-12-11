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

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
LL rd(LL a, LL b) { return uniform_int_distribution<LL>(a, b)(rng); }


struct Tree {
	using T = LL;
	T f(T a, T b) { return a ^ b; }
	vector<T> tree;
	int size = 1;

	Tree(int n, T val = 0) {
		while(size < n) size *= 2;
		tree.resize(size * 2, val);
	}

	void update(int pos, T val) {
		tree[pos += size] = val;
		while(pos /= 2)
			tree[pos] = f(tree[pos * 2], tree[pos * 2 + 1]);
	}

	T query(int l, int r) {
		l += size, r += size;
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
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<PII> a(n + 1), b(n + 1);
	FOR(i, 1, n) cin >> a[i].ST >> a[i].ND >> b[i].ST >> b[i].ND;
	vector<LL> hsh(n);
	 
	REP(i, n) hsh[i] = rd(1, 1e18);

	auto cal = [&](vector<PII> x) {
		vector<PII> evs;
		FOR(i, 1, n) {
			evs.emplace_back(x[i].ST, -i);
			evs.emplace_back(x[i].ND, i);
		}

		sort(evs.begin(), evs.end());
		Tree tree1(2 * n), tree2(n * 2);

		vector<PII> y(n);
		vector<LL> p(2 * n);
		REP(i, n * 2) {
			int q = evs[i].ND;
			int _x = -1;
			if(q > 0) {
				_x = q - 1;
				y[_x].ND = i;
				tree2.update(i, hsh[_x]);
			}
			else {
				_x = -q - 1;
				y[_x].ST = i;
				tree1.update(i, hsh[_x]);
			}
		}

		vector<LL> ret(n);
		REP(i, n) {
			ret[i] ^= tree2.query(0, y[i].ST);
			ret[i] ^= tree1.query(y[i].ND, n * 2 - 1);
		}
		return ret;
	};

	cout << (cal(a) == cal(b) ? "YES\n" : "NO\n");
}