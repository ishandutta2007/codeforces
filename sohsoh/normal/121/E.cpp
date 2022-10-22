#include <bits/stdc++.h>
#pragma GCC target("avx2")

using namespace std;

typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

constexpr int MAXN = 1e5 + 10;
constexpr int LCNT = 30;
constexpr int INF = 1e9 + 2;
constexpr int lucky[LCNT] = {
	4, 7,
	44, 47, 74, 77,
	444, 447, 474, 477, 744, 747, 774, 777,
	4444, 4447, 4474, 4477, 4744, 4747, 4774, 4777,
	7444, 7447, 7474, 7477, 7744, 7747, 7774, 7777
};

bool F, tof[MAXN << 2];
int lz[MAXN << 2][LCNT], n, q, A[MAXN];
vector<pair<int, pll>> sg[MAXN << 2]; // ans, ind, cnt

inline vector<pair<int, pll>> merge(vector<pair<int, pll>> a, vector<pair<int, pll>> b) {
	if (a.empty()) return b;
	if (b.empty()) return a;

	vector<pair<int, pll>> ans(LCNT);
	for (int i = 0; i < LCNT; i++) {
		if (a[i].X < b[i].X) ans[i] = a[i];
		else if (b[i].X < a[i].X) ans[i] = b[i];
		else ans[i] = {a[i].X, {a[i].Y.X, a[i].Y.Y + b[i].Y.Y}};
	}

	return ans;
}

inline void merge(int v) {
        for (int i = 0; i < LCNT; i++) {
                if (sg[v << 1][i].X < sg[v << 1 | 1][i].X) sg[v][i] = sg[v << 1][i];
                else if (sg[v << 1 | 1][i].X < sg[v << 1][i].X) sg[v][i] = sg[v << 1 | 1][i];
                else sg[v][i] = {sg[v << 1][i].X, {sg[v << 1][i].Y.X, sg[v << 1][i].Y.Y + sg[v << 1 | 1][i].Y.Y}};
        }

}

void build(int l = 1, int r = n, int v = 1) {
	if (l == r) {
		for (int i = 0; i < LCNT; i++) {
			int c = lucky[i] - A[l];
			if (c < 0) c = INF;
			sg[v][i] = {c, {l, 1}};
		}
	} else {
		int mid = (l + r) >> 1;
		build(l, mid, v << 1);
		build(mid + 1, r, v << 1 | 1);
		merge(v);
	}
}

inline void push(int v, int i) {
	if (!lz[v][i]) return;
	sg[v][i].X += lz[v][i];
	if ((v << 1 | 1) < (MAXN << 2)) {
		lz[v << 1][i] += lz[v][i];
		lz[v << 1 | 1][i] += lz[v][i];
		tof[v << 1] = tof[v << 1 | 1] = true;
	}

	lz[v][i] = 0;

}

inline void push(int v) {
	if (!tof[v]) return;
	tof[v] = false;
	for (int i = 0; i < LCNT; i++) push(v, i);
}

void update(int ql, int qr, int val, int l = 1, int r = n, int v = 1) {
	push(v);
	if (ql > r || qr < l) return;
	if (ql <= l && qr >= r) {
		tof[v] = true;
		for (int i = 0; i < LCNT; i++) lz[v][i] += val;
		push(v);
		return;
	}

	int mid = (l + r) >> 1;
	update(ql, qr, val, l, mid, v << 1);
	update(ql, qr, val, mid + 1, r, v << 1 | 1);
	merge(v);
}

void reset(int l_ind, int ind, int l = 1, int r = n, int v = 1) {
	push(v, l_ind);
	if (l == r) sg[v][l_ind] = {INF, {0, 0}};
	else {
		int mid = (l + r) >> 1;
		if (ind <= mid) reset(l_ind, ind, l, mid, v << 1), push(v << 1 | 1, l_ind);
		else reset(l_ind, ind, mid + 1, r, v << 1 | 1), push(v << 1, l_ind);

		if (sg[v << 1][l_ind].X < sg[v << 1 | 1][l_ind].X) sg[v][l_ind] = sg[v << 1][l_ind];
		else if (sg[v << 1][l_ind].X > sg[v << 1 | 1][l_ind].X) sg[v][l_ind] = sg[v << 1 | 1][l_ind];
		else sg[v][l_ind] = {sg[v << 1][l_ind].X, {sg[v << 1][l_ind].Y.X, sg[v << 1][l_ind].Y.Y + sg[v << 1 | 1][l_ind].Y.Y}};
	}
}

vector<pair<int, pll>> query(int ql, int qr, int l = 1, int r = n, int v = 1) {
	push(v);
	if (ql > r || qr < l) return {};

	if (ql <= l && qr >= r) return sg[v];

	int mid = (l + r) >> 1;
	return merge(query(ql, qr, l, mid, v << 1),
			query(ql, qr, mid + 1, r, v << 1 | 1));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 0; i < (MAXN << 2); i++) sg[i].resize(LCNT);
	for (int i = 1; i <= n; i++) cin >> A[i];
	
	if (A[1] == 1 && A[2] == 8) F = true;
	build();
	while (q--) {
		string s;
		cin >> s;
		if (s == "add") {
			int l, r, val;
			cin >> l >> r >> val;
			update(l, r, -val);
		} else {
			int l, r;
			cin >> l >> r;

			int ans = 0;
			for (int i = 0; i < LCNT; i++)
				while (sg[1][i].X < 0) 
					reset(i, sg[1][i].Y.X);	
		
			vector<pair<int, pll>> vec = query(l, r);
			for (int i = 0; i < LCNT; i++)
				if (vec[i].X == 0)
					ans += vec[i].Y.Y;
		
			cout << ans << endl;
		}
	}
	return 0;
}