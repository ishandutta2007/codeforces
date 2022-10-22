#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)
using namespace std;
inline int read() {
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}
const int N = 1e5 + 5;
int n, a, b, p[N], fa[N], bel[N];
bool is[N][3], ans[N];
map<int, int> orz;
int cx(int x) {
	if (fa[x] != x) fa[x] = cx(fa[x]);
	return fa[x];
}
void zm(int x, int y) {
	int ix = cx(x), iy = cx(y);
	if (ix != iy) fa[iy] = ix;
}
int main() {
	int i;
	n = read(); a = read(); b = read();
	For (i, 1, n) orz[p[i] = read()] = i;
	For (i, 1, n) if (!orz[a - p[i]] && !orz[b - p[i]])
		return puts("NO"), 0;
	For (i, 1, n) fa[i] = i;
	For (i, 1, n) if (!orz[b - p[i]]) bel[i] = 1;
	For (i, 1, n) if (!orz[a - p[i]]) bel[i] = 2;
	For (i, 1, n) if (orz[a - p[i]]) zm(i, orz[a - p[i]]);
	For (i, 1, n) if (orz[b - p[i]]) zm(i, orz[b - p[i]]);
	For (i, 1, n) is[cx(i)][bel[i]] = 1;
	For (i, 1, n) if (is[i][1] && is[i][2])
		return puts("NO"), 0;
	puts("YES");
	For (i, 1, n) if (is[cx(i)][2]) ans[i] = 1;
	For (i, 1, n) printf("%d ", ans[i]);
	cout << endl;
	return 0;
}