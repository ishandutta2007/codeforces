#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n], b[n], c[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	int before[n], after[n];
	before[0] = a[0];
	after[0] = b[0];
	for (int i = 1; i < n-1; i++) {
		before[i] = max(before[i-1] + b[i], after[i-1] + a[i]);
		after[i] = max(before[i-1] + c[i], after[i-1] + b[i]);
		// cout << i << "   " << before[i] << " " << after[i] << endl;
	}
	if (n > 1) {
		before[n-1] = max(before[n-2] + b[n-1], after[n-2] + a[n-1]);
	}
	if (n == 1) {
		before[n-1] = a[0];
	}
	cout << before[n-1] << endl;
	cin>> n;
}