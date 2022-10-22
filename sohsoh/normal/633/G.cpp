//: // ////: ///  / : //// / :
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

const ll MAXN = 1e5 + 2;
const ll MAXM = 1000 + 2;

int n, q, tin[MAXN], tout[MAXN], m, t, lz[MAXN << 2], A[MAXN], tin_r[MAXN];
bitset<MAXM> sg[MAXN << 2], null_bitset, prime_mask, suff_mask[MAXM];
bool B[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int p) {
	tin[v] = ++t;
	tin_r[t] = v;
	for (int u : adj[v])
		if (u != p)
			dfs(u, v);

	tout[v] = t;
}

void build(int l = 1, int r = n, int v = 1) {
	if (l == r) sg[v].set(A[tin_r[l]]);
	else {
		int mid = (l + r) >> 1;
		build(l, mid, v << 1);
		build(mid + 1, r, v << 1 | 1);
		sg[v] = sg[v << 1] | sg[v << 1 | 1];
	}
}

inline void push(int v) {
	if (lz[v]) {
		sg[v] = ((sg[v] & suff_mask[m - lz[v]]) >> (m - lz[v])) | (sg[v] << lz[v]); //
		if ((v << 1 | 1) < (MAXN << 2)) {
			lz[v << 1] = (lz[v << 1] + lz[v]) % m;
			lz[v << 1 | 1] = (lz[v << 1 | 1] + lz[v]) % m;
		}

		lz[v] = 0;
	}
}

void update(int ql, int qr, int x, int l = 1, int r = n, int v = 1) {
	push(v);
	if (ql > r || qr < l) return;
	if (ql <= l && qr >= r) {
		lz[v] = (lz[v] + x) % m;
		push(v);
		return;
	}

	int mid = (l + r) >> 1;
	update(ql, qr, x, l, mid, v << 1);
	update(ql, qr, x, mid + 1, r, v << 1 | 1);
	sg[v] = sg[v << 1] | sg[v << 1 | 1];
}

bitset<MAXM> query(int ql, int qr, int l = 1, int r = n, int v = 1) {
	push(v);
	if (ql > r || qr < l) return null_bitset;
	if (ql <= l && qr >= r) return sg[v];

	int mid = (l + r) >> 1;
	return query(ql, qr, l, mid, v << 1) |
		query(ql, qr, mid + 1, r, v << 1 | 1);
} 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> A[i], A[i] = A[i] % m;
	for (int i = m - 1; i >= 0; i--) {
		suff_mask[i] = suff_mask[i + 1];
		suff_mask[i].set(i);
	}

	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 2; i < m; i++) {
		if (!B[i]) {
			prime_mask.set(i);
			for (int j = i + i; j < m; j += i)
				B[j] = true;
		}
	}

	dfs(1, 0);
	build();

	cin >> q;
	while (q--) {
		int c;
		cin >> c;
		if (c == 1) {
			int v, x;
			cin >> v >> x;
			update(tin[v], tout[v], x);
		} else {
			int v;
			cin >> v;
			bitset<MAXM> ans = query(tin[v], tout[v]);
			ans &= prime_mask;
			cout << ans.count() << endl;
		}
	}
	return 0;
}