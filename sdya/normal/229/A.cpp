#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110;
const int maxM = 11000;
char s[maxN][maxM];
int n, m;

vector < int > a[maxN];

int getDist(int i, int j) {
	if (i > j) {
		swap(i, j);
	}
	return min(j - i, i + m - j);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", &s[i]);
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == '1') {
				a[i].push_back(j);
			}
		}
	}

	int res = 1000000000;
	for (int i = 0; i < m; ++i) {
		int current = 0;
		for (int j = 0; j < n; ++j) {
			if (a[j].size() == 0) {
				current = res;
				break;
			}

			int buf = 1000000000;
			buf = min(buf, getDist(i, a[j][0]));
			buf = min(buf, getDist(i, a[j].back()));
			int index = lower_bound(a[j].begin(), a[j].end(), i) - a[j].begin();
			for (int k = index - 3; k <= index + 3; ++k) {
				if (k >= 0 && k < a[j].size()) {
					buf = min(buf, getDist(i, a[j][k]));
				}
			}
			current += buf;
		}
		res = min(res, current);
	}
	if (res == 1000000000) {
		res = -1;
	}
	printf("%d\n", res);

	return 0;
}