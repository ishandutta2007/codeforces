	#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
	ll n, v;
	cin >> n >> v;
	v = min(v, n - 1);
	ll res = v;
	for (ll i = 2; i <= n; i++) {
		v--;
		if (v < n - i) {
			v++;
			res += i;
		}
	}
	cout << res << "\n";
}

const ll TESTS = 1;

int main() {
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	for (ll i = 0; i < TESTS; i++) {
		solve();
	}
}