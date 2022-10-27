#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 500 + 10;
const ll mod = 998244353;

ll dp[N][N];
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> op(n + 1);
	for (int i = 1; i <= n; i ++) {
		string s; int x;
		cin >> s;
		if (s == "+") cin >> x; else x = 0;
		op[i] = x;
 	}

 	auto solve = [&](int pos) {
 		ll ans = 0;
 		memset(dp, 0, sizeof(dp));
 		dp[0][0] = 1;
 		int x = op[pos];
 		for (int i = 0; i < n; i ++) {
 			if (i + 1 == pos) {
 				for (int j = 0; j <= n; j ++) dp[i+1][j] = dp[i][j];
 				continue;
 			}
 			for (int j = 0; j <= i; j ++) {
 				if (op[i+1] == 0) {

 					// not take
 					(dp[i+1][j] += dp[i][j]) %= mod;
 					
 					// take
 					if (j >= 1) {
 						(dp[i+1][j-1] += dp[i][j]) %= mod;
 					} else if (i + 1 < pos) {
 						(dp[i+1][j] += dp[i][j]) %= mod;
 					}

 				} else {
 					if (op[i+1] < x || (op[i+1]==x && i+1<pos)) {
 						(dp[i+1][j] += dp[i][j]) %= mod;
 						(dp[i+1][j+1] += dp[i][j]) %= mod;
 					} else {
 						(dp[i+1][j] += dp[i][j]) %= mod;
 						(dp[i+1][j] += dp[i][j]) %= mod;
 					}
 				}
 			}
 		}
 		for (int i = 0; i <= n; i ++) (ans += dp[n][i]) %= mod;
 		ans = ans * x % mod;
 		return ans;
 	};

 	ll ans = 0;
 	for (int i = 1; i <= n; i ++) {
 		if (op[i] == 0) continue;
 		ans = (ans + solve(i)) % mod; 
 	}
 	cout << ans << endl;
}