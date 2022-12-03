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
#include <random>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

int INF = INT_MAX / 2;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int N, K; cin >> N >> K;
	vector<double> p(N);
	for (double& x: p) cin >> x;
	vector<double> dp(1<<N);
	dp[0] = 1;
	for (int S = 0; S < 1<<N; S++) {
		int cnt = 0;
		double sum = 0;
		for (int i = 0; i < N; i++)
			if (S>>i & 1) cnt++;
			else sum += p[i];
		if (cnt >= K || sum <= EPS) continue;
		for (int i = 0; i < N; i++)
			if (!(S>>i & 1))
				dp[S | 1<<i] += dp[S] * p[i] / sum;
		dp[S] = 0;
	}
	vector<double> ans(N);
	for (int S = 0; S < 1<<N; S++)
		for (int i = 0; i < N; i++)
			if (S>>i & 1)
				ans[i] += dp[S];
	for (int i = 0; i < N; i++)
		printf("%.15f ", ans[i]);
	cout << endl;
}