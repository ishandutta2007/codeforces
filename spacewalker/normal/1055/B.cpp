#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
	int n, m, l; scanf("%d %d %d", &n, &m, &l);
	vector<ll> arr(n);
	for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
	int segments = 0;
	for (int i = 0; i < n; ++i) {
		if ((i == 0 || arr[i-1] <= l) && arr[i] > l) ++segments;
	}
	for (int q = 0; q < m; ++q) {
		int t; scanf("%d", &t);
		if (t == 0) printf("%d\n", segments);
		else {
			int p, d; scanf("%d %d", &p, &d); if (arr[--p] > l) continue;  arr[p] += d;
			// printf("%lld %lld %lld", arr[p-1], arr[p], arr[p+1]);
			if (arr[p] > l && p > 0 && p < n - 1 && (arr[p-1] > l) && arr[p+1] > l) --segments;
			else if (arr[p] > l && (p == 0 ? true : arr[p-1] <= l) && (p == n-1 ? true : arr[p+1] <= l))  ++segments;
		}
	}
	return 0;
}