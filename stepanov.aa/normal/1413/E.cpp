#include <iostream>
#include <cmath>
#include <algorithm>


using namespace std;

long long a, b, c, d;


long long get_dam(long long i) {
	long long res = a * (i + 1);
	long long k = 0; // max((long long)(0), i - ((c + 1) / d));
	res -= (i - k + 1) * (i - k) * b * d / 2;
	return res;
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c >> d;
		if (b * c < a) {
			cout << -1 << "\n";
			continue;
		}
		const long long r_beg = ((c + 1) / d) + 1;
		long long l = -1;
		long long r = r_beg;
		while (l + 2 < r) {
			long long t1 = (2 * l + r) / 3;
			long long t2 = (l + 2 * r) / 3;
			if (get_dam(t1) < get_dam(t2)) {
				l = t1;
			}
			else {
				r = t2;
			}
		}
		long long res = max({ get_dam(l), get_dam(l + 1), get_dam(r)});
		cout << res << "\n";
	}

	return 0;
}

/*
1
1 1 1 1
*/