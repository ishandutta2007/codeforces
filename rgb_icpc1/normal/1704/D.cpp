#include <bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define endl '\n'

#define NX 1000005
typedef long long LL;

vector <LL> dp[NX];
LL dif[NX];
LL pos[NX], neg[NX];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	LL tc;
	cin >> tc;
	while (tc --) {
		LL n, m;
		cin >> n >> m;
		for (LL i = 0; i < n; i ++) {
			dp[i].clear();
			dp[i].resize(m);
			for (LL j = 0; j < m; j ++) cin >> dp[i][j];
		}
		for (LL i = 0; i < n; i ++) {
			for (LL j = 0; j < m; j ++) 
				dif[j] = dp[i][j] - dp[(i + 1) % n][j];
			pos[i] = neg[i] = 0;
//			for (LL j = 0; j < m; j ++) cout << dif[j] << ' '; cout << endl;
			for (LL j = 0; j < m; j ++) {
				if (dif[j] > 0) pos[i] += dif[j], dif[j + 1] += dif[j];
				if (dif[j] < 0) neg[i] += dif[j], dif[j + 1] += dif[j];
			}
		}
		LL c = -1, rlt = 0;
		for (LL i = 0; i < n; i ++) {
			if (neg[(n + i - 1) % n] + pos[(n + i - 1) % n] != 0 && neg[(n + i) % n] + pos[(n + i) % n] != 0) {
				c = i;
				rlt = abs(pos[(i - 1 + n) % n] + neg[(i - 1 + n) % n]);
				break;
			}
		}
		cout << c + 1 << ' ' << rlt << endl;
	}
	return 0;
}