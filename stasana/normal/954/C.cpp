#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef int_fast64_t ll;

void start() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main() {
	start();
	int n;
	cin >> n;
	if (n == 1) {
		cout << "YES" << endl;
		cout << 1000 * 1000 * 1000 << " " << 1000 * 1000 * 1000;
		return 0;
	}
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int x = -1;
	for (int i = 1; i < n; ++i) {
		if (abs(a[i] - a[i - 1]) != 1) {
			if (x != -1 && x != abs(a[i] - a[i - 1])) {
				cout << "NO";
				return 0;
			}
			x = abs(a[i] - a[i - 1]);
		}
	}
	if (x == -1) {
		cout << "YES" << endl;
		cout << 1000 * 1000 * 1000 << " " << 1000 * 1000 * 1000;
		return 0;
	}
	if (x == 0) {
		cout << "NO";
		return 0;
	}
	for (int i = 1; i < n; ++i) {
		if (a[i] - a[i - 1] == 1) {
			if (a[i - 1] % x == 0) {
				cout << "NO";
				return 0;
			}
		}
		if (a[i] - a[i - 1] == -1) {
			if (a[i] % x == 0) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	cout << 1000 * 1000 * 1000 << " " << x;
	return 0;
}