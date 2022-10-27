#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 16;
const int inf = 1e9;

char s[N][2]; 
int n, r[N], b[N];
int f[1<<N][200];
void upd(int & x, int y) {
	x = max(x, y);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i ++) {
		scanf("%s%d%d",s[i],&r[i],&b[i]);
	}

	for (int i = 0; i < 1<<N; i ++) for (int j = 0; j < 200; j ++)
		f[i][j] = - inf;
	
	f[0][0] = 0;
	for (int i = 0; i < 1<<n; i ++) {

		int R = 0, B = 0;
		for (int j = 0; j < n; j ++) {
			if (i>>j&1) {
				if (s[j][0] == 'R') ++ R; else ++ B;
			}
		}

		for (int j = 0; j < 200; j ++) {
			if (f[i][j] < 0) continue;
			// printf("# %d %d = %d\n", i, j, f[i][j]);
			for (int k = 0; k < n; k ++) {
				if (!(i >> k & 1)) {
					int score_r = min(R, r[k]);
					int score_b = min(B, b[k]);

					upd(f[i|(1<<k)][j + score_r], f[i][j] + score_b);
				}
			}
		}
	}

	int sum_r = 0, sum_b = 0;
	for (int i = 0; i < n; i ++) {
		sum_r += r[i]; sum_b += b[i];
	}

	int all = (1<<n) - 1, ans = 1e9;
	for (int i = 0; i < 200; i ++) {
		if (f[all][i] >= 0) {
			ans = min(ans, max(sum_r - i, sum_b - f[all][i]));
		}
	}
	cout << ans + n << endl;
}