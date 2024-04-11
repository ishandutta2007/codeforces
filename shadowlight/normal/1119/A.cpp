#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (a[0] != a[n - 1]) {
		cout << n - 1 << "\n";
		return 0;
	}
	int l = 0, r = n - 1;
	while (l < n - 1 && a[l + 1] == a[0]) {
		l++;
	}
	while (r > 0 && a[r - 1] == a[n - 1]) {
		r--;
	}
	cout << max(n - l - 2, r - 1) << "\n";
}