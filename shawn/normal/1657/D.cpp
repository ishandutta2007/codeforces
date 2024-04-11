#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 10;
ll f[N], n, C, m, pre;

int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> n >> C;
	for (int i = 1; i <= n; i ++) {
		ll c, h, d;
		cin >> c >> h >> d;
		f[c] = max(f[c], h * d);
	}
	for (int i = 1; i <= C; i ++) {
		for (int j = i; j <= C; j += i)
			f[j] = max(f[j], f[i] * j / i);
	}
	for (int i = 1; i <= C; i ++) {
		pre = max(pre, f[i]);
		f[i] = pre;
	}
	cin >> m;
	while (m --) {
		ll h, d;
		cin >> h >> d;
		int ans = lower_bound(f + 1, f + C + 1, h * d + 1) - f;
		if (f[ans] < h * d + 1) cout << "-1 ";
		else cout << ans << " ";
	}
	return 0;	
}