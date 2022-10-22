#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int R[MAXN], A[MAXN], fen[MAXN], n, k, ans[MAXN], qans[MAXN], q, sg[MAXN];
vector<pair<int, pll>> Q[MAXN];
vector<int> X, Y, F[MAXN];

inline void add(int ind, int val) {
	for (++ind; ind < MAXN; ind += ind & -ind)
		fen[ind] += val;
}

inline int query(int ind) {
	int ans = 0;
	for (++ind; ind > 0; ind -= ind & -ind)
		ans += fen[ind];
	return ans;
}

inline int query(pll p) {
	if (p.Y == 0) return 0;
	return query(p.Y) - query(p.X - 1);
}

inline int ind(int x) {
	return lower_bound(all(X), x) - X.begin() + 1;
}

inline pll rng(int l, int r) {
	if (l > X.back() || r < X.front()) return {0, 0};
	l = lower_bound(all(X), l) - X.begin() + 1;
	r = upper_bound(all(X), r) - X.begin();
	if (l > r) return {0, 0};
	return {l, r};
}

void update(int ind, int val, int l = 1, int r = n, int v = 1) {
	if (l == r) sg[v] = max(sg[v], val);
	else {
		int mid = (l + r) >> 1;
		if (ind <= mid) update(ind, val, l, mid, v << 1);
		else update(ind, val, mid + 1, r, v << 1 | 1);
		
		sg[v] = max(sg[v << 1], sg[v << 1 | 1]);
	}
}

int query(int ql, int qr, int l = 1, int r = n, int v = 1) {
	if (ql > r || qr < l) return 0;
	if (ql <= l && qr >= r) return sg[v];

	int mid = (l + r) >> 1;
	return max(query(ql, qr, l, mid, v << 1),
			query(ql, qr, mid + 1, r, v << 1 | 1));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> R[i], Y.push_back(R[i]);
	for (int i = 1; i <= n; i++) cin >> A[i], X.push_back(A[i]);

	sort(all(X));
	sort(all(Y));
	X.resize(unique(all(X)) - X.begin());
	Y.resize(unique(all(Y)) - Y.begin());

	for (int i = 1; i <= n; i++) { 
		R[i] = lower_bound(all(Y), R[i]) - Y.begin() + 1;
		F[R[i]].push_back(i);
	}

	for (int i = 1; i <= n; i++) {
		for (int e : F[i]) add(ind(A[e]), 1);
		for (int e : F[i]) ans[e] = query(rng(A[e] - k, A[e] + k));
	}

	cin >> q;
	for (int t = 1; t <= q; t++) {
		int i, j;
		cin >> i >> j;	
		pll a = rng(A[i] - k, A[i] + k), b = rng(A[j] - k, A[j] + k);
		
		pll u = {max(a.X, b.X), min(a.Y, b.Y)};
		if (u.X <= u.Y) Q[max(R[i], R[j])].push_back({t, u});
	}

	for (int i = n; i > 0; i--) {
		for (int e : F[i]) update(ind(A[e]), ans[e]);
		for (auto e : Q[i]) qans[e.X] = query(e.Y.X, e.Y.Y);
	}

	for (int i = 1; i <= q; i++)
		cout << (qans[i] < 2 ? -1 : qans[i]) << endl;
	return 0;
}