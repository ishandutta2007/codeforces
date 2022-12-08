#include <bits/stdc++.h>

using namespace std;

int a[1 << 18];
int swp[19], rev[19];
vector<long long> s[19];

long long getSum(int b, int l, int r) {
	if ((l & (1 << b) - 1) == 0 && (r & (1 << b) - 1) == (1 << b) - 1) return s[b][l >> b];
	if (rev[b]) {
		swap(l, r);
		l ^= (1 << b) - 1;
		r ^= (1 << b) - 1;
	}
	if (!swp[b - 1]) {
		if (r < (l >> b << b | 1 << (b - 1))) return getSum(b - 1, l, r);
		if (l >= (l >> b << b | 1 << (b - 1))) return getSum(b - 1, l, r);
		return getSum(b - 1, l, (l >> b << b | 1 << (b - 1)) - 1) + getSum(b - 1, l >> b << b | 1 << (b - 1), r);
	} else {
		if (r < (l >> b << b | 1 << (b - 1))) return getSum(b - 1, l ^ 1 << (b - 1), r ^ 1 << (b - 1));
		if (l >= (l >> b << b | 1 << (b - 1))) return getSum(b - 1, l ^ 1 << (b - 1), r ^ 1 << (b - 1));
		return getSum(b - 1, l ^ 1 << (b - 1), (l >> b << b) + (1 << b) - 1) +
			   getSum(b - 1, l >> b << b, r ^ 1 << (b - 1));
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < 1 << n; ++i) cin >> a[i], s[0].push_back(a[i]);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < s[i - 1].size(); j += 2) {
			s[i].push_back(s[i - 1][j] + s[i - 1][j + 1]);
		}
	}
	while (q--) {
		int o;
		cin >> o;
		if (o == 1) {
			int x, k;
			cin >> x >> k;
			--x;
			for (int i = n; i >= 0; --i) {
				if (swp[i]) x ^= 1 << i;
				if (rev[i]) x ^= (1 << i) - 1;
			}
			int d = k - a[x];
			a[x] = k;
			for (int i = 0; i <= n; ++i) {
				s[i][x] += d;
				x >>= 1;
			}
		} else if (o == 2) {
			int k;
			cin >> k;
			rev[k] ^= 1;
		} else if (o == 3) {
			int k;
			cin >> k;
			swp[k] ^= 1;
		} else {
			int l, r;
			cin >> l >> r;
			cout << getSum(n, l - 1, r - 1) << '\n';
		}
	}
	return 0;
}