
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
#define int long long
// don't do this people = ))
const int N = (int) 1e6 + 6, mod = (int) 0;
int dp[N][2];
int32_t main() {
	ios_base::sync_with_stdio(0);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, a, b;	
		cin >> n >> a >> b;
		string s;
		cin >> s;
		s += '0';	
		for (int j = 0; j <= n; ++j) dp[j][0] = dp[j][1] = 1e18;
		dp[0][0] = b;
		for (int j = 1; j <= n; ++j) {
			for (int i = max(s[j - 1] - '0', s[j] - '0'); i <= 1; ++i) {
				for (int last = 0; last <= 1; ++last) {
					dp[j][i] = min(dp[j][i], dp[j - 1][last] + a + (last ^ i) * a + (i + 1) * b);	
				}
			}
		}
		cout << dp[n][0] << '\n';
		
	}
}