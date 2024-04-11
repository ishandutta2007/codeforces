// Sohsoh84 :)))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 3e5 + 10;
const ll INF = 1e8;

int n, A[MAXN], lz[MAXN << 2];
pll sg[MAXN << 2];

inline pll merge(pll a, pll b) {
	pll ans = {min(a.X, b.X), 0};
	if (a.X == ans.X) ans.Y += a.Y;
	if (b.X == ans.X) ans.Y += b.Y;
	return ans;
}

inline void push(int v) {
	if (lz[v]) {
		sg[v].X += lz[v];
		if ((v << 1 | 1) < (MAXN << 2)) {
			lz[v << 1] += lz[v];
			lz[v << 1 | 1] += lz[v];
		}

		lz[v] = 0;
	}
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
	for (int i = 0; i < (MAXN << 2); i++)
		sg[i] = {INF, 1};
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int r, c;
		cin >> r >> c;
		A[r] = c;
	}

	stack<int> mn, mx;
	mn.push(n + 1);
	mx.push(n + 1);

	ll ans = 0;
	for (int i = n; i > 0; i--) {
		update(i, i, -INF);
		if (i < n) update(i + 1, n, -1);
	
		while (mn.top() <= n && A[i] < A[mn.top()]) {
			int ind = mn.top();
			mn.pop();
			update(ind, mn.top() - 1, A[ind] - A[i]);
		}
		
		while (mx.top() <= n && A[i] > A[mx.top()]) {
			int ind = mx.top();
			mx.pop();
			update(ind, mx.top() - 1, A[i] - A[ind]);
		}

		mn.push(i);
		mx.push(i);
		if (sg[1].X == 0) ans += sg[1].Y;
	}

	cout << ans << endl;
	return 0;
}