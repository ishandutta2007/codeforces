#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 50005;
ll K;
int n, P, s[N], m;
map<ll, int> _s;
vector<ll> pos;

struct matrix {
	int a[2][2];
	int *operator[](int x) { return a[x]; }
	const int *operator[](int x) const { return a[x]; }
} T[N << 2];
matrix operator*(const matrix &a, const matrix &b) {
	matrix c;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j) {
			ll s = 0;
			for (int k = 0; k < 2; ++k)
				s += 1ll * a[i][k] * b[k][j];
			c[i][j] = s % P;
		}
	return c;
}
matrix power(matrix a, ll x) {
	matrix ans = {1, 0, 0, 1};
	for (; x; x >>= 1, a = a * a)
		if (x & 1) ans = ans * a;
	return ans;
}

int query(ll x) {
	if (_s.count(x)) return _s[x];
	return s[(x + n) % n];
}
matrix query_m(ll x) {
	return (matrix){query(x), 1, query(x - 1), 0};
}

void build(int x, int l, int r) {
	if (l == r) { T[x] = query_m(l); return; }
	int mid = (l + r) / 2;
	build(x << 1, l, mid);
	build(x << 1 | 1, mid + 1, r);
	T[x] = T[x << 1] * T[x << 1 | 1];
}
matrix query(int x, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return T[x];
	int mid = (l + r) / 2;
	matrix res = {1, 0, 0, 1};
	if (ql <= mid) res = query(x << 1, l, mid, ql, qr);
	if (qr > mid) res = res * query(x << 1 | 1, mid + 1, r, ql, qr);
	return res;
}

matrix query(ll l, ll r) {
	if (l > r) return {1, 0, 0, 1};
	matrix res = query(1, 0, n - 1, l % n, min(r, l / n * n + n - 1) % n);
	if (l / n != r / n)
		res = res * power(T[1], r / n - l / n - 1) * query(1, 0, n - 1, 0, r % n);
	return res;
}

int main() {
	scanf("%lld%d", &K, &P);
	if (!K) return puts("0"), 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", s + i);
	build(1, 0, n - 1);
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		ll x; int y;
		scanf("%lld%d", &x, &y);
		if (x < K) {
			_s[x] = y;
			pos.push_back(x);
			if (x + 1 < K)
				pos.push_back(x + 1);
		}
	}
	sort(pos.begin(), pos.end());
	pos.erase(unique(pos.begin(), pos.end()), pos.end());
	ll now = 0;
	matrix res = {1, 0, 0, 1};
	for (ll x : pos)
		res = res * query(now + 1, x - 1) * query_m(x), now = x;
	res = res * query(now + 1, K - 1);
	printf("%d\n", res[0][0] % P);
	return 0;
}