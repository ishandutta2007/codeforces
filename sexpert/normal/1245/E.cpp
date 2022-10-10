#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
 
const double INF = 1e5;
double dp[2][105];
int grid[10][10];
vector<ii> ord;
map<ii, int> pos;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
 
	int cur = 0;
	for(int i = 0; i < 10; i++) {
		if(i % 2 == 0)
			for(int j = 0; j < 10; j++) {
				pos[{i, j}] = cur++;
				ord.push_back({i, j});
			}
		else
			for(int j = 9; j >= 0; j--) {
				pos[{i, j}] = cur++;
				ord.push_back({i, j});
			}
	}
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			cin >> grid[i][j];
	dp[1][0] = INF;
	for(int i = 1; i <= 5; i++) {
		double res = 0;
		for(int j = 0; j < i; j++)
			res += dp[0][j];
		res += 6.0;
		res /= (double)i;
		dp[0][i] = res;
		dp[1][i] = INF;
	}
	for(int i = 6; i <= 99; i++) {
		double res = 0;
		for(int j = i - 6; j < i; j++)
			res += min(dp[0][j], dp[1][j]);
		res /= 6.0;
		dp[0][i] = res + 1.0;
		auto p = ord[i];
		if(grid[p.first][p.second] == 0)
			dp[1][i] = INF;
		else {
			int r = p.first - grid[p.first][p.second], c = p.second;
			int x = pos[{r, c}];
			dp[1][i] = dp[0][x];
		}
	}
	cout << fixed << setprecision(10) << dp[0][99] << endl;
}