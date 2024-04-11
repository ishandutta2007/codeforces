#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int n, k;
int a[maxN];
bool used[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		if (used[i]) {
			continue;
		}
		++res;
		long long buf = (long long)(a[i]) * (long long)(k);
		if (buf > 1000000000LL) {
			continue;
		}

		int index = lower_bound(a + 1, a + n + 1, buf) - a;
		if (index <= n && a[index] == buf) {
			used[index] = true;
		}
	}

	printf("%d\n", res);

	return 0;
}