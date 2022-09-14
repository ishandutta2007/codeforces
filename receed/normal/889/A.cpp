#include <bits/stdc++.h>

using namespace std;


int main() {
	int n, t, ans = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 1; i <= n; i++) {
		cin >> t;
		if (!a[t])
			ans++;
		a[t]++;
	}
	cout << n + 1 - ans;
}