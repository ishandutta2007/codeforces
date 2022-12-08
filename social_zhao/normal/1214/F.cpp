#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int m, n; 
pair<int, int> a[N], b[N];
int c[N], d[N], s[N], ans[N], mx;

void add(int l, int r, int x) {
	if(l < 0 && r < 0) l += n, r += n;
	if(l < 0) s[l + n] += x, l = 0;
	s[l] += x, s[r + 1] -= x;
}

signed main() {
	m = get(), n = get();
	for(int i = 1; i <= n; i++) a[i].first = get(), a[i].second = i;
	for(int i = 1; i <= n; i++) b[i].first = get(), b[i].second = i;
	sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + n);
	for(int i = 1; i <= n; i++) c[i] = a[i].first, d[i] = b[i].first;
	for(int i = 1; i <= n; i++) {
		int l, r, p, q, x = b[i].first;
		l = max(1ll, x - m / 2), r = x;
		p = lower_bound(c + 1, c + 1 + n, l) - c, q = upper_bound(c + 1, c + 1 + n, r) - c - 1;
		add(i - q, i - p, x);
		if(x - 1 > m - x + 1) {
			l = 1, r = x - m / 2 - 1;
			p = lower_bound(c + 1, c + 1 + n, l) - c, q = upper_bound(c + 1, c + 1 + n, r) - c - 1;
			add(i - q, i - p, m - x);
		}
		l = x + 1, r = min(m, x + m / 2);
		p = lower_bound(c + 1, c + 1 + n, l) - c, q = upper_bound(c + 1, c + 1 + n, r) - c - 1;
		add(i - q, i - p, -x);
		if(m - x > x) {
			l = x + m / 2 + 1, r = m;
			p = lower_bound(c + 1, c + 1 + n, l) - c, q = upper_bound(c + 1, c + 1 + n, r) - c - 1;
			add(i - q, i - p, m + x);
		}
	}
	for(int i = 1; i <= n; i++) {
		int l, r, p, q, x = a[i].first;
		l = max(1ll, x - m / 2), r = x - 1;
		p = lower_bound(d + 1, d + 1 + n, l) - d, q = upper_bound(d + 1, d + 1 + n, r) - d - 1;
		add(p - i, q - i, x);
		if(x - 1 > m - x + 1) {
			l = 1, r = x - m / 2 - 1;
			p = lower_bound(d + 1, d + 1 + n, l) - d, q = upper_bound(d + 1, d + 1 + n, r) - d - 1;
			add(p - i, q - i, -x);
		}
		l = x, r = min(m, x + m / 2);
		p = lower_bound(d + 1, d + 1 + n, l) - d, q = upper_bound(d + 1, d + 1 + n, r) - d - 1;
		add(p - i, q - i, -x);
		if(m - x > x) {
			l = x + m / 2 + 1, r = m;
			p = lower_bound(d + 1, d + 1 + n, l) - d, q = upper_bound(d + 1, d + 1 + n, r) - d - 1;
			add(p - i, q - i, x);
		}
	}
	for(int i = 0; i < n; i++) {
		if(i) s[i] += s[i - 1];
		if(s[i] < s[mx]) mx = i;
	}
	for(int i = 1; i <= n; i++) 
		ans[a[i].second] = b[(i + mx > n)? (i + mx - n) : (i + mx)].second;
	printf("%lld\n", s[mx]);
	for(int i = 1; i <= n; i++) printf("%lld ", ans[i]);
	return 0;
}