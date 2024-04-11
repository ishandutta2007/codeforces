#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int n, m, k;

bool ok(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    if (k % 2) {
        forn (i, n) {
            forn (j, m) {
                cout << "-1 ";
            }
            cout << "\n";
        }
        return 0;
    }
    k /= 2;
    vector<vector<int>> a(n, vector<int>(m - 1));
    vector<vector<int>> b(n - 1, vector<int>(m));
    forn (i, n) {
    	forn (j, m - 1) {
    		cin >> a[i][j];
    	}
    }
    forn (i, n - 1) {
    	forn (j, m) {
    		cin >> b[i][j];
    	}
    }
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1)));
    for (int l = 1; l <= k; l++) {
    	forn (i, n) {
    		forn (j, m) {
    			dp[i][j][l] = 2e18;
    			if (ok(i - 1, j)) {
    				dp[i][j][l] = min(dp[i][j][l], dp[i - 1][j][l - 1] + b[i - 1][j]);
    			}
    			if (ok(i + 1, j)) {
    				dp[i][j][l] = min(dp[i][j][l], dp[i + 1][j][l - 1] + b[i][j]);
    			}
    			if (ok(i, j - 1)) {
    				dp[i][j][l] = min(dp[i][j][l], dp[i][j - 1][l - 1] + a[i][j - 1]);
    			}
    			if (ok(i, j + 1)) {
    				dp[i][j][l] = min(dp[i][j][l], dp[i][j + 1][l - 1] + a[i][j]);
    			}
    		}
	    }
	}
	forn (i, n) {
		forn (j, m) {
			cout << dp[i][j][k] * 2 << " ";
		}
		cout << "\n";
	}
}