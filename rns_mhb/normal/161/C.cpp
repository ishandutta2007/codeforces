#include <bits/stdc++.h>
using namespace std;
void chkmax(int &a, int b) {if (a < b) a = b;}

int func(int l, int r, int a) {
	return r / a - (l - 1) / a;
}

int get(int l, int a) {
    return ((l - 1) / a + 1) * a;
}

void get_r(int s, int f, int c, int r, int &a, int &b) {
    r = 1 << (r - 1);
    a = max(s, c - r + 1); b = min(f, c + r - 1);
    r <<= 1;
    a %= r, b %= r;
    return;
}

int s[2], f[2], g[2], l[2][2], r[2][2], ans;

int main() {
	scanf("%d %d %d %d", &s[0], &f[0], &s[1], &f[1]);
    int x, y;
    for (int pw = 1, qw = 2, ii = 1; ii <= 30; pw <<= 1, qw <<= 1, ii ++) {
        for (int i = 0; i < 2; i ++) g[i] = func(s[i], f[i], pw) - func(s[i], f[i], qw);
        cerr << g[0] << " " << g[1] << endl;
        if (!g[0] || !g[1]) continue;
        for (int i = 0; i < 2; i ++) {
            if (g[i] >= 3) g[i] = 1, l[i][0] = 1, r[i][0] = (1<<ii) - 1;
			else {
                x = get(s[i], pw);
				if (x % qw == 0) x += pw;
                get_r(s[i], f[i], x, ii, l[i][0], r[i][0]);
                if (g[i] > 1) {
					x += qw;
					get_r(s[i], f[i], x, ii, l[i][1], r[i][1]);
                }
			}
        }
        for (int i = 0; i < g[0]; i ++) for (int j = 0; j < g[1]; j ++) {
            chkmax(ans, min(r[0][i], r[1][j]) - max(l[0][i], l[1][j]) + 1);
        }
    }
    printf("%d\n", ans);
}