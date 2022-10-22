#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
	ll n, a, b;
	cin >> n >> a >> b;
	b = min(b, 2 * a);
	cout << (n / 2) * b + (n % 2) * a << "\n";
}

const ll TESTS = 1;

int main() {
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	for (ll i = 0; i < q; i++) {
		solve();
	}
}