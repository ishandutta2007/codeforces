#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pll;

#define X			first
#define Y			second

const int MAXN = 5e6;
const int LOG = 21;

int n, A[MAXN];
pll dp[MAXN];

inline void push(pll& e, int x) {
	if (x > e.X) {
		e.Y = e.X;
		e.X = x;
	} else if (x > e.Y) {
		e.Y = x;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		push(dp[A[i]], i);
	}

	for (int i = 0; i < LOG; i++) {
		for (int mask = 0; mask < MAXN; mask++) {
			if (!(mask >> i & 1)) {
				push(dp[mask], dp[mask ^ (1 << i)].X);
				push(dp[mask], dp[mask ^ (1 << i)].Y);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n - 2; i++) {
		int mask = 0;
		for (int j = LOG - 1; j >= 0; j--)
			if (!(A[i] >> j & 1) && dp[mask ^ (1 << j)].Y > i)
				mask ^= (1 << j);
		ans = max(ans, A[i] | mask);
	}

	cout << ans << endl;
	return 0;
}