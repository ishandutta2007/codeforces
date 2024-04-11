#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		int n;
		cin >> n;
		int a[n][5];
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < 5; j ++)		
				cin >> a[i][j];

		bool res = false;
		for (int i = 0; i < 5; i ++)
			for (int j = i + 1; j < 5; j ++) {
				bool ok = true;
				int c1 = 0, c2 = 0;
				for (int x = 0; x < n; x ++) {
					if (a[x][i] == 0 && a[x][j] == 0) ok = false;
					if (a[x][i] == 0) c1 ++;
					if (a[x][j] == 0) c2 ++;
				}
				if (not (n % 2 == 0 && c1 <= n / 2 && c2 <= n / 2))
					ok = false;
				res |= ok;
			}
		cout << (res?"YES":"NO") << "\n";
	}
}