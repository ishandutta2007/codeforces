#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

vector<int> dp;
vector<vector<int>> a;
vector<int> sum;
vector<int> sz;

void relax(int& a, int b) {
	a = max(a, b);
}

int ans = 0;
int n, k;

void rec(int l, int r) {
	//cerr << l << " " << r << endl;
	if (l == r - 1) {
		int sum = 0;
		for (int i = 1; i <= min(k, sz[l]); i++) {
			sum += a[l][i - 1];
			relax(ans, sum + dp[k - i]);
		}
		return;
	}
	vector<int> dp_copy = dp;
	int mid = (l + r) / 2;
	for (int i = l; i < mid; i++) {
		for (int j = k - sz[i]; j >= 0; j--) {
			relax(dp[j + sz[i]], dp[j] + sum[i]);
		}
	}
	rec(mid, r);
	dp = dp_copy;
	for (int i = mid; i < r; i++) {
		for (int j = k - sz[i]; j >= 0; j--) {
			relax(dp[j + sz[i]], dp[j] + sum[i]);
		}
	}
	rec(l, mid);
	dp = dp_copy;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    a.resize(n);
    sum.resize(n);
    sz.resize(n);
    dp.resize(k + 1);
    for (int i = 0; i < n; i++) {
    	cin >> sz[i];
    	a[i].resize(sz[i]);
    	for (int j = 0; j < sz[i]; j++) {
    		cin >> a[i][j];
    		sum[i] += a[i][j];
    	}
    }
    rec(0, n);
    cout << ans << endl;
    return 0;
}