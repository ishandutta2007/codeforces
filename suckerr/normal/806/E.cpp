#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 7;
const int INF = 1e9 + 7;

int n, a[N], m;
vector<pair<int, int>> values;

struct Node {
	pair<int, int> f;
	int size, maxv;
	Node() {
		f = make_pair(0, INF);
		size = 0, maxv = -INF;
	}
}tree[N << 2];

void build(int x, int l, int r) {
	if (l == r) return ;
	int mid = (l + r) / 2;
	build(x << 1, l, mid);
	build(x << 1 | 1, mid + 1, r);
}

pair<int, int> combine(const pair<int, int> &a, const pair<int, int> &b) {
	return make_pair(a.first + b.first, min(b.second, a.second + b.first));
}

void insert(int x, int l, int r, int pos) {
	++tree[x].size;
	if (values[pos].first > tree[x].maxv) {
		tree[x].maxv = values[pos].first;
	}
	if (l == r) {
		int v = values[pos].first;
		tree[x].f = make_pair(1, v);
		return ;
	}
	int mid = (l + r) / 2;
	if (pos <= mid) {
		insert(x << 1, l, mid, pos);
	} else {
		insert(x << 1 | 1, mid + 1, r, pos);
	}
	tree[x].f = combine(tree[x << 1].f, tree[x << 1 | 1].f);
}

int downpos, cur;

bool find_down(int x, int l, int r) {
	if (tree[x].maxv <= cur - tree[x].size) {
		cur -= tree[x].size;
		return false;
	}
	if (l == r) {
		downpos = l;
		return true;
	}
	int mid = (l + r) / 2;
	if (find_down(x << 1, l, mid)) return true;
	if (find_down(x << 1 | 1, mid + 1, r)) return true;
	assert(false);
}

pair<int, int> ask(int x, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) return tree[x].f;
	if (qr < l || r < ql) return make_pair(0, INF);
	int mid = (l + r) / 2;
	return combine(ask(x << 1, l, mid, ql, qr), ask(x << 1 | 1, mid + 1, r, ql, qr));
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		values.push_back({a[i], i});
	}
	sort(values.begin(), values.end());
	m = values.size();
	build(1, 0, m - 1);
	for (int i = 1; i <= n; i++) {
		int pos = lower_bound(values.begin(), values.end(), make_pair(a[i], i)) - values.begin();
		insert(1, 0, m - 1, pos);
		downpos = -1; cur = 0;
		find_down(1, 0, m - 1);
		if (downpos == -1) {
			printf("%d\n", cur);
		} else {
			pair<int, int> all = ask(1, 0, m - 1, downpos, m - 1);
			printf("%d\n", min(cur + all.first, all.second));
		}
	}
	return 0;
}