#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll st[3] = {1, 2, 3};
ll mv[3][4] = {{0, 1, 2, 3}, {0, 2, 3, 1}, {0, 3, 1, 2}};

void solve() {
	ll x;
	cin >> x;
	x--;
	int col = x % 3;
	x /= 3;

	ll k = 1;
	int len = 0;
	while (x >= k) {
		x -= k;
		len++;
		k *= 4;
	}

	ll val = st[col];
	while (k > 1) {
		k /= 4;
		val = val * 4 + mv[col][x / k];
		x %= k;
	}

	cout << val << " ";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}