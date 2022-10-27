#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <assert.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 102;
const int mod = 1e9 + 7;
int dp[N][N*102];
 
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> c(n),b(n-1);
	for (int i = 0; i < n; i ++) cin >> c[i];
	for (int i = 0; i < n - 1; i ++) cin >> b[i];
	int q;
	cin >> q;
	vector<int> x(q);
	for (int i = 0; i < q; i ++) cin >> x[i];
	
	int xmin=1e9, xmax=1e9;
	vector<int> bb(n);
	bb[0] = 0; 
	for (int i = 1; i < n; i ++) bb[i] = bb[i-1] + b[i-1];
	for (int i = 1; i < n; i ++) bb[i] += bb[i-1];
	int s = 0;
	for (int i = 0; i < n; i ++) {
		s += c[i];
		xmin = min(xmin, - bb[i] / (i+1));
		xmax = min(xmax, (s - bb[i]) / (i+1));
	}
	xmin -= 5; xmax += 5;
	//printf("xmin=%d,xmax=%d\n", xmin,xmax);
	assert(xmax-xmin<200);
	int res[500]; memset(res,-1,sizeof(res));
	bool has = 0; ll xmin_ans = 0;
	for (auto tmp: x) {
		tmp = min(tmp, xmax);
		tmp = max(tmp, xmin);
		int o = tmp;
		if (res[o - xmin] != -1) {
			cout << res[o - xmin] << endl; continue;
		}
		int sum = 0;
		vector<int> limit(n);
		memset(dp,0,sizeof(dp));
		dp[0][0] = 1;
		for (int i = 0; i < n - 1; i ++) {
			sum += tmp;
			limit[i] = sum;
			tmp += b[i];
		}
		sum += tmp;
		limit[n-1] = sum;
		//cout << "sum = " << sum << endl;
		int tot = 0;
		int pre[10000 + 2] = {0}; 
		for (int i = 1; i <= n; i ++) {
			tot += c[i-1];
			pre[0] = dp[i-1][0];
			for (int j = 1; j <= tot; j ++) pre[j] = (pre[j-1] + dp[i-1][j]) % mod;
			for (int j = max(limit[i-1], 0); j <= tot; j ++) {
				dp[i][j] = (pre[j] - ((j-c[i-1]-1)>=0?pre[j-c[i-1]-1]:0) + mod) % mod;
			}
		}
		ll ans= 0;
		for (int i = max(sum, 0); i <= tot; i ++) ans = (ans + dp[n][i]) % mod;
		cout << ans << endl; res[o - xmin] = ans;
	}
}