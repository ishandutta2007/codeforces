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
#include <unordered_map>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int src, dst; };

int const MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-9;
ll INF = LLONG_MAX / 2;

vector<int> z_algorithm(string s) {
	int N = s.length();
	vector<int> a(N + 1); a[0] = N;
	int j = 0;
	for (int i = 1; i <= N;) {
		for (; i + j < N && s[i + j] == s[j]; j++);
		if (a[i] = j) {
			int k;
			for (k = 1; k + a[k] < a[i]; k++)
				a[i + k] = a[k];
			i += k; j -= k;
		}
		else i++;
	}
	return a;
}

int main() {
	string s, t;
	cin >> s >> t;
	int N = s.length(), M = t.length();
	vector<int> z = z_algorithm(t);
	vector<bool> match(N + 1);
	for (int l = 0; l + M <= N; l++) {
		match[l] = true;
		rep(j, M) if (s[l + j] != '?' && s[l + j] != t[j]) match[l] = false;
	}
	vector<vector<int> > dp(N + 1, vector<int>(M + 1));
	rep(i, N + 1) {
		rep(j, M + 1) {
			if (j + 1 <= M) dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
			int l = i - M + j;
			if (l >= 0 && z[j] == M - j && match[l])
				dp[l + M][1] = max(dp[l + M][1], dp[i][j] + 1);
		}
		if (i + 1 <= N) dp[i + 1][M] = max(dp[i + 1][M], dp[i][M]);
	}
	cout << dp[N][M] << endl;
}