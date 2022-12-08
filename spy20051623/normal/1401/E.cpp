#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;
struct node {
	int l, r, s;
} tr[N << 2];
#define T tr[n]
#define LS tr[n<<1]
#define RS tr[n<<1|1]

void build(int n, int l, int r) {
	T.l = l, T.r = r, T.s = 0;
	if (l == r) return;
	int m = (l + r) >> 1;
	build(n << 1, l, m);
	build(n << 1 | 1, m + 1, r);
}

void upd(int n, int x, int k) {
	if (T.l == T.r) {
		T.s += k;
		return;
	}
	int m = (T.l + T.r) >> 1;
	if (x <= m) upd(n << 1, x, k);
	else upd(n << 1 | 1, x, k);
	T.s = LS.s + RS.s;
}

int qry(int n, int l, int r) {
	if (T.l >= l && T.r <= r) return T.s;
	if (T.l > r || T.r < l) return 0;
	return qry(n << 1, l, r) + qry(n << 1 | 1, l, r);
}

vector<pair<int, int>> L, R;

vector<pair<int, pair<int, int>>> v;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	build(1, 0, 1000000);
	upd(1, 0, 1);
	upd(1, 1000000, 1);
	int n, m;
	cin >> n >> m;
	long long ans = 1;
	for (int i = 0; i < n; ++i) {
		int l, r, h;
		cin >> h >> l >> r;
		if (l == 0 && r == 1000000) ++ans, upd(1, h, 1);
		else if (l == 0) L.emplace_back(r, h), upd(1, h, 1);
		else R.emplace_back(l, h);
	}
	sort(L.begin(), L.end());
	sort(R.begin(), R.end());
	for (int i = 0; i < m; ++i) {
		int l, r, h;
		cin >> h >> l >> r;
		v.emplace_back(h, make_pair(l, r));
	}
	sort(v.begin(), v.end());
	int pl = 0, pr = 0;
	for (int i = 0; i < m; ++i) {
		while (pl < L.size() && L[pl].first < v[i].first) upd(1, L[pl++].second, -1);
		while (pr < R.size() && R[pr].first <= v[i].first) upd(1, R[pr++].second, 1);
		ans += qry(1, v[i].second.first, v[i].second.second) - 1;
	}
	cout << ans << '\n';
	return 0;
}