#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	if (N% 2 == 1) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		int ans[N+1];
		int cur = N;
		while (cur > 0) {
			int po = 1;
			while (po <= cur) po*=2;
			po /= 2;
			int mi = cur;
			for (int i = 1; i <= cur; i++) {
				if (po + i -1 > cur) break;
				ans[po-i] = po+i-1;
				ans[po+i-1] = po-i;
				mi = min(mi, po-i);
			}
			cur = mi-1;
		}
		for (int i = 1; i <= N; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	if (N <= 5) {
		cout << "NO" << endl;
	}
	else {
		if (N == 6) {
			cout << "YES" << endl;
			cout << "3 6 2 5 1 4" << endl;
		}
		else {
			int po = 1;
			while (po <= N) po*=2;
			po /= 2;
			if (po == N) {
				cout << "NO" << endl;
			}
			else {
				cout << "YES" << endl;
				int ans[N+1];
				ans[1] = 7;
				ans[2] = 3;
				ans[3] = 6;
				ans[4] = 5;
				ans[5] = 1;
				ans[6] = 2;
				ans[7] = 4;
				int prevpow = 8;
				for (int i = 8; i <= N; i++) {
					if (i == prevpow*2-1 || i == N) {
						ans[i] = prevpow;
						prevpow*=2;
					}
					else {
						ans[i] = i+1;
					}
				}
				for (int i = 1; i <= N; i++) {
					cout << ans[i] << " ";
				}
				cout << endl;
			}
		}
	}
	cin >> N;
}