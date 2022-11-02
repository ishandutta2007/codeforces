#include <bits/stdc++.h>
using namespace std;
#define N 111
#define M 10010

int n, m, lf[N][M], rf[N][M];
char s[M];

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i ++) {
		scanf("%s", s);
		if (!strstr(s, "1")) {
			puts("-1"); return 0;
		}

		if (s[0] == '1') lf[i][0] = 0;
		else {
			for (int j = m - 1; j >= 0; j --) {
				if (s[j] == '1') {
					lf[i][0] = j; break;
				}
			}
		}
		for (int j = 1; j < m; j ++) {
			if (s[j] == '1') lf[i][j] = j;
			else lf[i][j] = lf[i][j-1];
		}

		if (s[m-1] == '1') rf[i][m-1] = m - 1;
		else {
			for (int j = 0; j < m; j ++) {
				if (s[j] == '1') {
					rf[i][m-1] = j; break;
				}
			}
		}
		for (int j = m - 2; j >= 0; j --) {
			if (s[j] == '1') rf[i][j] = j;
			else rf[i][j] = rf[i][j+1];
		}
	}
	int ans = 1 << 30;
	for (int i = 0; i < m; i ++) {
        int rlt = 0;
        for (int j = 0; j < n; j ++) {
			rlt += min((i - lf[j][i] + m) % m, (rf[j][i] - i + m) % m);
        }
        ans = min(rlt, ans);
	}
	printf("%d\n", ans);
	return 0;
}