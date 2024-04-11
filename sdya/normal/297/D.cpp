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

const int maxN = 2100;
int n, m, k;
char s[maxN][maxN];
int len[maxN];
int a[maxN][maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < 2 * n - 1; ++i) {
		scanf("%s", &s[i]);
		len[i] = strlen(s[i]);
	}

	if (k == 1) {
		int good = 0, total = 0;
		for (int i = 0; i < 2 * n - 1; ++i) {
			good += count(s[i], s[i] + len[i], 'E');
			total += len[i];
		}
		if (good * 4 >= 3 * total) {
			printf("YES\n");
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					printf("%d ", 1);
				}
				printf("\n");
			}
			return 0;
		}
		printf("NO\n");
		return 0;
	}


	if (n <= m) {
		for (int i = 0; i < n; ++i) {
			a[i][0] = 1;
			for (int j = 1; j < m; ++j) {
				if (s[2 * i][j - 1] == 'E') {
					a[i][j] = a[i][j - 1];
				} else {
					a[i][j] = 3 - a[i][j - 1];
				}
			}

			if (i > 0) {
				int good = 0;
				for (int j = 0; j < m; ++j) {
					if (a[i][j] == a[i - 1][j]) {
						good += (s[2 * i - 1][j] == 'E');
					} else {
						good += (s[2 * i - 1][j] == 'N');
					}
				}
				if (good < m - good) {
					for (int j = 0; j < m; ++j) {
						a[i][j] = 3 - a[i][j];
					}
				}
			}
		}
	} else {
		for (int j = 0; j < m; ++j) {
			a[0][j] = 1;
			for (int i = 1; i < n; ++i) {
				if (s[2 * i - 1][j] == 'E') {
					a[i][j] = a[i - 1][j];
				} else {
					a[i][j] = 3 - a[i - 1][j];
				}
			}

			if (j > 0) {
				int good = 0;
				for (int i = 0; i < n; ++i) {
					if (a[i][j] == a[i][j - 1]) {
						good += (s[2 * i][j - 1] == 'E');
					} else {
						good += (s[2 * i][j - 1] == 'N');
					}
				}
				if (good < n - good) {
					for (int i = 0; i < n; ++i) {
						a[i][j] = 3 - a[i][j];
					}
				}
			}
		}
	}

	printf("YES\n");
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}


	return 0;
}