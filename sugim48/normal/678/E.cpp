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

int main() {
	int N; cin >> N;
	vector<vector<double> > p(N, vector<double>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> p[i][j];
	vector<vector<double> > dp(1<<N, vector<double>(N));
	dp[0][0] = 1;
	for (int S = 1; S < 1<<N; S++)
		for (int i = 0; i < N; i++) {
			if (S>>i & 1) continue;
			for (int j = 0; j < N; j++) {
				if (!(S>>j & 1)) continue;
				int _S = S - (1<<j);
				dp[S][i] = max(dp[S][i], dp[_S][i] * p[i][j] + dp[_S][j] * p[j][i]);
			}
		}
	double ma = 0;
	for (int i = 0; i < N; i++)
		ma = max(ma, dp[(1<<N) - 1 - (1<<i)][i]);
	printf("%.15f\n", ma);
}