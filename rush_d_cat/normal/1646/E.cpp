#include <bits/stdc++.h>
using namespace std;

const int N = 1000000 + 10;
int t;
typedef long long ll;

bool f[N];
int mn[N];

int gcd(int x, int y) {
	return y==0?x:gcd(y,x%y);
}
bool vis[20000000 + 10];
int main() {
	for (int i = 0; i < N; i ++) mn[i] = 1e9;
	for (int i = 2; i < N; i ++) {
		if (f[i] == 1) continue;
		mn[i] = i;
		for (int j = 2 * i; j < N; j += i) {
			f[j] = 1; mn[j] = min(i, mn[j]);
		}
	}

	ios::sync_with_stdio(false);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	
	vector<int> dp(20, 0);
	int cnt = 0;
	for (int g = 1; g <= 19; g ++) {
		for (int i = 1; i <= m; i ++) {
			if (vis[i * g] == 0) {
				vis[i * g] = 1; cnt ++;
			}
		}
		dp[g] = cnt;
	}
	// for (int i = 1; i <= 19; i ++) cout << dp[i] << "\n";
	ll ans = 0;
	for (int i = 1; i <= n; i ++) {
		int cur = i;
		int sum = 0;
		while (cur > 1) {
			int div = mn[cur], tmp_cnt = 0;
			//printf("cut = %d, div = %d\n", cur, div);
			while (cur % div == 0) {
				cur /= div; tmp_cnt ++;
			}
			sum = gcd(sum, tmp_cnt);
		}
		//printf("%d %d\n", i, sum);
		if (sum == 1) {
			//printf("i = %d ", i);
			// i^j <= n, maxj
			ll prod = i, cnt = 0;
			while (prod <= n) {
				prod *= i, cnt += 1;
			}
			//printf("cnt = %lld\n", cnt);
			ans += dp[cnt];
		}
	}
	cout << ans + 1 << "\n";

}