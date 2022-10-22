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

int n, q;
double dp[10010][1010];
int ans[1010];

int main() {
	scanf("%d%d", &n, &q);

	dp[0][0] = 1.0;

	int now = 0;

	for (int i = 0; i <= 10000; ++i) {
		for (int j = 0; j < n; ++j) {
			dp[i+1][j+1] += dp[i][j] * (n-j) / n;
			dp[i+1][j] += dp[i][j] * j / n;
		}
		dp[i+1][n] += dp[i][n];

		bool ok = 0;

		while (now < 1010 && dp[i][n] > ((double)now-(1e-7))/2000) {
			ans[now++] = i;
		}

		if (dp[i][n] > 0.5) {
			ok = 1;
		}

		if (ok) {
			//cout << i << endl;
			break;
		}
	}


	while (q--) {
		int p;
		scanf("%d", &p);
		printf("%d\n", ans[p]);
	}

	return 0;
}