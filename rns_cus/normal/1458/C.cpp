#include <bits/stdc++.h>
using namespace std;

#define N 1010

int n, m, a[N][N], b[N][N];

struct num{
	int ty, x;
	num(int ty = 0, int x = 0) : ty(ty), x(x) {}
	int calc(int i, int j) {
		int rlt;
		if (ty == 0) rlt = i;
		else if (ty == 1) rlt = j;
		else rlt = b[i][j];
		rlt = (rlt + x) % n;
		if (rlt <= 0) rlt += n;
		return rlt;
	}
} O[3];
char s[100100];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i ++) for (int j = 1; j <= n; j ++) scanf("%d", &b[i][j]);
		for (int k = 0; k < 3; k ++) O[k] = num(k, 0);
		scanf("%s", s);
		for (int i = 0; i < m; i ++) {
			if (s[i] == 'R') O[1].x ++;
			else if (s[i] == 'L') O[1].x --;
			else if (s[i] == 'D') O[0].x ++;
			else if (s[i] == 'U') O[0].x --;
			else if (s[i] == 'I') swap(O[1], O[2]);
			else swap(O[0], O[2]);
		}

		for (int i = 1; i <= n; i ++) for (int j = 1; j <= n; j ++) {
			int x = O[0].calc(i, j), y = O[1].calc(i, j), z = O[2].calc(i, j);
			a[x][y] = z;
		}
		for (int i = 1; i <= n; i ++, puts("")) for (int j = 1; j <= n; j ++) printf("%d ", a[i][j]);
		puts("");
    }

    return 0;
}