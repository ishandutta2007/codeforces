#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
typedef long long ll;
int n, k, s[N], cnt[N * 4];
vector<int> ql[N], qr[N];
ll ans;
bool rev[N * 4];

void reverse(int u, int l, int r) {
	cnt[u] = r - l + 1 - cnt[u];
	rev[u] ^= 1;
}
void pushup(int u) { cnt[u] = cnt[u << 1] + cnt[u << 1 | 1]; }
void pushdown(int u, int l, int r, int mid) {
	if (rev[u]) {
		rev[u] = false;
		reverse(u << 1, l, mid);
		reverse(u << 1 | 1, mid + 1, r);
	}
}
void reverse(int u, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) {
		reverse(u, l, r);
		return;
	}
	int mid = l + r >> 1;
	pushdown(u, l, r, mid);
	if (ql <= mid) reverse(u << 1, l, mid, ql, qr);
	if (qr > mid) reverse(u << 1 | 1, mid + 1, r, ql, qr);
	pushup(u);
}
int query(int u, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return cnt[u];
	int mid = l + r >> 1, ans = 0;
	pushdown(u, l, r, mid);
	if (ql <= mid) ans += query(u << 1, l, mid, ql, qr);
	if (qr > mid) ans += query(u << 1 | 1, mid + 1, r, ql, qr);
	return ans;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", s + i);
	sort(s + 1, s + 1 + n);
	for (int l, r; k--;) {
		scanf("%d%d", &l, &r);
		l = lower_bound(s + 1, s + 1 + n, l) - s;
		r = upper_bound(s + 1, s + 1 + n, r) - s - 1;
		if (l >= r) continue;
		ql[l].push_back(r);
		qr[r].push_back(l);
	}
	for (int i = 1; i <= n; i++) {
		for (auto r : ql[i]) reverse(1, 1, n, i, r);
		int d = 0;
		if (i > 1) d += query(1, 1, n, 1, i - 1);
		if (i < n) d += n - i - query(1, 1, n, i + 1, n);
		ans += d * (d - 1ll) >> 1;
		for (auto l : qr[i]) reverse(1, 1, n, l, i);
	}
	ans = n * (n - 1ll) * (n - 2ll) / 6ll - ans;
	cout << ans << endl;
}