//: // ////: ///  / : //// / :
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define mp			make_pair
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXM = 1e6 + 10;
const ll MAXN = 10 + 2;

int A[MAXN][MAXM], n, m, q, par[MAXN << 2];
vector<int> C[MAXN << 2];

inline void add(int ind, int id) {
	C[id].push_back(ind);
	par[ind] = id;
}

inline bool unite(int a, int b) {
	a = par[a], b = par[b];
	if (a == b) return false;
	
	if (C[a].size() < C[b].size()) swap(a, b);
	for (int e : C[b]) add(e, a);
	C[b].clear();
	return true;
}

struct Node {
	bool b = false;
	pll L[MAXN], R[MAXN];
	int ans = 0;

	Node(bool b = false) : b(b) {}

	Node(int ind) {
		for (int i = 1; i <= n; i++) {
			L[i] = R[i] = (A[i][ind] == A[i - 1][ind] ? mp(A[i][ind], ans) : mp(A[i][ind], ++ans));
		}
	}	
} sg[MAXM];

Node merge(Node a, Node b) {
	if (a.b) return b;
	if (b.b) return a;
	Node res = Node();
	res.ans = a.ans + b.ans;

	memset(par, 0, sizeof par);
	for (int i = 0; i < (MAXN << 2); i++) C[i].clear();

	for (int i = 1; i <= n; i++) {
		add(i, a.L[i].Y);
		add(n + i, a.R[i].Y);
		add(2 * n + i, b.L[i].Y + (MAXN << 1));
		add(3 * n + i, b.R[i].Y + (MAXN << 1));
	
		res.L[i].X = a.L[i].X;
		res.R[i].X = b.R[i].X;
	}

	for (int i = 1; i <= n; i++)
		if (a.R[i].X == b.L[i].X)
			res.ans -= unite(n + i, 2 * n + i);

	int id = 1;
	for (int i = 0; i < (MAXN << 2); i++) {
		bool f = false;
		for (int e : C[i]) {
			if (e <= n) res.L[e].Y = id, f = true;
			if (e > 3 * n) res.R[e - 3 * n].Y = id, f = true;
		}

		id += f;
	}

	return res;
}

void build(int l = 1, int r = m, int v = 1) {
	if (l == r) sg[v] = Node(l);
	else {
		int mid = (l + r) >> 1;
		build(l, mid, v << 1);
		build(mid + 1, r, v << 1 | 1);
		sg[v] = merge(sg[v << 1], sg[v << 1 | 1]);
	}
}

Node query(int ql, int qr, int l = 1, int r = m, int v = 1) {
	if (ql > r || qr < l) return Node(true);
	if (ql <= l && qr >= r) return sg[v];

	int mid = (l + r) >> 1;
	return merge(query(ql, qr, l, mid, v << 1),
			query(ql, qr, mid + 1, r, v << 1 | 1));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> A[i][j];
	build();
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << query(l, r).ans << endl;
	}
	return 0;
}