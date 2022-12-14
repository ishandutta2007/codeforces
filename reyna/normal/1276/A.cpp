
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;

const int N = (int) 1e6 + 6, mod = (int) 0;
int dp[N][3][3], par[N][3][3];
string s = "one", t = "two";
int main() {
	ios_base::sync_with_stdio(0);
	int tc;
	cin >> tc;
	while (tc--) {
		string inp;
		cin >> inp;
		int n = (int) inp.size();
		for (int j = 0; j <= n + 1; ++j)
			for (int a = 0; a < 3; ++a)
				for (int b = 0; b < 3; ++b)
					dp[j][a][b] = 0, par[j][a][b] = -1;
		dp[0][0][0] = 0;
		for (int j = 0; j < n; ++j) {
			for (int a = 0; a < 3; ++a) {
				for (int b = 0; b < 3; ++b) {
					dp[j + 1][a][b] = max(dp[j + 1][a][b], dp[j][a][b]);
					if (dp[j + 1][a][b] == dp[j][a][b])
						par[j + 1][a][b] = a * 3 + b;
					int na, nb;
					if (s[a] == inp[j]) na = a + 1;
					else if (s[0] == inp[j]) na = 1;
					else na = 0;
					if (t[b] == inp[j]) nb = b + 1;
					else if (t[0] == inp[j]) nb = 1;
					else nb = 0;
					if (na == 3 || nb == 3) continue;
					dp[j + 1][na][nb] = max(dp[j + 1][na][nb], dp[j][a][b] + 1);
					if (dp[j + 1][na][nb] == dp[j][a][b] + 1)
						par[j + 1][na][nb] = a * 3 + b;
				}
			}
		}
		int res = 0;
		for (int a = 0; a < 3; ++a)
			for (int b = 0; b < 3; ++b)
				res = max(res, dp[n][a][b]);
		cout << n - res << '\n';
		int flag = 0;
		for (int a = 0; a < 3 && !flag; ++a) {
			for (int b = 0; b < 3 && !flag; ++b) {
				if (res == dp[n][a][b]) {
					vector<int> all;
					int cur = n;
					int ca = a, cb = b;
					while (cur > 0) {
						int pa = par[cur][ca][cb] / 3;
						int pb = par[cur][ca][cb] % 3;
						if (dp[cur - 1][pa][pb] == dp[cur][ca][cb]) {
							cout << cur << ' ';
						}
						ca = pa;
						cb = pb;
						--cur;
					}
					flag = 1;
				}
			}
		}
		cout << '\n';
	}
}