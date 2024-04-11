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

const int INF = 10000;

int n;
int tp[110];
int dp[110][3];

int main() {
    cin >> n;
    rep(i, n) cin >> tp[i];

    rep(i, n + 1) rep(j, 3) dp[i][j] = INF;

    dp[0][0] = 1;
    if (tp[0] & 1) dp[0][1] = 0;
    if (tp[0] >= 2) dp[0][2] = 0;

    for (int i = 1; i < n; ++i) {
	rep(j, 3) {
	    dp[i][0] = min(dp[i][0], dp[i - 1][j] + 1);
	}

	if (tp[i] & 1) {
	    rep(j, 3) if (j != 1) {
		dp[i][1] = min(dp[i][1], dp[i - 1][j]);
	    }
	}

	if (tp[i] >= 2) {
	    rep(j, 3) if (j != 2) {
		dp[i][2] = min(dp[i][2], dp[i - 1][j]);
	    }
	}
    }

    int ret = INF;
    rep(i, 3) ret = min(ret, dp[n - 1][i]);

    cout << ret << endl;

    return 0;
}