#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}
typedef long long ll;
const ll mod = 998244353;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);

	int t;
	cin >> t;
	while (t --) {
		int l, r;
		cin >> l >> r;
		int n = r - l + 1;
		vector<int> a(n);
		for (int i = 0; i < n; i ++)
			cin >> a[i];

		vector<int> f(n);
		iota(f.begin(), f.end(), 0);

		int cnt1[20] = {0}, cnt2[20] = {0};
		for (auto x: f) {
			for (int i = 0; i < 17; i ++) if (x >> i & 1) cnt1[i] ++;
		}

		for (auto x: a) {
			for (int i = 0; i < 17; i ++) if (x >> i & 1) cnt2[i] ++;
		}

		int res = 0;
		for (int i = 0; i < 17; i ++) {
			//printf("%d %d %d\n", i, cnt1[i], cnt2[i]);
			if (cnt2[i] != cnt1[i]) res |= 1<<i;
		}
		cout << res << "\n";
	}
}

/*
1. in range
	a[i] xor x in [l, r]
2. 

*/