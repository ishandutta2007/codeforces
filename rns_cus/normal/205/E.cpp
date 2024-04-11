#include <bits/stdc++.h>
using namespace std;
#define N 200200
#define M 27

int n, a[M][N], cnt[M];
char txt[N];
double s[M][N], ans;

int main() {
//	freopen("e.in", "r", stdin);
	scanf("%d", &n);
	scanf("%s", txt + 1);
	for (int i = 1; i <= n; i ++) {
		int x = txt[i] - 'A';
		a[x][cnt[x]++] = i;
	}
	for (int i = 0; i < 26; i ++) if (cnt[i]) {
		s[i][0] = a[i][0];
		for (int j = 1; j < cnt[i]; j ++) s[i][j] = s[i][j-1] + a[i][j];
	}
	scanf("%s", txt + 1);
	for (int i = 1; i <= n; i ++) {
		int x = txt[i] - 'A';
		if (!cnt[x]) continue;
		int k = lower_bound(a[x], a[x] + cnt[x], i) - a[x];
		if (k) {
            ans += 1.0 * s[x][k-1] * (n - i + 1);
		}
		if (k < cnt[x]) {
			double y = 1.0 * (n + 1) * (cnt[x] - k) - s[x][cnt[x]-1];
			if (k) y += s[x][k-1];
			ans += 1.0 * i * y;
		}
	}
	ans = ans / n / (n + 1) / (2 * n + 1) * 6;
	printf("%.12lf\n", ans);
	return 0;
}