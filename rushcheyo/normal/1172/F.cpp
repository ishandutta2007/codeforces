#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1000005;
const ll inf = (ll)1e16;
int n, m, P, a[N];
ll sum[N];
vector<ll> func[N << 2];

vector<ll> merge(int l, int r, int mid, const vector<ll> &f, const vector<ll> &g) {
	ll suml = sum[mid] - sum[l - 1], sumr = sum[r] - sum[mid];
	vector<ll> ret(f.size() + g.size() - 1, inf);
	for (int i = 0, j = 0; i < (int)f.size(); ++i) {
		ll xl = f[i], xr = (i + 1 == (int)f.size() ? inf : f[i + 1] - 1), yl = xl + suml - (ll)i * P, yr = xr + suml - (ll)i * P;
		while (j > 0 && g[j] > yl) --j;
		while (j < (int)g.size() && (j == 0 || g[j] <= yl)) ++j;
		--j;
		for (; j < (int)g.size() && g[j] <= yr; ++j)
			ret[i + j] = min(ret[i + j], max(xl, g[j] - suml + (ll)i * P));
	}
	ret[0] = -inf;
	return ret;
}
void build(int u, int l, int r) {
	if (l == r) {
		func[u].push_back(-inf);
		func[u].push_back(P - a[l]);
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	func[u] = merge(l, r, mid, func[u << 1], func[u << 1 | 1]);
}
ll query(int u, int l, int r, int ql, int qr, ll now) {
	if (l >= ql && r <= qr)
		return now + sum[r] - sum[l - 1] - (ll)P * (upper_bound(func[u].begin(), func[u].end(), now) - func[u].begin() - 1);
	int mid = l + r >> 1;
	if (qr <= mid)
		return query(u << 1, l, mid, ql, qr, now);
	if (ql > mid)
		return query(u << 1 | 1, mid + 1, r, ql, qr, now);
	return query(u << 1 | 1, mid + 1, r, ql, qr, query(u << 1, l, mid, ql, qr, now));
}

int main() {
	scanf("%d%d%d", &n, &m, &P);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i), sum[i] = sum[i - 1] + a[i];
	build(1, 1, n);
	for (int l, r; m--;) {
		scanf("%d%d", &l, &r);
		printf("%lld\n", query(1, 1, n, l, r, 0));
	}
	return 0;
}