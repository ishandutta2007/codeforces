#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <fstream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int v, w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

double dp[101][101][101];

int main() {
	for (int r = 0; r <= 100; r++)
		for (int s = 0; s <= 100; s++)
			for (int p = 0; p <= 100; p++) {
				int sum = r * s + s * p + p * r;
				if (!sum) {
					if (r) dp[r][s][p] = 1;
					continue;
				}
				if (r * s) dp[r][s][p] += dp[r][s - 1][p] * r * s / sum;
				if (s * p) dp[r][s][p] += dp[r][s][p - 1] * s * p / sum;
				if (p * r) dp[r][s][p] += dp[r - 1][s][p] * p * r / sum;
			}
	int r, s, p; cin >> r >> s >> p;
	printf("%.12f %.12f %.12f\n", dp[r][s][p], dp[s][p][r], dp[p][r][s]);
}