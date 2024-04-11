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

const ll MAXN = 4e5 + 10;

int n, q;
ll sg[MAXN], mn[MAXN], mx[MAXN], lz[MAXN], lz2[MAXN];

void build(int l = 1, int r = n, int v = 1) {
	if (l == r) {
		mn[v] = mx[v] = l;
		return;
	}

	int mid = (l + r) >> 1;
	build(l, mid, v << 1);
	build(mid + 1, r, v << 1 | 1);
	mn[v] = l;
	mx[v] = r;
}

inline void push(int v) {
	if (lz[v]) {
		mx[v] = mn[v] = lz[v];
		if ((v << 1 | 1) < MAXN)
			lz[v << 1] = lz[v << 1 | 1] = lz[v];
		lz[v] = 0;
	}
}

inline void push2(int l, int r, int v) {
	if (lz2[v]) {
		sg[v] += lz2[v] * (r - l + 1);
		if ((v << 1 | 1) < MAXN) {
			lz2[v << 1] += lz2[v];
			lz2[v << 1 | 1] += lz2[v];
		}

		lz2[v] = 0;
	}
}

void update(int s, int e, int c, int l = 1, int r = n, int v = 1) {
	push(v);
	push2(l, r, v);
	if (s > r || e < l) return;
	if (s <= l && e >= r && mx[v] == mn[v]) {
		lz[v] = c;
		lz2[v] += abs(c - mx[v]);
		push(v);
		push2(l, r, v);
		return;
	}

	int mid = (l + r) >> 1;
	update(s, e, c, l, mid, v << 1);
	update(s, e, c, mid + 1, r, v << 1 | 1);
	sg[v] = sg[v << 1] + sg[v << 1 | 1];
	mx[v] = max(mx[v << 1], mx[v << 1 | 1]);
	mn[v] = min(mn[v << 1], mn[v << 1 | 1]);
}

ll query(int s, int e, int l = 1, int r = n, int v = 1) {
	push(v);
	push2(l, r, v);
	if (s > r || e < l) return 0;
	if (s <= l && e >= r) return sg[v];

	int mid = (l + r) >> 1;
	return query(s, e, l, mid, v << 1) 
		+ query(s, e, mid + 1, r, v << 1 | 1);
}

int main() {
//	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	build();

	while (q--) {
		int c;
		cin >> c;
		if (c == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			update(l, r, x);
		} else {
			int l, r;
			cin >> l >> r;
			cout << query(l, r) << endl;
		}
	}
	return 0;
}