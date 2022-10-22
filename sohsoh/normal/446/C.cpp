// Sohsoh84 :)))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 12e5 + 10;
const ll MOD = 1e9 + 9;

int n, q;
ll a[MAXN], b[MAXN], pa[MAXN], pb[MAXN],
   sg[MAXN], lz_a[MAXN], lz_b[MAXN], ps[MAXN];

inline void mkey(ll& a) {
	if (a >= MOD) a -= MOD;
}

inline pll nxt(pll e, int k) {
	k++;
	return {(e.X * a[k] + e.Y * b[k]) % MOD, 
		(e.X * a[k + 1] + e.Y * b[k + 1]) % MOD};
}

inline void push(int l, int r, int v) {
	if (lz_a[v] || lz_b[v]) {
		if (r == l) {
			mkey(sg[v] += lz_a[v]);
			lz_a[v] = lz_b[v] = 0;
			return;
		}

		int mid = (l + r) >> 1;
		mkey(lz_a[v << 1] += lz_a[v]);
		mkey(lz_b[v << 1] += lz_b[v]);

		pll e = nxt({lz_a[v], lz_b[v]}, mid + 1 - l);
		mkey(lz_a[v << 1 | 1] += e.X);
		mkey(lz_b[v << 1 | 1] += e.Y);
	
		int len = r - l + 1;
		sg[v] += pa[len] * lz_a[v] + pb[len] * lz_b[v];
		sg[v] %= MOD;
		
		lz_a[v] = lz_b[v] = 0;
	}
}

void update(pll base, int ql, int qr, int l = 1, int r = n, int v = 1) {
	push(l, r, v);
	if (ql > r || qr < l) return;
	if (ql <= l && qr >= r) {
		mkey(lz_a[v] += base.X);
		mkey(lz_b[v] += base.Y);
		push(l, r, v);
		return;
	}

	int mid = (l + r) >> 1;
	update(base, ql, qr, l, mid, v << 1);
	update(nxt(base, max(0, mid - max(ql, l) + 1)), ql, qr, mid + 1, r, v << 1 | 1);
	mkey(sg[v] = sg[v << 1] + sg[v << 1 | 1]);
}

ll query(int ql, int qr, int l = 1, int r = n, int v = 1) {
	push(l, r, v);
	if (ql > r || qr < l) return 0;
	if (ql <= l && qr >= r) return sg[v];

	int mid = (l + r) >> 1;
	return (query(ql, qr, l, mid, v << 1) + 
			query(ql, qr, mid + 1, r, v << 1 | 1)) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	a[1] = b[2] = 1;
	pa[1] = pa[2] = 1;
	pb[2] = 1;

	for (int i = 3; i < MAXN; i++) {
		mkey(a[i] = a[i - 1] + a[i - 2]);
		mkey(b[i] = b[i - 1] + b[i - 2]);
		mkey(pa[i] = pa[i - 1] + a[i]);
		mkey(pb[i] = pb[i - 1] + b[i]);
	}
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		mkey(ps[i] = ps[i - 1] + x);
	}

	while (q--) {
		int c, l, r;
		cin >> c >> l >> r;

		if (c == 1) update({1, 1}, l, r);
		else cout << (query(l, r) + ps[r] - ps[l - 1] + MOD) % MOD << endl;
	}
	return 0;
}