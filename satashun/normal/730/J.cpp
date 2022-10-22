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

inline void chmax(int &x, int y) { if (x <= y) x = y; }

int n;
int a[110], b[110];
int s;
int dp[2][110][10010];

int main() {
	scanf("%d", &n);
	rep(i, n) {
		scanf("%d", &a[i]);
		s += a[i];
	}
	rep(i, n) scanf("%d", &b[i]);
	
	memset(dp, -1, sizeof(dp));

	int c = 0, f = 1;
	dp[c][0][0] = 0;
	
	rep(i, n) {
		rep(j, 110) rep(k, 10010) dp[f][j][k] = -1;

		rep(j, 110) rep(k, 10010) if (dp[c][j][k] != -1) {
			chmax(dp[f][j+1][k + b[i]], dp[c][j][k] + a[i]);
			chmax(dp[f][j][k], dp[c][j][k]);
		}

		swap(c, f); 
	}

	for (int i = 1; i <= n; ++i) {
		int ans = -1;
		for (int j = s; j < 10010; ++j) {
			if (dp[c][i][j] != -1) {
				ans = max(ans, dp[c][i][j]);
			}
		}
		if (ans != -1) {
			printf("%d %d\n", i, s - ans);
			return 0;
		}
	}
}