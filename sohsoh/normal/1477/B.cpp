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

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 2e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, q;
string s, f;
stack<pll> Q;
ll sg[MAXN], lz[MAXN], mark[MAXN];

inline void push(int v, int s) {
	if (s <= 0) return;
	if (mark[v]) {
		lz[2 * v] = lz[2 * v + 1] = lz[v];
		mark[2 * v] = mark[2 * v + 1] = true;
		sg[v] = s * lz[v];	
		mark[v] = false;
	}
}

void Update(int v, int l, int r, int ql, int qr, int val) {	
	if (r < l) return; 
	push(v, r - l + 1);
	if (r < l || qr < l || ql > r) return;
	if (ql <= l && qr >= r) {
		lz[v] = val;
		mark[v] = true;
		push(v, r - l + 1);
		return;
	} 
	
	push(v, r - l + 1);
	int mid = (l + r) >> 1;
	Update(2 * v, l, mid, ql, qr, val);
	Update(2 * v + 1, mid + 1, r, ql, qr, val);
	sg[v] = sg[2 * v] + sg[2 * v + 1];
}

int Query(int v, int l, int r, int ql, int qr) {		
	if (r < l) return 0;
	push(v, r - l + 1);
	if (r < l || qr < l || ql > r) return 0;
	if (ql <= l && qr >= r) return sg[v];
	int mid = (l + r) >> 1;
	return Query(2 * v, l, mid, ql, qr) + Query(2 * v + 1, mid + 1, r, ql, qr);
}

inline int solve() {
	for (int i = 0; i < 4 * n + 10; i++) mark[i] = false, lz[i] = 0, sg[i] = 0;
	while (!Q.empty()) Q.pop();

	cin >> n >> q >> s >> f;
	s = '.' + s;
	f = '.' + f;
	while (q--) {
		int L, R;
		cin >> L >> R;
		Q.push({L, R});
	}

	for (int i = 1; i <= n; i++) Update(1, 1, n, i, i, int(f[i] - '0'));
	while (!Q.empty()) {
		int L = Q.top().X, R = Q.top().Y;
		Q.pop();
		int cnt = Query(1, 1, n, L, R);
		int s = R - L + 1;
		if (s % 2 == 0 && cnt == s / 2) return cout << "NO" << endl, 0;
		if (cnt <= s / 2) Update(1, 1, n, L, R, 0);
		else Update(1, 1, n, L, R, 1);
	}
	
	for (int i = 1; i <= n; i++) if (Query(1, 1, n, i, i) != int(s[i] - '0')) return cout << "NO" << endl, 0;
	cout << "YES" << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	fill(lz, lz + MAXN, 3);
/*	n = 20;
	while (true) {
		int q;
		cin >> q;
		if (q == 1) {
			int l, r;
			cin >> l >> r;
			cout << Query(1, 1, n, l, r) << endl;
		} else if (q == 2) {
			int l, r, c;
			cin >> l >> r >> c;
			Update(1, 1, n, l, r, c);
		} else {
			for (int i = 1; i <= 2 * n; i++) cerr << i << ": " << sg[i] << sep << lz[i] << endl;
		}
	}
*/	return 0;
}