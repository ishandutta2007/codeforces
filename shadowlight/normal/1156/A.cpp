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
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		if (a[i - 1] == 1 || a[i] == 1) {
			cnt += a[i] + a[i - 1];
		} else {
			cout << "Infinite\n";
			return 0;
		}
		if (i > 1 && a[i - 2] == 3 && a[i - 1] == 1 && a[i] == 2) {
			cnt--;
		}
	}
	cout << "Finite\n";
	cout << cnt << "\n";
}