#include <bits/stdc++.h>

using namespace std;



#define N 2525



char c[N<<1][N<<1];

int s[N<<1][N<<1];



int main() {

	//freopen("r.in", "r", stdin);

	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i ++) scanf("%s", c[i] + 1);

	for (int i = 1; i < N * 2; i ++) for (int j = 1; j < N * 2; j ++) {

		s[i][j] = s[i][j-1] + s[i-1][j] - s[i-1][j-1];

		if (c[i][j] == '1') s[i][j] ++;

	}

	int ans = n * m;

	for (int k = 2; k <= max(n, m); k ++) {

		int now = 0, tmp;

		for (int i = 0; i < n; i += k) for (int j = 0; j < m; j += k) {

			tmp = s[i+k][j+k] + s[i][j] - s[i][j+k] - s[i+k][j];

			now += min(tmp, k * k - tmp);

		}

		ans = min(ans, now);

	}

	printf("%d\n", ans);



	return 0;

}