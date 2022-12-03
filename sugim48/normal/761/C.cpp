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

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

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
int INF = INT_MAX / 10;
double EPS = 1e-10;

int main() {
	int N, M; cin >> N >> M;
	vector<int> dp(1<<3, INF);
	dp[0] = 0;
	while (N--) {
		string s; cin >> s;
		vector<int> a(3, INF);
		rep(i, M) {
			char c = s[i];
			int k;
			if ('0'<=c && c<='9') k = 0;
			if ('a'<=c && c<='z') k = 1;
			if (c=='#' || c=='*' || c=='&') k = 2;
			a[k] = min(a[k], min(i, M - i));
		}
		vector<int> _dp(1<<3, INF);
		rep(S, 1<<3) rep(k, 3) {
			int _S = S | 1<<k;
			_dp[_S] = min(_dp[_S], dp[S] + a[k]);
		}
		dp = _dp;
	}
	cout << dp.back() << endl;
}