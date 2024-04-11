#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

struct segment_tree{
	vector<int> tree;
	int n;
	segment_tree() {

	}

	void build(int v, int tl, int tr, const vector<int> & a) {
		if (tl == tr - 1) {
			tree[v] = a[tl];
			return;
		}
		int tm = (tl + tr) / 2;
		build(v * 2, tl, tm, a);
		build(v * 2 + 1, tm, tr, a);
		tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
	}

	segment_tree(vector<int> a) {
		n = a.size();
		tree.assign(n * 4, -1e9);
		build(1, 0, n, a);
	}

	int get(int v, int tl, int tr, int l, int r) {
		if (tl >= r || tr <= l) return -1e9;
		if (tl >= l && tr <= r) return tree[v];
		int tm = (tl + tr) / 2;
		return max(get(v * 2, tl, tm, l, r), get(v * 2 + 1, tm, tr, l, r));
	}

	int get(int l, int r) {
		return get(1, 0, n, l, r + 1);
		int ans = -1e9;
		for (int i = l; i <= r; i++)
			chkmax(ans, tree[i]);
		return ans;
	}
};

struct hero{
	int pow, cnt;
	hero() {}
	hero(int a, int b) {
		pow = a, cnt = b;
	}
};

bool operator<(const hero & a, const hero & b) {
	return tie(a.pow, a.cnt) < tie(b.pow, b.cnt);
}

int n, m;
vector<int> a;
vector<hero> b;



void read() {
	cin >> n;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
	cin >> m;
	b.resize(m);
	for (auto &i : b)
		cin >> i.pow >> i.cnt;
}

int ans = 0;

segment_tree help;

bool check(int l, int r) {
	//cout << "l "
	auto x = lower_bound(all(b), hero(help.get(l, r), -1)) - b.begin();
	if (x == m) return false;
	return b[x].cnt >= (r - l + 1);
}

int get_pos(int pos) {
	if (a[pos] > b.back().pow) return -1;
	int l = pos, r = n;
	while (l < r - 1) {
		int mid = (l + r) / 2;
		if (check(pos, mid))
			l = mid;
		else
			r = mid;
	}
	return l + 1;
}

void run() {
	sort(all(b));
	for (int i = m - 2; i >= 0; i--)
		chkmax(b[i].cnt, b[i + 1].cnt);
	help = segment_tree(a);
	ans = 0;
	int pos = 0;
	while (pos < n) {
		pos = get_pos(pos);
		if (pos == -1) {
			ans = -1;
			return;
		}
		//cout << "pos = " << pos << endl;
		ans++;
	}
}

void write() {
	cout << ans << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		read();
		run();
		write();
	}
	return 0;
}