#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAXN = 2e6 + 10;

int R[MAXN];
ll A[MAXN], ps[MAXN], q, n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = n + 1; i <= 2 * n; i++) A[i] = A[i - n];

	for (int i = 1; i <= 2 * n; i++)
		ps[i] = ps[i - 1] + A[i];
	
	while (q--) {
		ll x;
		cin >> x;
		if (ps[n] <= x) {
			cout << 1 << endl;
			continue;
		} 

		int ans = n, mn = n;
		R[2 * n] = 2 * n;
		
		for (int i = 2 * n - 1; i > 0; i--) {
			R[i] = R[i + 1];
			while (ps[R[i]] - ps[i - 1] > x) R[i]--;

			if (i < n && R[i] - i < R[mn] - mn) mn = i;
		}

		for (int ts = max(mn - 1, 1); ts <= min(R[mn] + 1ll, 2 * n); ts++) {
			int s = (ts > n ? ts - n : ts), tans = 0;
			for (int i = s; i < s + n; i = R[i] + 1, tans++);
			ans = min(ans, tans);
		}

		cout << ans << endl;
	}
	return 0;
}