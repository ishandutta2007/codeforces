#include <bits/stdc++.h>
using namespace std;

int n;
long long c[555][555];

int main() {
//	freopen("g.in", "r", stdin);
	c[0][0] = 1;
	for (int i = 1; i <= 505; i ++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j ++) c[i][j] = c[i-1][j-1] + c[i-1][j];
	}
	cin >> n;
	cout << c[n+2][3] * c[n+4][5] << endl;
	return 0;
}