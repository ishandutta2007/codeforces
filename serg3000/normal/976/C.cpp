#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
	long long n;
	cin >> n;
	vector<vector<int>>a(n, vector<int>(3));
	for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1];
		a[i][2] = i;
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n - 1; i++) {
		if (a[i][1] >= a[i + 1][1]) {
			cout << a[i + 1][2] + 1 << " " << a[i][2] + 1;
			return 0;
		}
		if (a[i][0] == a[i + 1][0]) {
			cout << a[i][2] + 1 << " " << a[i + 1][2] + 1;
			return 0;
		}
	}
	cout << -1 << " " << -1;
	return 0;
}