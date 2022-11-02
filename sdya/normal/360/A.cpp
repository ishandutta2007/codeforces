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
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 5100;
const int inf = 500000000;
int n, m;
int a[maxN], b[maxN];
int t[maxN], l[maxN], r[maxN], d[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d%d", &t[i], &l[i], &r[i], &d[i]);
	}

	for (int i = 1; i <= n; ++i) {
		a[i] = inf;
	}
	for (int i = m - 1; i >= 0; --i) {
		if (t[i] == 1) {
			for (int j = l[i]; j <= r[i]; ++j) {
				a[j] -= d[i];
			}
		} else {
			int mx = -inf;
			for (int j = l[i]; j <= r[i]; ++j) {
				if (a[j] > d[i]) {
					a[j] = d[i];
				}
				mx = max(mx, a[j]);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		b[i] = a[i];
	}
	for (int i = 0; i < m; ++i) {
		if (t[i] == 1) {
			for (int j = l[i]; j <= r[i]; ++j) {
				b[j] += d[i];
			}
		} else {
			int mx = -inf;
			for (int j = l[i]; j <= r[i]; ++j) {
				mx = max(mx, b[j]);
			}
			if (mx != d[i]) {
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	for (int i = 1; i <= n; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}