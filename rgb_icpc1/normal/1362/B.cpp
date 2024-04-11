#include<bits/stdc++.h>

using namespace std;
int flg[1050], a[1050];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t, n;
	for (cin >> t; t --;) {
		cin >> n;
		memset(flg, 0, sizeof(flg));
		for (int i = 0; i < n ; i ++) cin >> a[i], flg[a[i]] = 1;
		int res = -1;
		for (int i = 1; i < 1024; i ++) {
			int ok = 0;
			for (int j = 0; j < n ; j ++) {
				if (flg[a[j]^i]) continue;
				ok = 1;
				break;
			}
			if (!ok) {
				res = i;
				break;
			}
		}
		cout << res << endl;
	}
	return 0;
}