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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxL = 205000000;
char s[maxL];

const int maxN = 5100;
int a[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		for (int j = 0; j <= k; ++j) {
			int value = a[i] * j;
			if (s[value] == 0) {
				s[value] = j;
			} else {
				s[value] = min(s[value], (char)(j));
			}
		}
	}
	int q;
	scanf("%d", &q);
	for (int t = 0; t < q; ++t) {
		int w;
		scanf("%d", &w);
		int res = 100;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= k; ++j) {
				int needed = w - a[i] * j;
				if (needed < 0) {
					continue;
				}
				if (needed == 0) {
					res = min(res, j);
					continue;
				}
				if (s[needed] == 0) {
					continue;
				}
				res = min(res, j + (int)(s[needed]));
			}
		}
		if (res > k) {
			res = -1;
		}
		printf("%d\n", res);
	}

	return 0;
}