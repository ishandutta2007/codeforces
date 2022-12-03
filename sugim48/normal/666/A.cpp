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

int INF = INT_MAX / 2;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	string s; cin >> s;
	int N = s.length();
	vector<vector<bool> > dp(N + 1, vector<bool>(4));
	dp[N][0] = true;
	set<string> ans;
	for (int i = N; i >= 0; i--)
		for (int x = 0; x <= 3; x++) {
			if (!dp[i][x]) continue;
			for (int y = 2; y <= 3 && i - y >= 5; y++)
				if (s.substr(i, x) != s.substr(i - y, y)) {
					dp[i - y][y] = true;
					ans.insert(s.substr(i - y, y));
				}
		}
	cout << ans.size() << endl;
	for (string s: ans) cout << s << endl;
}