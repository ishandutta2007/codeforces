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

const ll MAXN = 5e5 + 10;

int n, q, A[MAXN], B[MAXN];
vector<int> X;
vector<pair<int, pll>> Q;

struct node {
	ll sum = 0, cnt = 0, ans = 0;
	node(ll sum, ll cnt, ll ans): sum(sum), cnt(cnt), ans(ans) {}
	node() {}
} sg[MAXN << 2];


inline int pos(int x) {
	return lower_bound(all(X), x) - X.begin() + 1;
}

inline node merge(node a, node b) {
	return node(a.sum + b.sum, a.cnt + b.cnt, a.ans + b.ans + b.sum * a.cnt - a.sum * b.cnt);
}

void update(int ind, node val, int l = 1, int r = MAXN - 3, int v = 1) {
	if (l == r) sg[v] = val;
	else {
		int mid = (l + r) >> 1;
		if (ind <= mid) update(ind, val, l, mid, v << 1);
		else update(ind, val, mid + 1, r, v << 1 | 1);

		sg[v] = merge(sg[v << 1], sg[v << 1 | 1]);
	}
}

node query(int ql, int qr, int l = 1, int r = MAXN - 3, int v = 1) {
	if (ql > r || qr < l) return node();
	if (ql <= l && qr >= r) return sg[v];

	int mid = (l + r) >> 1;
	return merge(query(ql, qr, l, mid, v << 1),
			query(ql, qr, mid + 1, r, v << 1 | 1));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		B[i] = A[i];
		X.push_back(A[i]);
	}

	cin >> q;
	while (q--) {
		int c, a, b;
		cin >> c >> a >> b;
		Q.push_back({c, {a, b}});

		if (c == 1) {
			B[a] += b;
			X.push_back(B[a]);
		} else {
			X.push_back(a);
			X.push_back(b);
		}
	}

	sort(all(X));
	for (int i = 1; i <= n; i++) update(pos(A[i]), node(A[i], 1, 0));

	for (auto e : Q) {
		int c = e.X, a = e.Y.X, b = e.Y.Y;
		if (c == 1) {
			update(pos(A[a]), node());
			A[a] += b;
			update(pos(A[a]), node(A[a], 1, 0));
		} else cout << query(pos(a), pos(b)).ans << endl;
	}
	return 0;
}