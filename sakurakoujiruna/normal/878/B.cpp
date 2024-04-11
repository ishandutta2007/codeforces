#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e6L + 11;

int a[N], b[N], c[N];
int sl[N], sr[N];

int solve(int n, int k, int *a, int *b) {
	int m = 0;
	for(int i = 1; i <= n; i ++) {
		b[++ m] = a[i];
		if(b[m] == b[m - 1])
			sl[m] = sl[m - 1];
		else
			sl[m] = m;
		if(m - sl[m] + 1 == k)
			m -= k;
	}
	return m;
}

int main() {
	ios :: sync_with_stdio(0);
	int n, k, m; cin >> n >> k >> m;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	
	if(k >= n) {
		if(count(a + 1, a + n + 1, a[1]) == n)
			cout << ll(n) * m % k << '\n';
		else
			cout << ll(n) * m << '\n';
		return 0;
	}
	
	{
		int nn = solve(n, k, a, b);
		n = nn;
		for(int i = 1; i <= n; i ++)
			a[i] = b[i];
	}
	
	int l = 1, r = n;
	
	for(int i = 1; i <= n; i ++)
		if(a[i] == a[i - 1])
			sl[i] = sl[i - 1];
		else
			sl[i] = i;
	for(int i = n; i >= 1; i --)
		if(a[i] == a[i + 1])
			sr[i] = sr[i + 1];
		else
			sr[i] = i;

	while(r - l + 1 >= k) {
		if(a[l] == a[r] && sr[l] + r - l - sl[r] + 2 >= k) {
			int b = k - (sr[l] - l + 1);
			l = sr[l] + 1;
			r -= b;
		} else
			break;
	}
	
	if(l == 1 && r == n) {
		cout << ll(n) * m << '\n';
		return 0;
	}
	
	int mid = 0;
	ll ans = ll(m) * (r - l + 1) + (l - 1) + (n - r);
	if(l <= r && count(a + l, a + r + 1, a[l]) == r - l + 1) {
		int mid = ll(r - l + 1) * m % k;
		ans -= ll(r - l + 1) * m / k * k;
	
		for(int i = 1; i <= l - 1; i ++)
			b[i] = a[i];
		for(int i = 1; i <= mid; i ++)
			b[l + i - 1] = a[l];
		for(int i = 1; i <= n - r; i ++)
			b[l + mid + i - 1] = a[r + i];
		
		int nn = solve(l - 1 + n - r + mid, k, b, c);
		ans -= l - 1 + n - r + mid - nn;
		cout << ans << '\n';
	} else
		cout << ll(r - l + 1) * m + (l - 1) + (n - r) << '\n';
}