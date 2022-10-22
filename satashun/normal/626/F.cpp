#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const ll MOD = 1000000007;

int n, m;
int dp[210][210][1010];
int a[210];

inline void add(int &x, int y)
{
	x += y;
	if (x >= MOD) x -= MOD;
}

int main() {
	cin >> n >> m;
	rep(i, n) cin >> a[i];
	sort(a, a + n);
	a[n] = 500;

	dp[0][0][0] = 1;

	rep(i, n) {
		for (int j = 0; j <= i; ++j) {
			for (int k = 0; k <= m; ++k) {
				//itself
				int nc = k + j * (a[i+1] - a[i]);

				if (nc <= m) {
					add(dp[i+1][j][nc], dp[i][j][k]);
				}

				//belong
				nc = k + j * (a[i+1] - a[i]);
				if (nc <= m) {
					add(dp[i+1][j][nc], (ll)dp[i][j][k] * j % MOD);
				}

				//open
				nc = k + (j + 1) * (a[i+1] - a[i]);
				if (nc <= m) {
					add(dp[i+1][j+1][nc], dp[i][j][k]);
				}

				//close
				nc = k + (j - 1) * (a[i+1] - a[i]);
				if (j && nc <= m) {
					add(dp[i+1][j-1][nc], (ll)dp[i][j][k] * j % MOD);
				}
			}
		}
	}

	int ret = 0;
	for (int k = 0; k <= m; ++k) {
		add(ret, dp[n][0][k]);
	}

	cout << ret << endl;

	return 0;
}