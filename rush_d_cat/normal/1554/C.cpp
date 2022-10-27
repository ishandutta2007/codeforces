#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int t; cin >> t;
	while (t --) {
		LL n, m;
		cin >> n >> m;
		// n ^ i = x
		// i = n ^ x
		// n ^ x > m
		LL ans = 0;
		LL pre = 0;
		for (LL i = 32; i >= 0; i --) {
			if ((n >> i & 1) == 0) {
				LL tmp = pre + (1LL<<i) - 1;
				if (tmp <= m) {
					ans |= (1LL<<i);
					pre |= (1LL<<i);
				}
			} else {
				pre |= (1LL<<i);
			}
		}
		cout << ans << endl;
	}
}