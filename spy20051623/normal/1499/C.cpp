#include <bits/stdc++.h>
using namespace std;
int a[100005];

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, i, fir[2], cnt[2];
	long long sum, minm, tmp;
	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 0; i < n; ++i) {
			cin >> a[i];
		}
		minm = 1LL * (a[0] + a[1]) * n;
		tmp = 0;
		fir[0] = a[0];
		fir[1] = a[1];
		cnt[0] = cnt[1] = n;
		for (i = 2; i < n; ++i) {
			if (a[i] < fir[i % 2]) {
				tmp += fir[i % 2];
				fir[i % 2] = a[i];
			} else {
				tmp += a[i];
			}
			--cnt[i % 2];
			sum = 1LL * cnt[0] * fir[0] + 1LL * cnt[1] * fir[1] + tmp;
			minm = min(minm, sum);
		}
		cout << minm << endl;
	}
	return 0;
}