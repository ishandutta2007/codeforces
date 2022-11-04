#include <bits/stdc++.h>

using namespace std;

const int NN = 1010;
long long mn[NN][NN], sum[NN], a[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
#endif
	int n; cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		if((i & 1) == 0) a[i] = - a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	for(int i = 1; i <= n; i ++) {
		long long k = 0;
		for(int j = i; j <= n; j ++) {
			k += a[j];
			mn[i][j] = k;
			if(j > i) mn[i][j] = min(mn[i][j - 1], k);
		}
	}
	long long ans = 0;
	for(int i = 1; i <= n; i += 2) {
		for(int j = i + 1; j <= n; j += 2) {
			if(j == i + 1) {
				ans += min(a[i], - a[j]);
			}
			else {
				long long tmp = sum[j - 1] - sum[i];
				if(a[i] >= - mn[i + 1][j - 1] && - a[j] >= tmp - mn[i + 1][j - 1]) {
					ans += 1 + min(a[i] + mn[i + 1][j - 1], - a[j] - (tmp - mn[i + 1][j - 1]));
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}