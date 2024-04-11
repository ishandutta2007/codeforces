#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 2e6 + 10;

int n, B[MAXN], I[MAXN], R[MAXN], ans, sg[MAXN], lz[MAXN];
vector<int> X[3]; 

inline int ind(int i, int x) {
	return lower_bound(all(X[i]), x) - X[i].begin() + 1;
}

inline void upd(int& a, int b) {
	if (a == 0 || a > b) a = b;
}

inline void push(int v) {
	if (lz[v]) {
		sg[v] = min(sg[v], lz[v]);
		if ((v << 1 | 1) < MAXN) {
			upd(lz[v << 1], lz[v]);
			upd(lz[v << 1 | 1], lz[v]);
		}

		lz[v] = 0;
	}
}

void update(int ql, int qr, int val, int l = 1, int r = n, int v = 1) {
	push(v);
	if (ql > r || qr < l) return;
	if (ql <= l && qr >= r) {
		lz[v] = val;
		push(v);
		return;
	}

	int mid = (l + r) >> 1;
	update(ql, qr, val, l, mid, v << 1);
	update(ql, qr, val, mid + 1, r, v << 1 | 1);
	sg[v] = min(sg[v << 1], sg[v << 1 | 1]);
}

int query(int ql, int qr, int l = 1, int r = n, int v = 1) {
	push(v);
	if (ql > r || qr < l) return MAXN;
	if (ql <= l && qr >= r) return sg[v];

	int mid = (l + r) >> 1;
	return min(query(ql, qr, l, mid, v << 1),
			query(ql, qr, mid + 1, r, v << 1 | 1));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fill(sg, sg + MAXN, MAXN);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> B[i];
		B[i] = -B[i];
		X[0].push_back(B[i]);
	}

	for (int i = 1; i <= n; i++) {
		cin >> I[i];
		I[i] = -I[i];
		X[1].push_back(I[i]);
	}
	
	for (int i = 1; i <= n; i++) {
		cin >> R[i];
		R[i] = -R[i];
		X[2].push_back(R[i]);
	}
	
	for (int i = 0; i < 3; i++)
		sort(all(X[i]));

	vector<pair<int, pll>> v;
	for (int i = 1; i <= n; i++) {
		B[i] = ind(0, B[i]);
		I[i] = ind(1, I[i]);
		R[i] = ind(2, R[i]);
		v.push_back({B[i], {I[i], R[i]}});
	}

	sort(all(v), [] (pair<int, pll> a, pair<int, pll> b) {
		return make_pair(a.X, -a.Y.X) < make_pair(b.X, -b.Y.X);
	});

	for (auto e : v) {
		int x = e.Y.X, y = e.Y.Y;
		if (x > 1 && query(1, x - 1) < y) ans++;
		update(x, n, y);
	}

	cout << ans << endl;
	return 0;
}