#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 7;
const int inf = 1e9;

string s[MAXN];
vector<vector<int> > dp, dp2;
int n, m;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 0; i < n; ++i){
		cin >> s[i];
	}

	for(int i = 0; i < n; ++i){
		dp.push_back(vector<int>());
		for(int j = 0; j < m; ++j){
			dp[i].push_back(0);
		}
	}
	dp2 = dp;

	for(int i = n - 1;i >= 0; --i){
		for(int j = m - 1; j >= 0; --j){
			if(i == 0 && j == 0){
				break;
			}
			if(i == n - 1 && j == m - 1){
				dp[i][j] = inf;
				continue;
			}
			if(s[i][j] == '#'){
				dp[i][j] = 0;
				continue;
			}
			if(i < n - 1){
				dp[i][j] += dp[i + 1][j];
			}
			if(j < m - 1){
				dp[i][j] += dp[i][j + 1];
			}

			dp[i][j] = min(dp[i][j], 1);
		}
	}

	for(int i = 0;i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(i == n - 1 && j ==  m - 1){
				break;
			}
			if(i == 0 && j == 0){
				dp2[i][j] = inf;
				continue;
			}
			if(s[i][j] == '#'){
				dp2[i][j] = 0;
				continue;
			}
			if(i > 0){
				dp2[i][j] += dp2[i - 1][j];
			}
			if(j > 0){
				dp2[i][j] += dp2[i][j - 1];
			}

			dp2[i][j] = min(dp2[i][j], 1);
		}
	}

	int ans = 0;

	if(n > 1){
		ans += dp[1][0];
	}
	if(m > 1){
		ans += dp[0][1];
	}

	if(ans == 2){
		for(int sum = 1; sum < n - 1 + m - 1; ++sum){
			int curr = 0;
			for(int j = max(0, sum - m + 1); j <= min(sum, n - 1); ++j){
				if(dp[j][sum - j] && dp2[j][sum - j]){
					++curr;
				}
			}
			if(curr == 1){
				cout << "1\n";

				return 0;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}