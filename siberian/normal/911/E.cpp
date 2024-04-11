#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n, k;
vector<int> p;
vector<int> b;
vector<int> st;
vector<int> ans;

void read() {
	cin >> n >> k;
	p.resize(k);
	for (auto &i : p) {
		cin >> i;
	}
}

void no() {
	/*cout << "ans = " << endl;
	for (auto i : ans) {
		cout << i << " ";
	}
	cout << endl;
	cout << "st = " << endl;
	for (auto i : st) {
		cout << i << " ";
	}
	cout << endl;*/
	cout << -1 << endl;
	exit(0);
}

struct fenvik{
	vector<int> tree;
	int n;
	fenvik() {}
	fenvik(int _n) {
		n = _n;
		tree.assign(n, 0);
	}
	int get(int r) {
		int ans = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1) {
			ans += tree[r];
		}
		return ans;
	}
	int get(int l, int r) {
		return get(r) - get(l);
	}
	void upd(int pos, int val) {
		for (; pos < n; pos |= (pos + 1))
			tree[pos] += val;
	}
	void wr() {
		cout << "tree =" << endl;
		for (auto i : tree) {
			cout << i << " ";
		}
		cout << endl;
	}
};

fenvik tree;

void relax() {
	while (!st.empty() && ((b.empty() && st.back() == 1) || (!b.empty() && (st.back() - 1 == b.back())))) {
		b.push_back(st.back());
		st.pop_back();
	}
}

void add(int x) {
	tree.upd(x, -1);
	x++;
	ans.push_back(x);
	if (b.empty() && x == 1) {
		b.push_back(x);
	} else if (!b.empty() && b.back() == x - 1) {
		b.push_back(x);
	} else if (!st.empty() && st.back() < x) { 
		no();
	}
	else {
		st.push_back(x);
	}
	relax();
}

void build() {
	tree = fenvik(n);
	for (int i = 0; i < n; i++) {
		tree.upd(i, 1);
	}
	for (auto i : p) {
		add(i - 1);
	}
}

int find(int sum) {
	int l = -1, r = n;
	while(l < r - 1) {
		int mid = (l + r) / 2;
		if (tree.get(mid) >= sum) {
			r = mid;
		} else {
			l = mid;
		}
	}
	return r;
}

bool check(int mid) {
	int val = find(mid) + 1;
	//cout << "mid = " << mid << " val = " << val << endl;
	if (val == 1) return true;
	if (!b.empty() && b.back() == val) return true;
	if (st.empty()) return true;
	if (st.back() > val) return true;
	return false;
}

void run() {
	build();
	for (int i = 0; i < n - k; i++) {
		//tree.wr();
		int l = 1, r = tree.get(n - 1) + 1;
		while (l < r - 1) {
			int mid = (l + r) / 2;
			if (check(mid)) {
				l = mid;
			} else {
				r = mid;
			}
		}
		//cout << "nxt = " << find(l) << endl;
		add(find(l));
	}
}

void write() {
	for (auto &i : ans) {
		cout << i << " ";
	}
	cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}