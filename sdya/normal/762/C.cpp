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
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
char a[maxN], b[maxN];
int nt[26][maxN], pv[26][maxN];
int n, m;

int l[maxN], r[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%s", &a);
	scanf("%s", &b);

	n = strlen(a);
	m = strlen(b);

	for (int i = 0; i < 26; ++i) {
		nt[i][n] = n;
		for (int j = n - 1; j >= 0; --j) {
			if (a[j] == i + 'a') {
				nt[i][j] = j;
			} else {
				nt[i][j] = nt[i][j + 1];
			}
		}

		pv[i][0] = (a[0] == i + 'a' ? 0 : -1);
		for (int j = 1; j < n; ++j) {
			if (a[j] == i + 'a') {
				pv[i][j] = j;
			} else {
				pv[i][j] = pv[i][j - 1];
			}
		}
	}

	l[0] = -1;
	for (int i = 1; i <= m; ++i) {
		if (l[i - 1] == n) {
			l[i] = n;
			continue;
		} 
		l[i] = nt[b[i - 1] - 'a'][l[i - 1] + 1];
	}

	r[m] = n;
	for (int i = m - 1; i >= 0; --i) {
		if (r[i + 1] == -1 || r[i + 1] == 0) {
			r[i] = -1;
			continue;
		}
		r[i] = pv[b[i] - 'a'][r[i + 1] - 1];
	}

	int len = -1;
	int x = 0, y = 0;
	for (int i = m; i >= 0; --i) {
		int index = upper_bound(l, l + m + 1, r[i] - 1) - l - 1;
		if (r[i] != -1 && index >= 0 && index + (m - i) > len) {
			len = m - i + index;
			x = index;
			y = m - i;
		}
	}

	if (len == 0) {
		printf("-\n");
	} else {
		for (int i = 0; i < m; ++i) {
			if (i < x || i >= m - y) {
				printf("%c", b[i]);
			}
		}
		printf("\n");
	}

	return 0;
}