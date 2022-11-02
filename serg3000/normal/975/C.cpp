#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
	long long n, q;
	cin >> n >> q;
	vector<long long> a(n);
	vector<long long> k(q);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < q; i++) {
		cin >> k[i];
	}
	
	vector<long long> pref(n);
	pref[0] = a[0];
	for (int i = 1; i < n; i++) {
		pref[i] = pref[i - 1] + a[i];
	}
	long long c = 0, cnt = 0;
	for (int i = 0; i < q; i++) {
		cnt += k[i];
		if (cnt >= pref[n - 1]) {
			cout << n << '\n';
			cnt = 0;
		}
		else {
			long long l = -1, r = n - 1;
			while (r - l > 1) {
				long long m = (l + r) / 2;
				if (pref[m] > cnt) {
					r = m;
				}
				else {
					l = m;
				}
			}
			cout << n - r << '\n';
		}
	}
	return 0;
}