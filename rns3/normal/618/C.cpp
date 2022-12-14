#include <bits/stdc++.h>
using namespace std;
#define ep 1e-10
typedef long long LL;

struct pnt {
	LL x, y;
	pnt (LL x = 0, LL y = 0) : x(x), y(y) {}
	pnt operator - (pnt a) {return pnt(x - a.x, y - a.y);}
	LL operator ^ (pnt a) {return x * a.y - y * a.x;}
	LL operator & (pnt a) {return x * a.x + y * a.y;}
} p[100010];

int main() {
//	freopen("C.in", "r", stdin);
	int n, x = 0, y = 1, z;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%I64d %I64d", &p[i].x, &p[i].y);
    for (int i = 2; i < n; i++) {
    	LL tmp = ((p[x] - p[i]) ^ (p[i] - p[y]));
        if (!tmp && ((p[i] - p[x]) & (p[i] - p[y])) < 0) x = i;
    }
    LL mn = 5 * (1e18);
    for (int i = 0; i < n; i++) {
    	if (i == x || i == y) continue;
		LL tmp = abs((p[x] - p[i]) ^ (p[i] - p[y]));
		if (!tmp) continue;
		if (tmp < mn) mn = tmp, z = i;
    }
    printf("%d %d %d\n", x + 1, y + 1, z + 1);
}