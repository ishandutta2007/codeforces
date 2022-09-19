#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)

vector<long long> a;

long long f(long long n) {
	return max(0ll, n);
}

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	forn (n, 10) {
		forn (i, 1 << n) {
			int x = 0;
			for (int j = n - 1; j >= 0; j--) {
				x *= 10;
				if (i & (1 << j)) {
					x += 7;
				} else {
					x += 4;
				}
			}
			a.push_back(x);
		}
	}
	a.push_back(1000000010);
	long long pl, pr, vl, vr, k;
	cin >> pl >> pr >> vl >> vr >> k;
	long long s = 0;
	forn (i1, a.size() - k - 1) {
		int i = i1 + 1;
		int j = i + k - 1;
		s += f(min(a[i], pr) - max(a[i - 1] + 1, pl) + 1) * f(min(a[j + 1] - 1, vr) - max(a[j], vl) + 1);
		s += f(min(a[i], vr) - max(a[i - 1] + 1, vl) + 1) * f(min(a[j + 1] - 1, pr) - max(a[j], pl) + 1);
		if (k == 1 && a[i] >= pl && a[i] <= pr && a[i] >= vl && a[i] <= vr) {
			s--;
		}
	}
	printf("%0.20lf", (double)s / ((pr - pl + 1) * (vr - vl + 1)));
}