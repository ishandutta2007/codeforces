#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>
#include <ctime>
#include <unordered_set>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 510000;
int n, a, b, t;
char s[2 * maxN];

long long sum[2 * maxN];

int solve(int index) {
	for (int i = 0; i < n + n; ++i) {
		sum[i] = 1 + a;
		if (s[i] == 'w') {
			sum[i] += b;
		}
		if (i > 0) {
			sum[i] += sum[i - 1];
		}
	}

	int res = 0;
	long long needed = 0;
	for (int i = index; i >= index - n + 1; --i) {
		needed += 1;
		if (s[i] == 'w') {
			needed += b;
		}
		if (i < index) {
			needed += a;
		}

		if (needed <= (long long)(t)) {
			res = max(res, index - i + 1);
		}

		long long cur = needed + (long long)(index - i) * (long long)(a);

		if (cur > (long long)(t)) {
			continue;
		}

		long long rem = t - cur;

		int pos = upper_bound(sum, sum + n + n, rem + sum[index]) - sum;
		--pos;
		if (pos >= index) {
			res = max(res, pos - i + 1);
		}

	}
	return min(res, n);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d%d", &n, &a, &b, &t);
	scanf("%s", &s);
	for (int i = 0; i < n; ++i) {
		s[n + i] = s[i];
	}

	int res = solve(n);
	reverse(s, s + n + n);
	res = max(res, solve(n - 1));
	printf("%d\n", res);

	return 0;
}