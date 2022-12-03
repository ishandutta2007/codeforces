#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
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
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;
double INF = FLT_MAX;

ll dp[2001][2001][2];

int main() {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	dp[n][0][0] = 1;
	for (int i = n; i >= 1; i--) {
		for (int j = i - 1; j >= 0; j--) {
			int win = 25 - (s[j] - 'a'), lose = s[j] - 'a';
			int dx = (i - j - 1) * (n - i);
			for (int x = 0; x + dx <= k; x++)
				dp[j][x + dx][0] = (dp[j][x + dx][0] + lose * dp[i][x][1]) % MOD;
			dx += n - j;
			for (int x = 0; x + dx <= k; x++)
				dp[j][x + dx][1] = (dp[j][x + dx][1] + win * dp[i][x][1]) % MOD;
			if (!j) {
				dx -= n - j;
				dx += n - i;
				for (int x = 0; x + dx <= k; x++)
					dp[j][x + dx][1] = (dp[j][x + dx][1] + dp[i][x][1]) % MOD;
			}
		}
		int win = 25 - (s[i - 1] - 'a'), lose = s[i - 1] - 'a' + 1;
		for (int x = 0; x <= k; x++)
			dp[i - 1][x][0] = (dp[i - 1][x][0] + lose * dp[i][x][0]) % MOD;
		for (int x = 0; x + n - i + 1 <= k; x++)
			dp[i - 1][x + n - i + 1][1] = (dp[i - 1][x + n - i + 1][1] + win * dp[i][x][0]) % MOD;
	}
	cout << (dp[0][k][0] + dp[0][k][1]) % MOD << endl;
}