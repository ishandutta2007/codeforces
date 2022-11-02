#include <bits/stdc++.h>
using namespace std;

const int N = 1e5L + 11;
using ll = long long;
ll a[N];

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	ll ans = 0;
	for(int i = 1; i <= n; i ++) {
		ans += a[i] * a[n - i + 1];
		ans %= 10007;
	}
	cout << ans << '\n';
}