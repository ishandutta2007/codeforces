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

const ll MAXN = 2e5 + 40;
const ll LOG = 20;

int n, q, sg[(MAXN + 20) << 2], A[MAXN];
bool lz[(MAXN + 20) << 2];

inline void push(int v, int l, int r) {
	if (lz[v]) {
		sg[v] = (r - l + 1) - sg[v];
		if (l < r) {
			lz[v << 1] ^= 1;
			lz[v << 1 | 1] ^= 1;
		}

		lz[v] = false;
	}
}

void update(int ql, int qr, int l = 1, int r = MAXN, int v = 1) {
	push(v, l, r);
	if (ql > r || qr < l) return;
	if (ql <= l && qr >= r) {
		lz[v] ^= 1;
		push(v, l, r);
		return;
	}

	int mid = (l + r) >> 1;
	update(ql, qr, l, mid, v << 1);
	update(ql, qr, mid + 1, r, v << 1 | 1);
	sg[v] = sg[v << 1] + sg[v << 1 | 1];
}

int find_first(int ql, bool flag, int l = 1, int r = MAXN, int v = 1) {
	push(v, l, r);
	if ((flag && !sg[v]) || (!flag && sg[v] == (r - l + 1))) return 0;
	if (l == r) return l;

	int mid = (l + r) >> 1;
	if (mid < ql) return find_first(ql, flag, mid + 1, r, v << 1 | 1);
	
	int ans = find_first(ql, flag, l, mid, v << 1);
	if (ans) return ans;
	return find_first(ql, flag, mid + 1, r, v << 1 | 1);
}

int find_last(int l = 1, int r = MAXN, int v = 1) {
	push(v, l, r);
	if (sg[v] == 0) return 0;
	if (l == r) return l;
	int mid = (l + r) >> 1;

	int ans = find_last(mid + 1, r, v << 1 | 1);
	if (ans) return ans;
	return find_last(l, mid, v << 1);
}

inline void add(int x) {
	int ind = find_first(x, 0);
	update(x, ind);
}

inline void remove(int x) {
	int ind = find_first(x, 1);
	update(x, ind);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		add(A[i]);
	}

	while (q--) {
		int k, x;
		cin >> k >> x;
		remove(A[k]);
		A[k] = x;
		add(A[k]);
		cout << find_last() << endl;
	}
	return 0;
}