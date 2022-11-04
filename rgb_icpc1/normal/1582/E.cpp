#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
const int mx = 100005;
const LL inf = 100000000000000007LL;
int n, a[mx];
LL sum[mx], _dp[mx], dp[mx];
bool can(int k) {
	int s = 0;
	for (int i = 0; i <= n; i++) _dp[i] = 0;
	for (int i = k; i >= 1; i--) {
		for (int j = 0; j <= n; j++) dp[j] = inf;
		s += i;
		for (int j = s; j <= n; j++) {
			LL S = sum[j] - sum[j - i];
			if (_dp[j - i] < S) dp[j] = S;
		}
		_dp[0] = dp[0];
		for (int j = 1; j <= n; j++) _dp[j] = min(_dp[j - 1], dp[j]);
	}
	if(_dp[n] < inf) return 1;
	return 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int Tc;
	for (cin >> Tc; Tc--; ) {
		cin >> n;
		sum[0] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			sum[i] = sum[i - 1] + a[i];
		}
		int st = 1, en, md;
		for (en = 1; en * (en + 1) / 2 <= n; en++);
		while (en - st > 1) {
			md = (st + en) / 2;
			if (can(md)) st = md;
			else en = md;
		}
		if (can(en)) cout << en << endl;
		else cout << st << endl;
	}
	return 0;
}