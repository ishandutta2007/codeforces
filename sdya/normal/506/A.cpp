#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <string>
#include <queue>
#include <bitset>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 31000;
const int maxD = 600;
int n, l;
int cnt[maxN];
int d[maxN][maxD];

int calc(int pos, int step) {
	if (pos > 30000) {
		return 0;
	}
	if (d[pos][maxD / 2 + (l - step)] != -1) {
		return d[pos][maxD / 2 + l - step];
	}

	int res = cnt[pos];
	if (step - 1 > 0) {
		res = max(res, cnt[pos] + calc(pos + step - 1, step - 1));
	}
	res = max(res, cnt[pos] + calc(pos + step, step));
	res = max(res, cnt[pos] + calc(pos + step + 1, step + 1));
	return d[pos][maxD / 2 + l - step] = res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	memset(d, -1, sizeof(d));
	scanf("%d%d", &n, &l);
	for (int i = 1; i <= n; ++i) {
		int p;
		scanf("%d", &p);
		++cnt[p];
	}

	int res = calc(l, l);
	printf("%d\n", res);

	return 0;
}