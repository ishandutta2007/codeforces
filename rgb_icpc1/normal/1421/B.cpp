#include<bits/stdc++.h>
#define N 205
using namespace std;

int n;
char s[N][N];
pair<int, int> ans[5];

int main() {
	int T;
	for (cin >> T; T --;) {
		cin >> n;
		for (int i = 0; i < n; i ++) cin >> s[i];
		int m;
		int a = s[0][1] - '0', b = s[1][0] - '0', c = s[n - 1][n - 2] - '0', d = s[n - 2][n - 1] - '0';
		if (a == b) {
			if (c == d) {
				if (a == c) {
					m = 2;
					ans[0] = {1, 2}, ans[1] = {2, 1};
				}
				else m = 0;
			}
			else {
				m = 1;
				if (c == a) ans[0] = {n, n - 1};
				else ans[0] = {n - 1, n};
			}
		}
		else {
			if (c == d) {
				m = 1;
				if (a == c) ans[0] = {1, 2};
				else ans[0] = {2, 1};
			}
			else {
				m = 2;
				if (a == 0) ans[0] = {1, 2};
				else ans[0] = {2, 1};
				if (c == 1) ans[1] = {n, n - 1};
				else ans[1] = {n - 1, n};
			}
		}
		cout << m << endl;
		for (int i = 0; i < m; i ++) {
			cout << ans[i].first << ' ' << ans[i].second << endl;
		}
	}
}