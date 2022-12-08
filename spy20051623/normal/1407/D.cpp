#include <bits/stdc++.h>

using namespace std;
const int N = 3e5 + 5;
const int inf = 1e9;
int h[N], st1[N][20], st2[N][20], lg2[N];
struct node {
	int l, r;
	int dp1, dp2;
	int tag1, tag2;
} tr[N << 2];
#define T tr[n]
#define LS tr[n<<1]
#define RS tr[n<<1|1]

void build(int n, int l, int r) {
	T.l = l, T.r = r, T.dp1 = T.dp2 = inf, T.tag1 = T.tag2 = 0;
	if (l == r) return;
	int m = (l + r) >> 1;
	build(n << 1, l, m);
	build(n << 1 | 1, m + 1, r);
}

void push_down(int n) {
	if (T.tag1) {
		LS.dp1 = RS.dp1 = inf;
		LS.tag1 = RS.tag1 = 1;
		T.tag1 = 0;
	}
	if (T.tag2) {
		LS.dp2 = RS.dp2 = inf;
		LS.tag2 = RS.tag2 = 1;
		T.tag2 = 0;
	}
}

void upd(int n, int x, int k) {
	if (T.l == T.r) {
		T.dp1 = T.dp2 = k;
		T.tag1 = T.tag2 = 0;
		return;
	}
	push_down(n);
	int m = (T.l + T.r) >> 1;
	if (x <= m) upd(n << 1, x, k);
	else upd(n << 1 | 1, x, k);
	T.dp1 = min(LS.dp1, RS.dp1);
	T.dp2 = min(LS.dp2, RS.dp2);
}

void upd1(int n, int l, int r) {
	if (T.l >= l && T.r <= r) {
		T.tag1 = 1;
		T.dp1 = inf;
		return;
	}
	if (T.l > r || T.r < l) return;
	upd1(n << 1, l, r);
	upd1(n << 1 | 1, l, r);
	T.dp1 = min(LS.dp1, RS.dp1);
}

void upd2(int n, int l, int r) {
	if (T.l >= l && T.r <= r) {
		T.tag2 = 1;
		T.dp2 = inf;
		return;
	}
	if (T.l > r || T.r < l) return;
	upd2(n << 1, l, r);
	upd2(n << 1 | 1, l, r);
	T.dp2 = min(LS.dp2, RS.dp2);
}

int qry1(int n, int l, int r) {
	if (T.l >= l && T.r <= r) return T.dp1;
	if (T.l > r || T.r < l) return inf;
	push_down(n);
	return min(qry1(n << 1, l, r), qry1(n << 1 | 1, l, r));
}

int qry2(int n, int l, int r) {
	if (T.l >= l && T.r <= r) return T.dp2;
	if (T.l > r || T.r < l) return inf;
	push_down(n);
	return min(qry2(n << 1, l, r), qry2(n << 1 | 1, l, r));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	build(1, 1, n);
	upd(1, 1, 0);
	for (int i = 1; i <= n; ++i) lg2[i] = (int) log2(i);
	for (int i = 1; i <= n; ++i) {
		cin >> h[i];
		st1[i][0] = st2[i][0] = h[i];
	}
	for (int i = 1; 1 << i <= n; ++i) {
		for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
			st1[j][i] = min(st1[j][i - 1], st1[j + (1 << (i - 1))][i - 1]);
			st2[j][i] = max(st2[j][i - 1], st2[j + (1 << (i - 1))][i - 1]);
		}
	}
	int res;
	for (int i = 2; i <= n; ++i) {
		int l = 1, r = i - 1, ans1 = 0;
		while (l <= r) {
			int m = (l + r) >> 1;
			int d = lg2[m];
			if (min(st1[i - m][d], st1[i - (1 << d)][d]) > h[i]) ans1 = m, l = m + 1;
			else r = m - 1;
		}
		l = 1, r = i - 1;
		int ans2 = 0;
		while (l <= r) {
			int m = (l + r) >> 1;
			int d = lg2[m];
			if (max(st2[i - m][d], st2[i - (1 << d)][d]) < h[i]) ans2 = m, l = m + 1;
			else r = m - 1;
		}
		int ans = 1 + min(qry1(1, i - ans1 - 1, i - 1), qry2(1, i - ans2 - 1, i - 1));
		upd(1, i, ans);
		l = 1, r = i - 1, ans1 = 0;
		while (l <= r) {
			int m = (l + r) >> 1;
			int d = lg2[m];
			if (min(st1[i - m][d], st1[i - (1 << d)][d]) >= h[i]) ans1 = m, l = m + 1;
			else r = m - 1;
		}
		l = 1, r = i - 1, ans2 = 0;
		while (l <= r) {
			int m = (l + r) >> 1;
			int d = lg2[m];
			if (max(st2[i - m][d], st2[i - (1 << d)][d]) <= h[i]) ans2 = m, l = m + 1;
			else r = m - 1;
		}
		if (ans1) upd1(1, i - ans1, i - 1);
		if (ans2) upd2(1, i - ans2, i - 1);
		res = ans;
	}
	cout << res << '\n';
	return 0;
}