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

const int maxN = 60;
const int maxS = 510000;
const int inf = 1000000;
int n, a[maxN], d;
int dp[maxN][maxS];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < maxS; ++j) {
			if (dp[i][j]) {
				dp[i + 1][j] = true;
				dp[i + 1][j + a[i]] = true;
			}
		}
	}

	int moves = 0, value = 0;
	while (true) {
		int t = -1;
		for (int i = value + 1; i < maxS && i <= value + d; ++i) {
			if (dp[n][i]) {
				t = i;
			}
		}
		if (t == -1) {
			break;
		}
		++moves;
		value = t;
	}
	printf("%d %d\n", value, moves);


	return 0;
}