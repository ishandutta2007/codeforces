#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	if (n == 1 && m == 1) {
		cout << "YES" << endl;
		cout << 1 << endl;
	}
	else if (n == 1) {
		if (m <= 3) {
			cout << "NO" << endl;
		}
		else if (m == 4) {
			cout << "YES" << endl;
			cout << "2 4 1 3" << endl;
		}
		else {
			cout << "YES" << endl;
			for (int i = 1; i <= m; i+=2) {
				cout << i << " ";
			}
			for (int i = 2; i <= m; i+=2) {
				cout << i << " ";
			}
			cout << endl;
		}
	}
	else if (m == 1) {
		if (n < 4) {
			cout << "NO" << endl;
		}
		else if (n == 4) {
			cout << "YES" << endl;
			cout << 2 << endl;
			cout << 4 << endl;
			cout << 1 << endl;
			cout << 3 << endl;
		}
		else {
			cout << "YES" << endl;
			for (int i = 1; i <= n; i+=2) {
				cout << i << endl;
			}

			for (int i = 2; i <= n; i+=2) {
				cout << i << endl;
			}
			// cout << endl;
		}
		
	}
	else if (n == 2) {
		if (m <= 3) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
			int ans[n][m];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					ans[i][j] = i*m + j+1;
				}
			}
			int tmp1 = ans[1][0];
			int tmp2 = ans[1][1];
			for (int i = 0; i < m-2; i++) {
				ans[1][i] = ans[1][i+2];
			}
			ans[1][m-2] = tmp1;
			ans[1][m-1] = tmp2;
			
			for (int i = 1; i < m; i += 2) {
				int tmp = ans[0][i];
				ans[0][i] = ans[1][i];
				ans[1][i] = tmp;
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << ans[i][j] << " ";
				}
				cout << endl;
			}
		}
	}
	else if (m == 2) {
		if (n <= 3) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
			int ans[n][m];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					ans[i][j] = i*m + j+1;
				}
			}
			int tmp1 = ans[0][1];
			int tmp2 = ans[1][1];
			for (int i = 0; i < n-2; i++) {
				ans[i][1] = ans[i+2][1];
			}
			ans[n-2][1] = tmp1;
			ans[n-1][1] = tmp2;

			for (int i = 1; i < n; i += 2) {
				int tmp = ans[i][0];
				ans[i][0] = ans[i][1];
				ans[i][1] = tmp;
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << ans[i][j] << " ";
				}
				cout << endl;
			}
		}
	}
	else if (n == 3 && m == 3) {
		cout << "YES" << endl;
		cout << "8 3 4" << endl;
		cout << "1 5 9" << endl;
		cout << "6 7 2" << endl;
	} 
	else if (n == 3) {
		cout << "YES" << endl;
		int ans[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ans[i][j] = i*m+j+1;
			}
		}

		for (int i = 1; i < n; i+=2) {
			int tmp = ans[i][0];
			for (int j = 0; j < m-1; j++) {
				ans[i][j] = ans[i][j+1];
			}
			ans[i][m-1] = tmp;
		}
		for (int i = 1; i < n; i+=2) {
			int tmp = ans[i][0];
			for (int j = 0; j < m-1; j++) {
				ans[i][j] = ans[i][j+1];
			}
			ans[i][m-1] = tmp;
		}

		for (int i = 1; i < m; i+=2) {
			int tmp = ans[0][i];
			for (int j = 0; j < n-1; j++) {
				ans[j][i] = ans[j+1][i];
			}
			ans[n-1][i] = tmp;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << ans[i][j] << " ";
			}
			cout << endl;
		}
	}
	else {
		cout << "YES" << endl;
		int ans[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ans[i][j] = i*m+j+1;
			}
		}
		for (int i = 1; i < n; i+=2) {
			int tmp = ans[i][0];
			for (int j = 0; j < m-1; j++) {
				ans[i][j] = ans[i][j+1];
			}
			ans[i][m-1] = tmp;
		}
		// for (int i = 0; i < n; i++) {
		// 	for (int j = 0; j < m; j++) {
		// 		cout << ans[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;
		for (int i = 1; i < m; i+=2) {
			int tmp1 = ans[0][i];
			int tmp2 = ans[1][i];
			for (int j = 0; j < n-2; j++) {
				ans[j][i] = ans[j+2][i];
			}
			ans[n-2][i] = tmp1;
			ans[n-1][i] = tmp2;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << ans[i][j] << " ";
			}
			cout << endl;
		}
	}
	cin >> n;
}