#include <bits/stdc++.h>
using namespace std;
int a[505][505];

int main() {
//	freopen("in.txt", "r", stdin);
	int n, m, i, j;
	cin >> n >> m;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			cin >> a[i][j];
			if ((i + j) % 2 == 0)
				a[i][j] = 720720 + pow(a[i][j], 4);
			else
				a[i][j] = 720720;
		}
	}
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}