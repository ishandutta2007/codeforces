#include <bits/stdc++.h>

using namespace std;
#define maxn 105

const int inf = 1234567890;

bool ok[maxn][2];
int dp[maxn][4]; //0 is both empty, 1 is top, 2 is bot, 
int cond[maxn];
//3 is both

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string top, bot;
	cin >> top >> bot;
	int n = top.length();
	for (int i = 0; i < n; i++) {
		if (top[i] == 'X') {
			ok[i][0] = false;
		}
		else ok[i][0] = true;
	}
	for (int i = 0; i < n; i++) {
		if (bot[i] == 'X') {
			ok[i][1] = false;

		}
		else ok[i][1]= true;
	}
	for (int i = 0; i < n; i++) {
		if (!ok[i][0]) cond[i] += 1;
		if (!ok[i][1]) cond[i] += 2;
	}
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		dp[0][i] = -inf;
	}
	dp[0][cond[0]] = 0;
	for (int i = 1; i < n; i++) {
		int myc = cond[i];
		for (int j = 0; j < 4; j++) {
			dp[i][j] = -inf;
		}
		for (int j = 0; j < 4; j++) {
			dp[i][cond[i]] = max(dp[i][cond[i]], dp[i-1][j]);
		}
		
		//try adding all 4 pieces
		if ( (myc & 1) == 0) {
			//no top guy
			dp[i][myc+1] = max(dp[i][myc+1], dp[i-1][0]+1);
			
		}
		if ( (myc & 2) == 0) {
			dp[i][myc+2] = max(dp[i][myc+2], dp[i-1][0]+1);
		}


		if (myc == 0) {
			dp[i][myc+3] = max(dp[i][myc+3], dp[i-1][0]+1);
			dp[i][myc+3] = max(dp[i][myc+3], dp[i-1][2]+1);
			dp[i][myc+3] = max(dp[i][myc+3], dp[i-1][1]+1);
		}


		for (int j = 0; j < 4; j++) {
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
	cin >> ans;

}