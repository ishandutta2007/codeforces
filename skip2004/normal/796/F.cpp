#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int maxn = 300100;
int n, m;
const int L = 1 << 19;
const int inf = 2e9;
int max[L << 1];
int t[maxn], l[maxn], r[maxn], x[maxn], k[maxn], d[maxn];
int a[maxn], b[maxn];
inline void up(int & x, int y) { if(x < y) x = y; }
inline void down(int & x, int y) { if(x > y) x = y; }
inline void upt(int ql, int qr, int v, int cur = 1, int l = 1, int r = L) {
	if(ql <= l && r <= qr) {
		return down(max[cur], v);
	}
	int mid = l + r >> 1;
	if(ql <= mid) upt(ql, qr, v, cur << 1, l, mid);
	if(mid < qr) upt(ql, qr, v, cur << 1 | 1, mid + 1, r);
}
inline int test(int x) {
	int ans = inf;
	for(x += L - 1;x;x >>= 1) down(ans, max[x]);
	return ans;
}
inline int ask(int ql, int qr, int cur = 1, int l = 1, int r = L) {
	if(ql <= l && r <= qr) return max[cur];
	int mid = l + r >> 1, ans = 0;
	if(ql <= mid) up(ans, ask(ql, qr, cur << 1, l, mid));
	if(mid < qr) up(ans, ask(ql, qr, cur << 1 | 1, mid + 1, r));
	return ans;
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> n >> m, std::fill(max, max + L + L, inf), std::fill(a + 1, a + n + 1, -1);
	for(int i = 1;i <= m;++i) {
		cin >> t[i];
		if(t[i] == 1) {
			cin >> l[i] >> r[i] >> x[i];
			upt(l[i], r[i], x[i]);
		} else {
			cin >> k[i] >> d[i];
			if(a[k[i]] == -1) a[k[i]] = test(k[i]);
		}
	}
	for(int i = 1;i <= n;++i) {
		if(a[i] == -1) a[i] = test(i);
	}
	for(int i = 1;i <= n;++i) {
		max[i + L - 1] = a[i];
		for(int x = i + L - 1;x >>= 1;) max[x] = std::max(max[x << 1], max[x << 1 | 1]);
	}
	for(int i = 1;i <= m;++i) {
		if(t[i] == 1) {
			if(ask(l[i], r[i]) != x[i]) {
				cout << "NO" << '\n';
				return 0;
			}
		} else {
			max[k[i] + L - 1] = d[i];
			for(int x = k[i] + L - 1;x >>= 1;) max[x] = std::max(max[x << 1], max[x << 1 | 1]);
		}
	}
	int cnt = 0;
	for(int i = 1;i <= n;++i) cnt += a[i] == inf;
	if(cnt >= 2) {
		for(int i = 1;i <= n;++i) {
			if(a[i] == inf) {
				static int rev = 1;
				a[i] = (1 << 29) - (rev ^= 1);
			}
		}
	} else {
		for(int i = 1;i <= n;++i) b[i] = a[i];
		std::sort(b + 1, b + n + 1);
		for(int i = n;i > 1;--i) {
			if(b[i] == b[i - 1]) {
				for(int j = 1;j <= n;++j) if(a[j] == b[i]) {
					a[j] = (1 << std::__lg(b[i])) - 1;
					break;
				}
				break;
			}
		}
		int sum = 0, ok = 0;
		for(int i = 1;i <= n;++i) if(a[i] != inf) sum |= a[i]; else ok = 1;
		if(ok) {
			int val = 0;
			for(int i = 1 << 29;i;i >>= 1) {
				if(val + i <= 1e9 && (sum & i) == 0) {
					val += i;
				}
			}
			for(int i = 1;i <= n;++i) if(a[i] == inf) a[i] = val;
		}
	}
	cout << "YES" << '\n';
	for(int i = 1;i <= n;++i) {
		cout << a[i] << " \n"[i == n];
	}
}