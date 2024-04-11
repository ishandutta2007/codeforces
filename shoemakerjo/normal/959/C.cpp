#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	if (n <= 5) cout << -1 << endl;
	else {
		cout << 1 << " " << 2 << endl;
		int mid = n/2 + 1;
		for (int i = 3; i <= mid; i++) {
			cout << 2 << " " << i << endl;
		}
		for (int i = mid+1; i <= n; i++) {
			cout << 1 << " " << i << endl;
		}
	}
	for (int i = 2; i <= n; i++) {
		cout << i-1 << " " << i << endl;
	}
	cin >> n;
}