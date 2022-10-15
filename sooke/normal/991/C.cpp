#include <iostream>

using namespace std;

long long n, ans, _max;

inline long long Check(long long d) {
	bool flag = true;
	long long res = 0, lef = n;
	while (lef > 0) {
		if (flag) {
			if (lef < d) {
				res += lef;
				lef = 0;
			} else {
				lef -= d;
				res += d;
			}
		} else {
			lef -= lef / 10;
		}
		flag = !flag;
	}
	return res;
}

int main() {
	cin >> n;
	long long l = 1, r = n;
	for (long long i = 500; ; i--) {
		r = n;
		ans = -1;
		for (long long mid; l <= r; ){
			mid = l + r >> 1;
			if (Check(mid) / mid <= i) {
				r = mid - 1;
				ans = mid;
			} else {
				l = mid + 1;
			}
		}
		if (ans == -1) {
			continue;
		} else {
			l = 1, r = n;
			_max = 0;
			long long _l = (1LL << 63) - 1, ms = 0;
			for (long long mid; l <= r; ){
				mid = l + r >> 1;
				long long res = Check(mid), _i = res / mid;
				if (_i <= i) {
					if(_i == i) {
						if(res >= (n + 1) / 2)
							r = mid - 1, ms = mid;
						else
							l = mid + 1;
					} else {
						r = mid - 1;
					}
				} else {
					l = mid + 1;
				}
			}
			if (ms > 0 && Check(ms) >= (n + 1) / 2) {
				cout << ms << endl;
				return 0;
			}
		}
	}
	return 0;
}

// By Sooke.