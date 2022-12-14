#include <bits/stdc++.h>
using namespace std;

#define N 1010

char s[N][N];
int n, m, a, b, c, d, aa, bb, cc, dd, aaa, bbb, ccc, ddd;

int main() {
	scanf("%d %d\n", &n, &m);
	for (int i = 1; i <= n; i ++) gets(s[i] + 1);
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) {
		if (s[i][j] == 'S') a = i, b = j;
		else if (s[i][j] == 'T') c = i, d = j;
	}
	for (aa = a; aa >= 1; aa --) if (s[aa][b] == '*') break;
	aa ++;
	for (aaa = a; aaa <= n; aaa ++) if (s[aaa][b] == '*') break;
	aaa --;
    for (cc = c; cc >= 1; cc --) if (s[cc][d] == '*') break;
	cc ++;
	for (ccc = c; ccc <= n; ccc ++) if (s[ccc][d] == '*') break;
	ccc --;
	int y1, y2;
	y1 = b;
	y2 = d;
	if (y1 > y2) swap(y1, y2);
	int tag = 0;
	for (int i = aa; i <= aaa && !tag; i ++) {
		if (i >= cc && i <= ccc) {
			tag = 1;
			for (int j = y1; j <= y2 && tag; j ++) if (s[i][j] == '*') tag = 0;
		}
	}
	if(tag) {
		puts("YES");
		return 0;
	}
	for (bb = b; bb >= 1; bb --) if (s[a][bb] == '*') break;
	bb ++;
	for (bbb = b; bbb <= m; bbb ++) if (s[a][bbb] == '*') break;
	bbb --;
    for (dd = d; dd >= 1; dd --) if (s[c][dd] == '*') break;
	dd ++;
	for (ddd = d; ddd <= m; ddd ++) if (s[c][ddd] == '*') break;
	ddd --;
	int x1, x2;
	x1 = a;
	x2 = c;
	if (x1 > x2) swap(x1, x2);
	tag = 0;
	for (int j = bb; j <= bbb && !tag; j ++) {
		if (j >= dd && j <= ddd) {
			tag = 1;
			for (int i = x1; i <= x2 && tag; i ++) if (s[i][j] == '*') tag = 0;
		}
	}
	if(tag) {
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}