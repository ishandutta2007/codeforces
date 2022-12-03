#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(a) (a).begin(), (a).end()

using ll = long long;
using i_i = tuple<int, int>;

int main() {
	int N; cin >> N;
	vector<int> a(N * 2);
	rep(i, N * 2) scanf("%d", &a[i]);
	sort(all(a));
	ll dx = a[N - 1] - a[0];
	ll dy = a[N * 2 - 1] - a[N];
	ll ans = dx * dy;
	for (int i = 0; i + N <= N * 2; i++) {
		ll dx = a[i + N - 1] - a[i];
		ll dy = a[N * 2 - 1] - a[0];
		ans = min(ans, dx * dy);
	}
	cout << ans << endl;
}