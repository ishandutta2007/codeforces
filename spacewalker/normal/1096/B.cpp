#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
constexpr ll MOD = 998244353;

char str[200010];

int main() {
	int n; scanf("%d", &n);
	scanf("%s", str);
	ll prefEqual = -1;
	for (int i = 0; i < n - 1; ++i) {
		if (str[i] != str[i+1]) {
			prefEqual = i;
			break;
		}
	}
	ll suffEqual = n;
	for (int i = n - 1; i > 0; --i) {
		if (str[i] != str[i-1]) {
			suffEqual = i;
			break;
		}
	}
	// printf("%lld %lld", prefEqual, suffEqual);
	if (str[0] == str[n-1]) {
		// same first character
		// valid deletions: from [0, prefEqual+1] to [suffEqual-1, n-1]
		printf("%lld\n", (prefEqual + 2) * (n-suffEqual+1) % MOD);
	} else {
		// different end chracters
		// valid deletions: either 0 to [suffEqual-1, n-1]
		// OR [0, prefEqual + 1] to n-1
		printf("%lld\n", ((n-suffEqual + 1)+(prefEqual + 2)-1) % MOD);
	}
	return 0;
}