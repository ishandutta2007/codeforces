#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
long long solve(int A, int B, int C, int D) {
	long long ans = 0;
	for (int i = C; i <= D; ++i) {
		// A <= x <= B
		// B <= y <= C
		// x + y > i
		long long ra = B - A + 1;
		long long rb = C - B + 1;
		long long d = i - (A + B) + 1;
		if (ra < rb) swap(ra, rb);
		// 0 <= x < ra
		// 0 <= y < rb (ra >= rb is assured)
		// x + y >= d (i.e. excludes x + y < d)
		long long sub = ra * rb;
		d = max(d, 0LL);
		if (0 <= d && d <= rb) {
			sub -= 1LL * d * (d + 1) / 2;
		}
		else if (d <= ra) {
			sub -= 1LL * (d - rb) * rb + 1LL * rb * (rb + 1) / 2;
		}
		else if (d <= ra + rb) {
			int s = ra + rb;
			sub = 1LL * (s - d) * (s - d - 1) / 2;
		}
		else {
			sub = 0;
		}
		ans += sub;
	}
	return ans;
}
int solve2(int A, int B, int C, int D) {
	int ans = 0;
	for (int i = A; i <= B; ++i) {
		for (int j = B; j <= C; ++j) {
			for (int k = C; k <= D; ++k) {
				if (i + j > k) ++ans;
			}
		}
	}
	return ans;
}
int main() {
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	long long res = solve(A, B, C, D);
	cout << res << endl;
	return 0;
}