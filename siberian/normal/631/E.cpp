#include <bits/stdc++.h>

using namespace std;
#define int long long

const int INF = -1e18;

struct line { 
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

const int MIN_L = -1e6 - 10, MAX_R = 1e6 + 10;

const int MAXN = 2e5 + 10;
const int MAXSZ = MAX_R - MIN_L;

struct li_tree {
	unordered_map <int, line> tree;
	li_tree() {
		tree = {};
	}

	void add(line l, int v = 1, int tl = MIN_L, int tr = MAX_R) {
		int tm = (tl + tr) / 2;
		bool mid = eval(l, tm) > eval(tree[v], tm);
		bool left = eval(l, tl) > eval(tree[v], tl);
		if (mid) {
			swap(l, tree[v]);
		}
		if (tl == tr - 1) return;
		if (mid != left) {
			add(l, v * 2, tl, tm);
		}
		else {
			add(l, v * 2 + 1, tm, tr);
		}
	}

	int get(int x, int v = 1, int tl = MIN_L, int tr = MAX_R) {
		if (tl >= x + 1 || tr <= x) return INF;
		if (tl == x && tr == x + 1) return eval(tree[v], x);
		int tm = (tl + tr) / 2;
		int ans = eval(tree[v], x);
		ans = max(get(x, v * 2, tl, tm), ans);
		ans = max(get(x, v * 2 + 1, tm, tr), ans);
		return ans;
	}
};

int n;
int a[MAXN];
int pref[MAXN];
void read() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], pref[i] = pref[i - 1] + a[i];
}

int ans = 0;
void run() {
	for (int i = 1; i <= n; i++)
		ans += i * a[i];
	int plus = 0;
	li_tree left;

	for (int i = 1; i <= n; i++) {
		plus = max(plus, left.get(i) - pref[i]);
		left.add(line(a[i], -a[i] * i + pref[i]));
	}

	li_tree right;

	for (int i = n; i >= 1; i--) {
		plus = max(plus, right.get(i) - pref[i - 1]);
		right.add(line(a[i], -a[i] * i + pref[i - 1]));
	}

	ans += plus;
}

void write() {
	cout << ans << endl;
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