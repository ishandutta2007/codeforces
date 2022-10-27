#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int T;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	while (T --) {
		int n;
		cin >> n;

		if (n % 2 == 1) {
			for (int i = 1; i <= n; i ++) {
				for (int j = i + 1; j <= n; j ++) {
					if (j-i <= (n-1)/2) cout << 1 << " ";
					else cout << -1 << " ";
				}
			}
			cout << endl;
		} else {
			int a[102][102] = {0};
			for (int i = 0; i < n; i ++) {
				for (int j = i + 1; j <= i + n/2-1; j ++) {
					a[i][(j%n+n)%n] = 1; a[(j%n+n)%n][i] = -1;
				}
			}
			for (int i = 0; i < n; i ++) {
				for (int j = i + 1; j < n; j ++) {
					cout << a[i][j] << " ";
				}
			}
			cout << endl;
		}

	}

}