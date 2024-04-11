#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 2100;

int n, k;
string s[maxN];

int d[maxN][maxN];
int ans[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int l = 0; l < s[i].size() && l < s[j].size(); ++l) {
				if (s[i][l] == s[j][l]) d[i][j] = l + 1; else break;
			}
		}
	}

	int res = 0;
	for (int i = 0; i < (1 << n); ++i) {
		int bits = 0;
		for (int j = 0; j < n; ++j)
			if (i & (1 << j)) ++bits;

		int score = 0;
		for (int j = 0; j < n; ++j)
			if (i & (1 << j))
				for (int l = j + 1; l < n; ++l)
					if (i & (1 << l))
						score += d[j][l];

		/*if (bits > 1) {
			for (int j = 0; j < n; ++j)
				if (i & (1 << j)) {
					ans[i] = ans[i - (1 << j)];
					for (int l = j + 1; l < n; ++l)
						if (i & (1 << l)) ans[i] += d[j][l];
					break;
				}
		}*/

		if (bits == k) {
			res = max(res, score);
		}
	}
	printf("%d\n", res);

	return 0;
}