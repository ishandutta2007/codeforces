#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, x, odd = 0, even = 0;
	cin >> n;
	while (n--) {
		cin >> x;
		if (x % 2) odd++;
		else even++;
	}
	cout << ((even && odd) || odd % 2 ? "YES\n" : "NO\n"); 
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