#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>

using namespace std;

const int maxN = 4100;

int p[maxN][maxN];
int n, k;
int t[maxN], d[maxN];
int res = 0;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &t[i], &d[i]);
	p[0][0] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= k; ++j) {
			p[i][j] = max(p[i - 1][j] + 1, t[i]) + d[i] - 1;
			res = max(res, t[i] - p[i - 1][j] - 1);
			if (j > 0)
				p[i][j] = min(p[i][j], p[i - 1][j - 1]);
		}

	for (int j = 0; j <= k; ++j)
		res = max(res, 86400 - p[n][j]);
	printf("%d\n", res);

	return 0;
}