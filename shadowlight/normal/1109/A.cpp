#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = 1 << 20;

void solve() {
	int n;
	cin >> n;
	vector <int> a(n);
	vector <int> odd(MAXN, 0), even(MAXN, 0);
	int pr = 0;
	even[0]++;
	ll res = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pr ^= x;
		if (i % 2 == 0) {
			res += odd[pr];
			odd[pr]++;
		} else {
			res += even[pr];
			even[pr]++;
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