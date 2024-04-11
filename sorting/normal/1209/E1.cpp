#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4;
const int MAXM = 107;
const int inf = 1e9;

int a[MAXN][MAXM];
pair<int, bool> dp[1 << 4][MAXM];
int n, m;

int score(int c, int state){
	if(c == m){
		if(state){
			return -inf;
		}
		return 0;
	}
	if(dp[state][c].second){
		return dp[state][c].first;
	}
	dp[state][c].second = true;

	int ans = -inf;
	for(int j = 0; j < (1 << n); ++j){
		if((j | state) > state){
			continue;
		}
		for(int i = 0; i < n; ++i){
			int curr = 0;
			for(int k = 0; k < n; ++k){
				if(j & (1 << k)){
					curr += a[(i + k) % n][c];
				} 
			}
			curr += score(c + 1, state ^ j);
			ans = max(ans, curr);
		}
	}

	dp[state][c].first = ans;
	return ans;
}

void solve(){
	cin >> n >> m;

	for(int i = 0; i < (1 << n); ++i){
		for(int j = 0; j < m; ++j){
			dp[i][j].second = false;
		}
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> a[i][j];
		}
	}

	cout << score(0, (1 << n) - 1) << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--){
		solve();
	}

	return 0;
}