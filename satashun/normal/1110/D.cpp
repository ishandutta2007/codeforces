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
#define dump(x) cout << #x << " = " << (x) << endl

const int MX = 1000100;
const int inf = -1e9;

int num[MX];
int dp[MX][3][3];

int main() {
	int n, m; scanf("%d %d", &n, &m);
	rep(i, n) {
		int x; scanf("%d", &x);
		++num[x];
	}

	rep(i, MX) {
		rep(j, 3) {
			rep(k, 3) {
				dp[i][j][k] = inf;
			}
		}
	}
	dp[0][0][0] = 0;

	for (int i = 1; i <= m; ++i) {
		rep(j, 3) {
			rep(k, 3) {
				if (dp[i-1][j][k] == inf) continue;
				int zan[3] = {num[i] - j - k, num[i+1] - k, num[i+2]};

				rep(t, 3) {
					if (zan[0] >= t && zan[1] >= t && zan[2] >= t) {
						dp[i][k][t] = max(dp[i][k][t], dp[i-1][j][k] + (num[i] - j - k - t) / 3 + t);
					}
				}
			}
		}
	}

	int ans = 0;
	rep(j, 3) rep(k, 3) ans = max(ans, dp[m][j][k]);
	cout << ans << endl;
	return 0;
}