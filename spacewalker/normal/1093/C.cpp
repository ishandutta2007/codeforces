#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
	int n; scanf("%d", &n);
	vector<ll> arr;
	for (int i = 0; i < n/2; ++i) {
		ll ai; scanf("%lld", &ai);
		arr.push_back(ai);
	}
	if (n == 2) {
		printf("%d %lld\n", 0, arr[0]);
		return 0;
	}
	/*
	pdiffs maybe? let ai+1 - ai = d(i+1) with d0 = 0.
	so ai+1 = ai + d(i+1)
	now it suffices to let all di be nonnegative
	so the sum condition becomes like, 
	ai + a(n+1-i) = bi
	a(i-1) + di + a(n+2-i) - d(n+2-i) = bi (i >= 1)
	di - d(n+2-i) = bi - b(i-1)
	0 0 1 1 1 2
	0 0 1 0 0 1
	2 1 2
	0 _ _ _ _ 2

	5 6
	so a1 a2 a3 a4

	a2 + a3 = 6
	a1 + d2 + a4 - d4 = 6
	d2 - d4 = 1

	1 2 3 4 5 6 7 8 9 10
d   1 1 1 1 1 1 1 1 1 1
    a b b b b b b b b b
      a+b+diff[1]   a+(n-2)b+allSum-diff[n-1]
    a                 a+(n-1)b+allSum

    5 6
    a b+1 b b

	a a+b+1 a+2b+1 a+3b+1

	2a+3b+1 = 5

	

	2a+3b+1 = 5

      2a+(n-2)b + allSum + diff[1] - diff[n-1] = arr[1]
	2a+ (n-1)b + allSum = arr[0]
	b = arr[1] - arr[0] - diff[1] + diff[n-1]
	a = arr[0] - allSum - (n-1)*b
	*/
	vector<ll> ans(n);
	vector<ll> diff(n);
	diff[0] = 0;
	ll allSum = 0;
	// printf("HERE\n");
	for (int i = 1; i < n / 2; ++i) {
		// we try to find diff[i] and diff[n-i]
		// a[i] + a[n-1-i] = b[i]
		// a[i-1] + d[i] + a[n-i] - d[n-i] = b[i]
		// d[i] - d[n-i] = b[i] - b[i-1]
		// printf("att to find %d and %d\n", i, n - i + 1);
		// x + x + 1 = 5
		ll bSum = arr[i] - arr[i-1];
		if (bSum >= 0) {
			diff[i] = bSum;
			allSum += bSum;
			// printf("setting %d to %lld\n", i, bSum);
		} else {
			diff[n-i] = -bSum;
			allSum += -bSum;
			// printf("setting %d to %lld\n", n-i, -bSum);
			// 1 5 7 10 10 12
			// 13 15 17
			// 3 5 7 10 10 10
			// 
		}
	}
	diff[0] = 0;
	diff[n/2] = arr[0] - (allSum);
	// printf("ALLSUM %lld\n", allSum);
	ans[0] = diff[0];
	for (int i = 1; i < n; ++i) {
		ans[i] = ans[i-1] + diff[i];
		// printf("d %d = %lld\n", i, diff[i]);
	}
	for (ll x : ans) printf("%lld ", x);
	printf("\n");
	return 0;
}