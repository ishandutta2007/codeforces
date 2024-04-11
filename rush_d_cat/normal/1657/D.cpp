#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);

	int n, C;
	cin >> n >> C;
	vector<int> c(n),d(n),h(n);
	vector<ll> f(C + 1, 0);

	vector<ll> mx(C + 1, 0);
	for (int i = 0; i < n; i ++) {
		cin >> c[i] >> d[i] >> h[i];
		mx[c[i]] = max(mx[c[i]], 1ll * d[i] * h[i]);
	}
	for (int i = 1; i <= C; i ++) {
		if (mx[i] != 0) {
			for (int j = i; j <= C; j += i) {
				f[j] = max(f[j], mx[i] * (j/i) - 1); 
			}
		}
	}
	for (int i = 1; i <= C; i ++) {
		f[i] = max(f[i], f[i-1]);
		//cout << i << " " << f[i] << "\n";
	}


	int m; cin >> m;
	for (int i = 0; i < m; i ++) {
		ll D, H;
		cin >> D >> H;
		if (D * H > f[C]) {
			cout << -1 << " "; continue;
		}
		int res = lower_bound(f.begin() + 1, f.end(), D*H) - f.begin();
		cout << res << " ";
	}
}
/*
(D*H+1) / (d[i]*h[i])


[A/B] * C
*/