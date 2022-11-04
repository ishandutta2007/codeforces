#include <bits/stdc++.h>
#define MX 2005
using namespace std;
int a[MX], sum[MX];
int main () {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int tc; cin >> tc;
	while (tc --) {
		int n; cin >> n;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
			sum[i] = sum[i - 1] + a[i];
		}
		int rlt = n;
		for (int i = 2; i <= n; i ++) {
			int st = i, ss = i - 1;
			int cur = a[i];
			int s = sum[i - 1];
			int cur_rlt = i - 1;
			int fg = 0;
			do{
				if (cur == s) {
					cur_rlt = max(cur_rlt, st - ss);
					ss = st;
					cur = a[++st];
					if (st > n) cur = 0;
				} else if (cur > s) {
					fg = 1;
					break;
				} else {
					cur += a[++st];
				}
			}while (st <= n);
			if (fg || cur) continue;
			rlt = min(rlt, cur_rlt);
		}
		cout << rlt << endl;
	}


	return 0;
}