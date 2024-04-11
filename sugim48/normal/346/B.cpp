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
int INF = INT_MAX / 10;

void unko(string& s, string t) {
	if (s == "unko" || s.length() < t.length())
		s = t;
}

int main() {
	string s1, s2, v; cin >> s1 >> s2 >> v;
	int n = v.length();
	vector<vector<int> > a(n, vector<int>(26));
	for (int l = 0; l < n; l++)
		for (int k = 0; k < 26; k++) {
			string s = v.substr(0, l) + string(1, 'A' + k);
			for (int _l = 0; _l <= l + 1; _l++)
				if (s.substr(l + 1 - _l, _l) == v.substr(0, _l))
					a[l][k] = _l;
		}
	int n1 = s1.length(), n2 = s2.length();
	vector<vector<vector<string> > > dp(n1 + 1, vector<vector<string> >(n2 + 1, vector<string>(n, "unko")));
	dp[0][0][0] = "";
	for (int i = 0; i <= n1; i++)
		for (int j = 0; j <= n2; j++)
			for (int l = 0; l < n; l++) {
				if (dp[i][j][l] == "unko") continue;
				if (i + 1 <= n1) unko(dp[i + 1][j][l], dp[i][j][l]);
				if (j + 1 <= n2) unko(dp[i][j + 1][l], dp[i][j][l]);
				if (i + 1 <= n1 && j + 1 <= n2 && s1[i] == s2[j]) {
					int k = s1[i] - 'A', _l = a[l][k];
					if (_l < n) unko(dp[i + 1][j + 1][_l], dp[i][j][l] + string(1, 'A' + k));
				}
			}
	string ans = "unko";
	for (int l = 0; l < n; l++)
		if (dp[n1][n2][l] != "unko")
			unko(ans, dp[n1][n2][l]);
	if (ans == "unko" || ans == "")
		cout << 0 << endl;
	else
		cout << ans << endl;
}