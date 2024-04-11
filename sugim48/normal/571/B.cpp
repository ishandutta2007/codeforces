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
struct edge { int u, v; ll w; };
 
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;
ll INF = LLONG_MAX / 10;
 
int main() {
	int n, k; cin >> n >> k;
	vector<int> A(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	sort(A.begin(), A.end());
	int x = n % k, y = k - x;
	vector<vector<ll> > dp(x + 1, vector<ll>(y + 1, INF));
	dp[0][0] = 0;
	for (int a = 0; a <= x; a++)
		for (int b = 0; b <= y; b++) {
			int l = a * (n / k + 1) + b * (n / k);
			if (a + 1 <= x) {
				int r = l + (n / k + 1);
				dp[a + 1][b] = min(dp[a + 1][b], dp[a][b] + A[r - 1] - A[l]);
			}
			if (b + 1 <= y) {
				int r = l + (n / k);
				dp[a][b + 1] = min(dp[a][b + 1], dp[a][b] + A[r - 1] - A[l]);
			}
		}
	cout << dp[x][y] << endl;
}