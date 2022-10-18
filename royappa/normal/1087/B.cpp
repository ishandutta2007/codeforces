#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

// is there an x such that a = x/k, b = x%k?
LL f(LL a, LL b, LL k) {
	if (b >= k) return -1LL;
	for (LL x = k*a; x < k*a+k; x++) {
		if (x%k == b) {
			return x;
		}
	}
	return -1LL;
}
int main()
{
	int n, k;
	cin >> n >> k;

	int minx = -1LL;
	for (int d = 1; d*d <= n; d++) {
		if (n%d != 0) continue;
		int a = d, b = n/d;  // a*b = n
		// is there an x such that a = x/k, b = x%k?
		int x = f(a, b, k);
		if (x != -1ll && (minx == -1LL || x < minx)) {
			minx = x;
		}
		// is there an x such that a = x%k, b = x%k?
		x = f(b, a, k);
		if (x != -1LL && (minx == -1LL || x < minx)) {
			minx = x;
		}
	}
	cout << minx << endl;
}