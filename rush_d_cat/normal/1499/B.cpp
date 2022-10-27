#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100 + 10;

int main() {
	int t;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    while (t --) {
    	string s;
		cin >> s;
		int n = s.length();

		vector<int> a(n+1, 0);
		for (int i = 1; i <= n; i ++) 
			if (s[i-1] == '1') a[i] = 1;

		int dp[N][2][2] = {0};
		dp[0][0][0] = 1;
	
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < 2; j ++) for (int k = 0; k < 2; k ++) {
				if (dp[i][j][k]) {
					if (k == 0) {
						dp[i+1][j][1] = 1;
						if (!(j == 1 && a[i+1] == 0))
							dp[i+1][a[i+1]][0] = 1;
					} else {
						if (!(j == 1 && a[i+1] == 0))
							dp[i+1][a[i+1]][0] = 1;
					}
				}
			}
		}
		bool ok = 0;
		for (int j = 0; j < 2; j ++) for (int k = 0; k < 2; k ++) if (dp[n][j][k]) ok = 1;
		cout << (ok?"YES":"NO") << endl;
	}

}