#include <bits/stdc++.h>

using namespace std;

bool a[20000005], v[1000005];
int b[100];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	for (int i = 1; i <= 20; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (!a[i * j]) {
				++cnt;
				a[i * j] = true;
			}
		}
		b[i] = cnt;
	}
	long long ans = 1;
	for (int i = 2; i <= n; ++i) {
		if (v[i]) continue;
		long long x = 1ll * i * i;
		int c = 1;
		while (x <= n) {
			++c;
			v[x] = true;
			x *= i;
		}
		ans += b[c];
	}
	cout << ans;
	return 0;
}