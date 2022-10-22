#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <int> a(n);
	int odd = 0, even = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 2) {
			odd++;
		} else {
			even++;
		}
	}
	if (!odd || !even) {
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		return 0;
	} else {
		sort(a.begin(), a.end());
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << "\n";
	}
}