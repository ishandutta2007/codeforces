#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int main() {
	long long n, h;
	cin >> n >> h;
	if (h + 0.5 >= sqrt(2 * n)) {
		long long l = 0, r = 2000000000;
		while (r - l > 1) {
			long long m = (r + l) / 2;
			if (m * (m + 1) / 2 < n) {
				l = m;
			}
			else {
				r = m;
			}
		}
		cout << r;
		return 0;
	}
	else {
		long long l = h - 1, r = 2000000000;
		while (r - l > 1) {
			long long m = (r + l) / 2;
			if (m * (m + 1) / 2 + m * (m - 1) / 2 - h * (h - 1) / 2 < n) {
				l = m;
			}
			else {
				r = m;
			}
		}
		long long m = r;
		if (m * (m + 1) / 2 + m * (m - 1) / 2 - h * (h - 1) / 2 - r >= n) {
			cout << r + r - 1 - h;
		}
		else {
			cout << r + r  - h;
		}
	}
		return 0;
}