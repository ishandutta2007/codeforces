//In the name of God
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 4e5 + 9;
const int base = 97;
const int mod = 98765431;
int ch[N], h[N], hnum[N][10], pw[N], n;
string s;
void prop(int v, int b, int e) {
	if (ch[v] == -1)
		return;
	int mid = b + e >> 1, l = v << 1, r = l | 1;
	ch[l] = ch[v];
	ch[r] = ch[v];
	h[l] = hnum[mid - b][ch[v]];
	h[r] = hnum[e - mid][ch[v]];
	ch[v] = -1;
	return;
}
void build(int v = 1, int b = 0, int e = n) {
	if (b + 1 == e) {
		h[v] = hnum[1][s[b] - '0'];
		return;	
	}
	int mid = b + e >> 1, l = v << 1, r = l | 1;
	build(l, b, mid);
	build(r, mid, e);
	h[v] = (h[r] * pw[mid - b] + h[l]) % mod;
}
void update(int i, int j, int c, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j)
		return;
	if (i <= b && e <= j) {
//		cout << " Damnit " << hnum[e - b - 1][c] << ' ' << e - b - 1 << ' ' << c << endl;
		h[v] = hnum[e - b][c];
		ch[v] = c;
		return;
	}
	int mid = b + e >> 1, l = v << 1, r = l | 1;
	prop(v, b, e);
	update(i, j, c, l, b, mid);
	update(i, j, c, r, mid, e);
	h[v] = (h[r] * pw[mid - b] + h[l]) % mod;
	return;
}
int query(int i, int j, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j)
		return 0;
	if (i <= b && e <= j) {
//		cout << b << ' ' << e << ' ' << h[v] << endl;
		return (h[v] * pw[b - i]) % mod;
	}
	int mid = b + e >> 1, l = v << 1, r = l | 1;
	prop(v, b, e);
	assert((h[r] * pw[mid - b] + h[l]) % mod == h[v]);
	return (query(i, j, l, b, mid) + query(i, j, r, mid, e)) % mod;
}
int32_t main() {
	memset(ch, -1, sizeof ch);
	ios_base::sync_with_stdio(0);
	int m, k; cin >> n >> m >> k;
	for (int i = 0; i < N; ++i)
		pw[i] = i? (pw[i - 1] * base) % mod: 1;
	for (int c = 0; c < 10; ++c)
		for (int i = 0; i < N; ++i)
			hnum[i][c] = i? (hnum[i - 1][c] * base + c + 'a') % mod: 0;
	cin >> s;
//	build();
	for (int i = 0; i < n; ++i)
		update(i, i + 1, s[i] - '0');
	int q = m + k;
	while (q--) {
		int c; cin >> c;
		if (c == 1) {
			int l, r, cc; cin >> l >> r >> cc; --l, r;
			update(l, r, cc);
		} else {
			int l, r, d; cin >> l >> r >> d; --l, r;
			int x = query(l, r - d), y = query(l + d, r);
			x %= mod;
			y %= mod;
			while (x < 0)
				x += mod;
			while (y < 0)
				y += mod;
	//		cout << " hi " << x << ' ' << y << endl;
			if (x == y) {
				cout << "YES\n";	
			} else {
				cout << "NO\n";	
			}
		}
	}
}