#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1250000 + 5;
int dp[25][MAXN];
int grid[2][25], mark[50];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, sum = 0;
	cin >> n;
	vector<int> A(2*n);
	for(int i = 0; i < 2*n; i++) {
		cin >> A[i];
		sum += A[i];
	}
	sort(A.rbegin(), A.rend());
	int rsum = (sum - A[2*n - 1] - A[2*n - 2])/2;
	int xsum = sum - A[2*n - 1] - A[2*n - 2];
	for(int i = 0; i <= rsum; i++)
		for(int k = 0; k < n; k++)
			dp[k][i] = -1;
	dp[0][0] = 0;
	int psum = 0;
	for(int i = 0; i < 2*n - 2; i++) {
		psum += A[i];
		for(int k = n - 1; k > 0; k--) {
			for(int s = min(psum, rsum); s >= A[i]; s--) {
				if(dp[k][s] != -1)
					continue;
				if(dp[k - 1][s - A[i]] != -1)
					dp[k][s] = i;
			}
		}
	}
	int ans = -1, bs;
	for(int s = 0; s <= rsum; s++) {
		if(dp[n - 1][s] != -1) {
			if(min(s, xsum - s) > ans) {
				ans = min(s, xsum - s);
				bs = s;
			}
		}
	}
	vector<int> upp, bot;
	int cs = bs, ck = n - 1;
	while(ck) {
		int i = dp[ck][cs];
		ck--;
		cs -= A[i];
		mark[i] = 1;
		upp.push_back(A[i]);
	}
	for(int i = 0; i < 2*n - 2; i++)
		if(!mark[i])
			bot.push_back(A[i]);
	sort(upp.begin(), upp.end());
	sort(bot.rbegin(), bot.rend());
	for(int i = 1; i < n; i++)
		grid[0][i] = upp[i - 1];
	for(int i = 0; i < n - 1; i++)
		grid[1][i] = bot[i];
	grid[0][0] = A[2*n - 2];
	grid[1][n - 1] = A[2*n - 1];
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < n; j++)
			cout << grid[i][j] << " ";
		cout << '\n';
	}
}