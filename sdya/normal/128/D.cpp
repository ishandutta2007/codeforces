#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int n, a[maxN];
int cnt[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = n - 1; i >= 0; --i) {
		a[i] -= a[0];
	}

	for (int i = 1; i < n; ++i) {
		if (a[i] > a[i - 1] + 1) {
			printf("NO\n");
			return 0;
		}
	}

	for (int i = 0; i < n; ++i) {
		++cnt[a[i]];
	}

	for (int i = n; i > 1; --i) {
		if (cnt[i] == 0) {
			continue;
		}
		if (cnt[i] >= cnt[i - 1]) {
			printf("NO\n");
			return 0;
		}
		cnt[i - 2] += cnt[i];
		cnt[i] = 0;
	}

	if (cnt[0] == cnt[1]) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}

	return 0;
}