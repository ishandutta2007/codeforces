#include <bits/stdc++.h>
using namespace std;
#define N 51

int n, m;
char s[N][N];

bool ok(int stx, int sty, int enx, int eny) {
	if (stx == enx && sty == eny) return 1;
	if (enx <= eny) {
        bool flag = 1;
        for (int j = sty; j <= eny; j ++) {
			if (s[stx][j] != 'B') {flag = 0; break;}
        }
        for (int i = stx; i <= enx; i ++) {
			if (s[i][eny] != 'B') {flag = 0; break;}
        }
        if (flag) return 1;
        flag = 1;
        for (int i = stx; i <= enx; i ++) {
			if (s[i][sty] != 'B') {flag = 0; break;}
        }
        for (int j = sty; j <= eny; j ++) {
			if (s[enx][j] != 'B') {flag = 0; break;}
        }
        if (flag) return 1;
        return 0;
	}
	else {
		bool flag = 1;
		for (int j = sty; j >= eny; j --) {
			if (s[stx][j] != 'B') {flag = 0; break;}
		}
		for (int i = stx; i <= enx; i ++) {
			if (s[i][eny] != 'B') {flag = 0; break;}
		}
		if (flag) return 1;
		flag = 1;
		for (int i = stx; i <= enx; i ++) {
			if (s[i][sty] != 'B') {flag = 0; break;}
		}
		for (int j = sty; j >= eny; j --) {
			if (s[enx][j] != 'B') {flag = 0; break;}
		}
		if (flag) return 1;
		return 0;
	}
}

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) if (s[i][j] == 'B') {
			for (int k = i; k <= n; k ++) {
				for (int l = 1; l <= m; l ++) if (s[k][l] == 'B') {
					if (!ok(i, j, k, l)) {
                        puts("NO"); return 0;
					}
				}
			}
		}
	}
	puts("YES");
	return 0;
}