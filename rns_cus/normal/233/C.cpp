#include <bits/stdc++.h>
using namespace std;

const int n = 100;

int m, con[101][101];

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d", &m);
	for (int i = 1; i <= n; i ++) {
		int sum = 0;
		for (int j = 1; j < i && sum <= m; j ++) {
			m -= sum;
			sum ++;
			con[i][j] = con[j][i] = 1;
		}
	}
	printf("%d\n", n);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) printf("%d", con[i][j] ? 1 : 0); puts("");
	}
	return 0;
}