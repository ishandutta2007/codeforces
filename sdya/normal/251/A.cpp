#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxN = 110000;
int n, d, a[maxN];

int main() {
	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	long long res = 0;
	for (int i = 0; i < n; ++i) {
		int index = upper_bound(a, a + n, a[i] + d) - a;
		long long length = index - i - 1;
		res += (length * (length - 1)) / 2LL;
	}
	cout << res << endl;
	return 0;
}