#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> str(n);
	for (int i = 0; i < n; i ++)
		cin >> str[i];

	vector<vector<int> > a(n + 1, vector<int>(m + 1, 0)), s(n + 1, vector<int>(m + 1, 0));
	int ans = 0;
	for (int i = n - 1; i >= 0; i --) {
		for (int j = m - 1; j >= 0; j --) {
			a[i][j] = s[i+1][j] ^ s[i][j+1] ^ s[i+1][j+1] ^ (str[i][j] == 'B');
			if (a[i][j]) ans ++;
			s[i][j] = a[i][j] ^ s[i+1][j] ^ s[i][j+1] ^ s[i+1][j+1];
		}
	} 
	for (int i = 0; i + 1 < n; i ++)
		for (int j = 0; j + 1 < m; j ++) {
			if (a[i][j] && a[i][m-1] && a[n-1][j] && a[n-1][m-1]) {
				ans --;
				cout << ans << "\n";
				return 0;
			}
		}
	cout << ans << "\n";
}