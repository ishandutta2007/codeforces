#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using db = double;
#define pb push_back
#define fir first
#define sec second

const int N = 53, M = 7011;
int f[N], s[N], p[N];

db dp[N][M];

const db eps = 1e-12;
int sgn(db a, db b = 0) {
	a -= b;
	return (a > eps) - (a < -eps);
}

int main() {
	ios :: sync_with_stdio(0);
	int n, r; cin >> n >> r;
	for(int i = 1; i <= n; i ++)
		cin >> f[i] >> s[i] >> p[i];
	
	db left = 0, right = 1e12;
	for(int _ = 0; _ < 100; _ ++) {
		db m = (left + right) / 2;
		for(int i = n; i >= 1; i --)
			for(int j = 0; j < M; j ++) {
				dp[i - 1][j] = 1e100;
				if(j >= s[i])
					dp[i - 1][j] = min(dp[i - 1][j], p[i] * min(dp[i][j - f[i]] + f[i], m + f[i]) / 100 + (100 - p[i]) * min(dp[i][j - s[i]] + s[i], m + s[i]) / 100);
				else if(j >= f[i]) {
					//if(i != n)
						dp[i - 1][j] = min(dp[i - 1][j], p[i] * min(dp[i][j - f[i]] + f[i], m + f[i]) / 100 + (100 - p[i]) * (m + s[i]) / 100);
				} else {
					//if(i != n)
						dp[i - 1][j] = min(dp[i - 1][j], p[i] * (m + f[i]) / 100 + (100 - p[i]) * (m + s[i]) / 100);
				}
			}
		//cout << m << ' ' << dp[0][r] << '\n';
		if(m > dp[0][r])
			right = m;
		else
			left = m;
	}

	cout << fixed << setprecision(12) << left << '\n';
	
	return 0;
}