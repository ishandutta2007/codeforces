///	D : Coded by Choe Kwang

#include <bits/stdc++.h>
using namespace std;
#define N 333

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct star {
	int x, y;
} p[N*N];

bool cmp(star A, star B) {
	return A.x != B.x ? A.x < B.x : A.y < B.y;
}

int n, m, num, cnt;
int a[N][N], gas[N], ss[N];
char s[N];

int main() {
//	freopen("d.in", "r", stdin);
//	freopen("d.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &num);
	for (int i = 1; i <= n; i ++) {
		scanf("%s", s);
		for (int j = 1; j <= m; j ++) a[i][j] = s[j-1] == '*' ? 1 : 0;
	}
	int mx = min(n - 1 >> 1, m - 1 >> 1);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) if (a[i][j]) {
			for (int k = 1; k <= mx; k ++) {
				if (i - k >= 1 && i + k <= n && j - k >= 1 && j + k <= m &&
						a[i-k][j] && a[i+k][j] && a[i][j-k] && a[i][j+k]) {
					gas[k] ++;
				}
			}
		}
	}
	for (int i = 1; i <= mx; i ++) ss[i] = ss[i-1] + gas[i];
	if (num > ss[mx]) {
		puts("-1"); return 0;
	}
	int k = lower_bound(ss + 1, ss + mx + 1, num) - ss;
	num -= ss[k-1];
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) if (a[i][j]) {
			if (i - k >= 1 && i + k <= n && j - k >= 1 && j + k <= m &&
					a[i-k][j] && a[i+k][j] && a[i][j-k] && a[i][j+k]) {
				p[++cnt].x = i;
				p[cnt].y = j;
			}
		}
	}
	sort(p + 1, p + cnt + 1, cmp);
	int x = p[num].x, y = p[num].y, r = k;
	printf("%d %d\n", x, y);
	for (int k = 0; k < 4; k ++) {
		printf("%d %d\n", x + r * dx[k], y + r * dy[k]);
	}
	return 0;
}