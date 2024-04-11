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

const long long P = 1000000007LL;
const int maxN = 210;
const int maxK = 2100;
int n, k, a[maxN];

long long dp[2][maxN][maxK];

void set0(long long dp[maxN][maxK]) {
	for (int i = 0; i < maxN; ++i) {
		for (int j = 0; j < maxK; ++j) {
			dp[i][j] = 0;
		}
	}
}

void add(long long &x, long long value) {
	x = (x + value) % P;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);

	int u = 0, v = 1;
	dp[u][0][0] = 1;
	for (int step = 0; step < n; ++step, swap(u, v)) {
		set0(dp[v]);
		for (int g = 0; g <= step; ++g) {
			for (int balance = 0; balance < maxK; ++balance) {
				if (dp[u][g][balance] == 0) {
					continue;
				}
				int diff = a[step] - (step == 0 ? 0 : a[step - 1]);
				if (balance + g * diff < maxK) {
					add(dp[v][g][balance + g * diff], dp[u][g][balance] * (long long)(g));
					add(dp[v][g + 1][balance + g * diff], dp[u][g][balance]);
				}
			}
		}

		for (int g = 1; g <= step + 1; ++g) {
			for (int balance = 0; balance < maxK; ++balance) {
				if (dp[v][g][balance] == 0) {
					continue;
				}
				add(dp[v][g - 1][balance], dp[v][g][balance]);
			}
		}
	}
	long long res = 0;
	for (int i = 0; i <= k; ++i) {
		res = (res + dp[u][0][i]) % P;
	}
	cout << res << endl;

	return 0;
}