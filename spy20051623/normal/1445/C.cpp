#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	long long t, p, q, i, x, maxm;
	cin >> t;
	while (t--) {
		cin >> p >> q;
		if (p % q != 0)
			cout << p << endl;
		else {
			maxm = 1;
			for (x = 1; x <= sqrt(q); ++x)
				if (q % x == 0) {
					if (x != 1)
						for (i = x; p % i == 0; i *= x)
							if (p / i % q != 0) {
								if (p / i > maxm)
									maxm = p / i;
								break;
							}
					for (i = q / x; p % i == 0; i *= q / x)
						if (p / i % q != 0) {
							if (p / i > maxm)
								maxm = p / i;
							break;
						}
				}
			if (p / q % q != 0 && p / q > maxm)
				maxm = p / q;
			cout << maxm << endl;
		}
	}
	return 0;
}