#include <bits/stdc++.h>

using namespace std;
#define maxn 10010

const int inf = 1000000000;
int dp[maxn]; //space saving version


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, l, r;
	cin >> n >> l >> r;
	int a[n];
	int b[n];
	int H = 0;
	for (int i = 0; i < n; i++) {
		cin >>a[i];
		H += a[i];
	}

	int tl = l;
	l = H-r; //will be lower of the two converted ones
	r = H-tl; //will be higher
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	vector<int> good;
	vector<int> bad;
	for (int i = 0; i < n; i++) {
		if (b[i] == 1) {
			good.push_back(a[i]);
		}
		else {
			bad.push_back(a[i]);
		}
	}
	sort(good.begin(), good.end());
	reverse(good.begin(), good.end());
	sort(bad.begin(), bad.end());
	fill(dp, dp+maxn, -inf);
	dp[0] = 0;
	for (int i = 0; i < bad.size(); i++) {
		for (int j = H; j >= bad[i]; j--) {
			dp[j] = max(dp[j], dp[j-bad[i]]);
		}
	}
	for (int i = 0; i < good.size(); i++) {
		int cur = good[i];
		for (int j = H; j >= cur; j--) { //consider adding me to this stack
			if (j >= l && j <= r) { //look at top of this
				dp[j] = max(dp[j], dp[j-cur]+1);
			}
			else {
				dp[j] = max(dp[j], dp[j-cur]);
			}
		}

	}
	int ans = 0;
	for (int i = 0; i <= H; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	cin >> n;

}