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

const long long P = 1000000007;
const int maxN = 2100;
int n, k;
char s[maxN];
long long dp[maxN][maxN], sums[maxN][maxN];
long long c[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	scanf("%s", &s);

	dp[0][0] = 1;
	sums[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= k; ++j) {
			dp[i][j] = (sums[i - 1][j] * (long long)(s[i - 1] - 'a')) % P;
			for (int q = 0; q < i && (q + 1) * (n - i + 1) <= j; ++q) {
				dp[i][j] = (dp[i][j] + dp[i - q - 1][j - (q + 1) * (n - i + 1)] * (long long)('z' - s[i - 1])) % P;
			}
			sums[i][j] = (sums[i - 1][j] + dp[i][j]) % P;
		}
	}
	long long res = 0;
	for (int i = 0; i <= n; ++i) {
		res = (res + dp[i][k]) % P;
	}
	printf("%d\n", (int)(res));

	return 0;
}