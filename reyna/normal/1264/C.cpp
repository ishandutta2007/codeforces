
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;

const int N = (int) 1e6 + 6, mod = (int) 998244353;
int pw(int a, int b) {
	if (b == 0) return 1;
	return (LL) pw((LL) a * a % mod, b >> 1) * (b & 1 ? a : 1) % mod;
}
int n, q, seg[N], inv[N], ch[N], chk[N], prod[N];
void build(int v = 1, int b = 0, int e = n) {
	ch[v] = 1;
	if (b + 1 == e) {
		seg[v] = prod[n] * (LL) inv[b] % mod;
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	build(l, b, m);
	build(r, m, e);
	seg[v] = (seg[l] + seg[r]) % mod;
}
void push(int v) {
	ch[v << 1 | 0] = (LL) ch[v << 1 | 0] * ch[v] % mod;
	ch[v << 1 | 1] = (LL) ch[v << 1 | 1] * ch[v] % mod;
	seg[v << 1 | 0] = (LL) seg[v << 1 | 0] * ch[v] % mod;
	seg[v << 1 | 1] = (LL) seg[v << 1 | 1] * ch[v] % mod;
	ch[v] = 1;
}
void update(int i, int j, int x, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j) return;
	if (i <= b && e <= j) {
		seg[v] = (seg[v] * (LL) x) % mod;
		ch[v] = (LL) ch[v] * x % mod;
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	push(v);
	update(i, j, x, l, b, m);
	update(i, j, x, r, m, e);
	seg[v] = (seg[l] + seg[r]) % mod;
}
int a[N];
int main() {
	ios_base::sync_with_stdio(0);
	cin >> n >> q;
	for (int j = 0; j < n; ++j) cin >> a[j];
	prod[0] = 1;
	for (int j = 0; j < n; ++j) {
		a[j] = a[j] * (LL) pw(100, mod - 2) % mod;
		a[j] = pw(a[j], mod - 2);
		prod[j + 1] = (LL) prod[j] * a[j] % mod;
	}
	for (int j = 0; j <= n; ++j) inv[j] = pw(prod[j], mod - 2);
	build();
	chk[0] = 1;
	set<int> st;
	st.insert(0);
	st.insert(n);
	while (q--) {
		int pos;
		cin >> pos;
		--pos;
		if (chk[pos]) {
			st.erase(pos);
			chk[pos] ^= 1;
			int aft = *(st.lower_bound(pos));
			int bef = *(--st.lower_bound(pos));
			update(bef, pos, (LL) prod[aft] * inv[pos] % mod);
		} else {
			chk[pos] ^= 1;
			int aft = *(st.lower_bound(pos));
			int bef = *(--st.lower_bound(pos));
			st.insert(pos);
			update(bef, pos, (LL) inv[aft] * prod[pos] % mod);
		}
		cout << seg[1] << '\n';
	}
}