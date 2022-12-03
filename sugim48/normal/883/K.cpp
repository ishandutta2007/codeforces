#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
typedef long long ll;

int main() {
	int N; cin >> N;
	vector<ll> a(N), b(N);
	rep(i, N) {
		scanf("%lld%lld", &a[i], &b[i]);
		b[i] += a[i];
	}
	ll ans = 0;
	rep(i, N) ans -= a[i];
	for (int i = 0; i + 1 < N; i++) {
		a[i + 1] = max(a[i + 1], a[i] - 1);
		b[i + 1] = min(b[i + 1], b[i] + 1);
	}
	for (int i = N - 1; i - 1 >= 0; i--) {
		a[i - 1] = max(a[i - 1], a[i] - 1);
		b[i - 1] = min(b[i - 1], b[i] + 1);
	}
	rep(i, N) if (a[i] > b[i]) {
		cout << -1 << endl;
		return 0;
	}
	rep(i, N) ans += b[i];
	cout << ans << endl;
	rep(i, N) printf("%lld ", b[i]);
	cout << endl;
}