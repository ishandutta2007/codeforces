#include <bits/stdc++.h>

using namespace std;
#define int long long
#define double long double

const int INF = -1e18;

struct line{
	int k, b;
	line() {
		k = 0, b = INF;
	}
	line(int x, int y) {
		k = x, b = y;
	}
};

int eval(line l, int x) {
	return l.k * x + l.b;
}

double cross(line l, line m) {
	return (double) (m.b - l.b) / (l.k - m.k);
}

bool operator<(line a, line b) {
	return a.k < b.k || (a.k == b.k && a.b > b.b);
}

bool operator==(line a, line b) {
	return a.k == b.k && a.b == b.b;
}

bool cmp(pair <line, int> a, pair <line, int> b) {
	return a.first < b.first || (a.first == b.first && a.second < b.second);
}

struct cht{
	vector<pair <line, int> > l;
	vector<double> p;

	cht() {
		l = {};
		p = {};
	}

	void add(pair <line, int> x) {
		while (!p.empty() && cross((l.back()).first, x.first) <= p.back())
			p.pop_back(), l.pop_back();
		l.push_back(x);
		if (l.size() >= 2) {
			p.push_back(cross(l[l.size() - 1].first, l[l.size() - 2].first));
		}
	}

	cht(vector<pair<line, int> > help) {
		sort(help.begin(), help.end(), cmp);
		add(help[0]);
		auto last = help[0];
		int sz = help.size();
		for (int i = 1; i < sz; i++) {
			if (help[i].first.k > last.first.k) {
				add(help[i]);
				last = help[i];
			}
		}
	}

	pair <int, int> get(int x) {
		int pos = lower_bound(p.begin(), p.end(), x) - p.begin();
		return {eval(l[pos].first, x), l[pos].second};
	}

};

struct segment_tree{
	vector<cht> tree;
	int n;
	segment_tree() {
		tree = {};
	}

	void build(int v, int l, int r, vector<pair <line, int> > & a) {
		if (l == r - 1) {
			tree[v].add(a[l]);
			return;
		}
		int m = (l + r) / 2;
		build(v * 2, l, m, a);
		build(v * 2 + 1, m, r, a);
		vector<pair <line, int> > help;
		for (auto i : tree[v * 2].l)
			help.push_back(i);
		for (auto i : tree[v * 2 + 1].l)
			help.push_back(i);
		tree[v] = cht(help);
	}

	segment_tree(vector<pair <line, int> > a) {
		n = a.size();
		tree.resize(4 * n);
		build(1, 0, n, a);
	}

	pair <int, int> get(int v, int tl, int tr, int l, int r, int t) {
		if (tl >= r || tr <= l) return {INF, INF};
		if (tl >= l && tr <= r) return tree[v].get(t);
		int tm = (tl + tr) / 2;
		return max(get(v * 2, tl, tm, l, r, t), get(v * 2 + 1, tm, tr, l, r, t)); 
	}

	pair <int, int> get(int l, int r, int t) {
		return get(1, 0, n, l, r, t);
	}
};

int n, q;
vector<int> ans;
vector<pair <line, int> > a;

void read() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		int k, b;
		cin >> b >> k;
		a.push_back({line(k, b), i + 1});
	}
}

void run() {
	segment_tree help(a);
	for (int test = 0; test < q; test++) {
		int l, r, t;
		cin >> l >> r >> t;
		l--;
		auto ax = help.get(l, r, t);
		ans.push_back(ax.second);
	}
}

void write() {
	for (auto i : ans)
		cout << i << "\n";
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