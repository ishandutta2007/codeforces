#include<iostream>
#include<algorithm>
using namespace std;
long long n, m, a[600000], c;
bool solve(long long p) {
	long long G = 0;
	for (int i = 0; i < n; i++) { G += max(0LL, p - a[i]); }
	if (G <= m)return true;
	return false;
}
bool solve2(long long p) {
	long long G = 0;
	for (int i = 0; i < n; i++) { G += max(0LL, a[i] - p); }
	if (G <= m)return true;
	return false;
}
int main() {
	cin >> n >> m; for (int i = 0; i < n; i++) { scanf("%lld", &a[i]); c += a[i]; }
	sort(a, a + n);
	long long L = -2000000000, R = 2000000000, M;
	while (true) {
		M = (L + R) / 2;
		bool p1 = solve(M), p2 = solve(M + 1);
		if (p1 == true && p2 == false) { break; }
		if (p1 == false)R = M;
		if (p2 == true)L = M;
	}
	long long L2 = -2000000000, R2 = 2000000000, M2;
	while (true) {
		M2 = (L2 + R2) / 2;
		bool p1 = solve2(M2 - 1), p2 = solve2(M2);
		if (p1 == false && p2 == true) { break; }
		if (p1 == true)R2 = M2;
		if (p2 == false)L2 = M2;
	}
	long long H = 1; if (c%n == 0)H = 0;
	cout << max(H, M2 - M) << endl;
	return 0;
}