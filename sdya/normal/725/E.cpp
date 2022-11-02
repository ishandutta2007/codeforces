#define _CRT_SECURE_NO_WARNINGS
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

const int maxN = 210000;
int c, n, a[maxN], d[maxN];

int cnt[maxN], pos[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &c, &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		++cnt[a[i]];
	}
	sort(a, a + n);
	reverse(a, a + n);

	d[n] = 1;
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] > d[i + 1]) {
			d[i] = d[i + 1];
		} else {
			d[i] = d[i + 1] + a[i];
		}
	}

	for (int i = 0; i < n; ++i) {
		pos[a[i]] = i;
	}

	int res = c + 1;
	int index = 0;
	int badres = c + 1;

	for (int i = c - 1; i >= 1; --i) {
		while (index < n && a[index] >= i) {
			if (a[index] <= c) {
				c -= a[index];
				--cnt[a[index]];
			}
			++index;
		}
		if (c <= 1) {
			break;
		}

		if (i >= c) {
			continue;
		}

		int j = index;
		if (d[j] > c - i) {
			continue;
		}
		if (d[j] == c - i) {
			res = min(res, i);
			continue;
		}

		int s = c - i;
		while (s && j < n) {
			int l = j, r = n - 1;
			while (r - l > 1) {
				int m = (l + r) / 2;
				if (a[m] > s) {
					l = m;
				} else {
					r = m;
				}
			}
			int start = -1;
			if (a[l] <= s) {
				start = l;
			} else if (a[r] <= s) {
				start = r;
			}
			if (start == -1) {
				break;
			}

			int w = cnt[a[start]];

			int needed = (s / a[start]);

			int rem = min(needed, w);
			s -= rem * a[start];
			j = pos[a[start]] + 1;
		}
		if (s != 0) {
			res = min(res, i);
		}
	}

	if (res == badres) {
		printf("Greed is good\n");
	} else {
		printf("%d\n", res);
	}


	return 0;
}