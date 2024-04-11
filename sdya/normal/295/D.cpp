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

const int maxN = 2100;
const int P = 1000000007;

int c[3 * maxN][3 * maxN];

int cnk(int n, int k) {
	if (n < 0 || k < 0 || k > n) {
		return 0;
	}
	return c[n][k];
}

int waysS[maxN][maxN], ways[maxN][maxN];
int n, m;

void precalc() {
	for (int len = 2; len <= m; ++len) {
		for (int steps = 0; steps <= n; ++steps) {
			{
				waysS[len][steps] = 2 * cnk(2 * steps + len - 3, 2 * steps) - cnk(2 * steps + len - 4, 2 * steps);
				while (waysS[len][steps] >= P) {
					waysS[len][steps] -= P;
				}
				while (waysS[len][steps] < 0) {
					waysS[len][steps] += P;
				}
				if (steps == 0) {
					waysS[len][0] = 1;
				}
				if (steps > 0) {
					waysS[len][steps] += waysS[len][steps - 1];
					if (waysS[len][steps] >= P) {
						waysS[len][steps] -= P;
					}
				}
			}
			{
				ways[len][steps] = cnk(2 * steps + len - 2, 2 * steps);
				if (steps > 0) {
					ways[len][steps] += ways[len][steps - 1];
					if (ways[len][steps] >= P) {
						ways[len][steps] -= P;
					}
				}
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 0; i < 3 * maxN; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			if (c[i][j] >= P) {
				c[i][j] -= P;
			}
		}
	}
	cin >> n >> m;
	precalc();

	long long res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int len = 2; len <= m; ++len) {
			long long A = waysS[len][i - 1];
			long long B = ways[len][n - i];
			res += ((A * B) % (long long)(P)) * (long long)(m - len + 1);
			res %= P;
		}
	}

	printf("%I64d\n", res);

	return 0;
}