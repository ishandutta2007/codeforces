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

const ll MAXN = 12e5 + 10;

struct node {
	ll l_val, r_val, pref_inc, pref_dec, suff_inc, suff_dec, ans_pref, ans_suff, ans, len;
	
	node(int val): l_val(val), r_val(val), pref_inc(1), pref_dec(1), suff_inc(1), suff_dec(1),
		ans_pref(1), ans_suff(1), ans(1), len(1) {}
	node(): l_val(0), r_val(0), pref_inc(0), pref_dec(0), suff_inc(0), suff_dec(0),
		ans_pref(0), ans_suff(0), ans(0), len(0) {}
};

inline node merge(node a, node b) {
	node ans = node();
	ans.l_val = a.l_val;
	ans.r_val = b.r_val;
	ans.len = a.len + b.len;

	ans.pref_inc = a.pref_inc;
	ans.pref_dec = a.pref_dec;
	ans.suff_inc = b.suff_inc;
	ans.suff_dec = b.suff_dec;

	ans.ans_pref = a.ans_pref;
	ans.ans_suff = b.ans_suff;
	ans.ans = max(a.ans, b.ans);

	if (a.r_val < b.l_val) {
		if (a.pref_inc == a.len) {
			ans.pref_inc += b.pref_inc;
			ans.ans_pref = max(ans.ans_pref, a.pref_inc + b.ans_pref);
		}

		if (b.suff_inc == b.len) ans.suff_inc += a.suff_inc;
		
		ans.ans = max(ans.ans, b.ans_pref + a.suff_inc);
		if (b.ans_suff == b.len) ans.ans_suff += a.suff_inc;
	}


	if (a.r_val > b.l_val) {
		if (b.suff_dec == b.len) {
			ans.suff_dec += a.suff_dec;
			ans.ans_suff = max(ans.ans_suff, b.suff_dec + a.ans_suff);
		}

		if (a.pref_dec == a.len) ans.pref_dec += b.pref_dec;
		ans.ans = max(ans.ans, a.ans_suff + b.pref_dec);
		if (a.ans_pref == a.len) ans.ans_pref += b.pref_dec;
	}


	return ans;
}

node sg[MAXN];
ll lz[MAXN], n, q, A[MAXN];

void build(int l = 1, int r = n, int v = 1) {
	if (l == r) sg[v] = node(A[l]);
	else {
		int mid = (l + r) >> 1;
		build(l, mid, v << 1);
		build(mid + 1, r, v << 1 | 1);
		sg[v] = merge(sg[v << 1], sg[v << 1 | 1]);
	}
}

inline void push(int v) {
	sg[v].l_val += lz[v];
	sg[v].r_val += lz[v];
	
	if ((v << 1 | 1) < MAXN)
		lz[v << 1] += lz[v], lz[v << 1 | 1] += lz[v];

	lz[v] = 0;
}

void update(int ql, int qr, int val, int l = 1, int r = n, int v = 1) {
	push(v);
	if (ql > r || qr < l) return;
	if (ql <= l && qr >= r) {
		lz[v] += val;
		push(v);
		return;
	}

	int mid = (l + r) >> 1;
	update(ql, qr, val, l, mid, v << 1);
	update(ql, qr, val, mid + 1, r, v << 1 | 1);
	sg[v] = merge(sg[v << 1], sg[v << 1 | 1]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];

	build();
	cin >> q;
	while (q--) {
		int l, r, val;
		cin >> l >> r >> val;
		update(l, r, val);
		cout << sg[1].ans << endl;
	}
	return 0;
}