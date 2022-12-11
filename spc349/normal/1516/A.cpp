#include <bits/stdc++.h>
using namespace std;

int a[110];

int main() {
	int T; cin >> T;
	while (T--) {
		int n, k; cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) {
			while (k && a[i] > 0) a[i]--, a[n - 1]++, k--;
		}
		for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
	}
	return 0;
}