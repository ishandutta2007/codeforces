#include <bits/stdc++.h>
using namespace std;
#define M 2000010
const int MOD = 1e9 + 7;

int X1, Y1, X2, Y2, n, h, w, H, W, sx, sy, oo, ans;
__int64 row[M << 1], col[M << 1], f[M], g[M], m;

char s[M];

void get_pattern() {
	int x = M, y = M;
	X1 = x, Y1 = y;
	m = n;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R') x++; if (s[i] == 'U') y++; if (s[i] == 'D') y--; if (s[i] == 'L') x--;
		if (!col[x]) col[x] = i + 1; if (!row[y]) row[y] = i + 1;
		X1 = min(X1, x), Y1 = min(Y1, y), X2 = max(X2, x), Y2 = max(Y2, y);
	}
	H = Y2 - Y1 + 1, W = X2 - X1 + 1;
	if (x == M && y == M && H <= h && W <= w) {oo = 1; return;}
	int dx = x - M, dy = y - M;
	while (X2 - X1 < w && Y2 - Y1 < h) {
		int st, en;
		if (dx) {
			if (dx < 0) st = X1 + dx, en = X1; else st = X2, en = X2 + dx;
			for (int i = st; i <= en; i++) if (!col[i]) col[i] = col[i-dx] + n;
			if (dx < 0) X1 += dx; else X2 += dx;
		}
		if (dy) {
			if (dy < 0) st = Y1 + dy, en = Y1; else st = Y2, en = Y2 + dy;
			for (int i = st; i <= en; i++) if (!row[i]) row[i] = row[i-dy] + n;
			if (dy < 0) Y1 += dy; else Y2 += dy;
		}
		m += n;
	}
	for (int i = X1; i <= X2; i++) col[i-X1+1] = col[i];
	for (int i = Y1; i <= Y2; i++) row[i-Y1+1] = row[i];
	H = Y2 - Y1 + 1, W = X2 - X1 + 1;
	sx = M - X1 + 1, sy = M - Y1 + 1;
	col[0] = m; row[0] = m; col[W+1] = row[H+1] = m;
}

int main() {
//	freopen("F.in", "r", stdin);
    scanf("%d %d %d", &n, &h, &w);
    scanf("%s", s);
    get_pattern();
    if (oo) return puts("-1"), 0;
    __int64 v1, v2, x;
	for (int i = 1; i <= w; i++) {
        if (sx < i) v1 = m; else v1 = col[sx-i];
        if (W - sx <= w - i) v2 = m; else v2 = col[sx+w-i+1];
        f[i] = min(v1, v2);
	}
	sort(f + 1, f + w + 1);
	for (int i = 1; i <= w; i++) {g[i] = g[i-1] + f[i]; g[i] %= MOD;}
	for (int i = 1; i <= h; i++) {
		if (sy < i) v1 = m; else v1 = row[sy-i];
        if (H - sy <= h - i) v2 = m; else v2 = row[sy+h-i+1];
        x = min(v1, v2);
        int y = lower_bound(f + 1, f + w + 1, x) - f;
        ans = (0LL + ans + g[y-1] + (1LL * (w - y + 1) * x % MOD)) % MOD;
	}
	printf("%d\n", ans);
}