#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	int Q;
	cin >> Q;
	while (Q--) {
		long long A, K;
		cin >> A >> K; --K;
		while (K--) {
			long long mn = 9, mx = 0;
			long long cur = A;
			while (cur > 0) {
				mn = min(mn, cur % 10);
				mx = max(mx, cur % 10);
				cur /= 10;
			}
			if (mn == 0) break;
			A += mn * mx;
		}
		cout << A << endl;
	}
	return 0;
}