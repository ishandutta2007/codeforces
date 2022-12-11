#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
	int n; scanf("%d", &n);
	vector<ll> arr(2*n);
	for (int i = 0; i < 2*n; ++i) scanf("%lld", &arr[i]);
	sort(arr.begin(), arr.end());
	if (n == 1) {printf("0\n"); return 0;}
	ll ans = (arr[n-1] - arr[0]) * (arr[2*n-1] - arr[n]);
	for (int i = 1; i < n; ++i) {
		ans = min(ans, (arr[i + n - 1] - arr[i]) * (arr[2*n-1] - arr[0]));
	}
	printf("%lld\n", ans);
	return 0;
}