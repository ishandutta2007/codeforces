#include <bits/stdc++.h>
using namespace std;
int main () {
	int T; cin >> T;
	while (T--) {
		long long n, k; cin >> n >> k;
		k--;
		if (n % 2 == 0) {
			cout << k % n + 1 << endl;
		} else {
			int loop = n >> 1;
			cout << (k + k / loop) % n + 1 << endl;
		}
	}
	return 0;
}