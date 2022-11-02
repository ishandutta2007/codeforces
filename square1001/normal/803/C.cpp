#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
long long n, m;
int main() {
	scanf("%lld %lld", &n, &m);
	vector<long long> v;
	for (int i = 1; 1LL * i * i <= n; i++) {
		if (n % i == 0) {
			v.push_back(i);
			v.push_back(n / i);
		}
	}
	sort(v.begin(), v.end(), greater<long long>());
	bool f = false;
	for (long long i : v) {
		if (log10(m) * 2 + log10(i) >= 12.0 || 1LL * m * (m + 1) * i / 2 > n) continue;
		for (int j = 1; j < m; j++) printf("%lld ", i * j);
		printf("%lld\n", n - 1LL * i * m * (m - 1) / 2);
		f = true;
		break;
	}
	if (!f) puts("-1");
	return 0;
}