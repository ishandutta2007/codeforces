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

struct Fenwick {
	vector<int> tree;
	Fenwick(int n) : tree(n + 1, n) {}
	void update(int pos, int val) {
		for(pos++; pos < size(tree); pos += pos & (-pos))
			tree[pos] = min(tree[pos], val);
	}
	int query(int pos) {
		int ret = size(tree) - 1;
		for(pos++; pos >= 1; pos -= pos & (-pos))
			ret = min(ret, tree[pos]);
		return ret;
	}
	void turn_on(int i) {
		int pos = size(tree) - 2 - i;
		update(pos, i);
	}
	int get_suffix(int i) {
		int pos = size(tree) - 2 - i;
		return query(pos);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string str;
	cin >> str;

	auto get_nxt = [&](char c) {
		vector<int> nxt(n);
		int cur = 0;
		for(int i = n - 1; i >= 0; i--) {
			if(str[i] == c) cur = 0;
			else cur++;
			nxt[i] = cur;
		}
		return nxt;
	};

	auto a = get_nxt('0'), b = get_nxt('1');
	vector<vector<int>> changes(n + 1);
	REP(i, n) changes[max(a[i], b[i])].emplace_back(i);

	Fenwick tree(n);
	vector<int> ans(n + 1);
	for(int i = n; i >= 1; i--) {
		for(int j : changes[i])
			tree.turn_on(j);

		int pos = 0;
		while(pos < n) {
			pos = tree.get_suffix(pos);
			if(pos < n) {
				pos += i;
				ans[i]++;
			}
		}
	}
	FOR(i, 1, n) cout << ans[i] << " ";
	cout << "\n";
	
}