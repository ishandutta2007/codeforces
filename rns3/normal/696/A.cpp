#include <bits/stdc++.h>
using namespace std;

#define N 1010
typedef long long LL;

LL u[N], v[N], w[N], x, y;
int e = 0, T, type;
LL g[N], h[N];

int func(LL x, LL y, LL u, LL v) {
	int p = 0, q = 0, cnt = 0;
	while (1) {
        if (x > y) {
			g[++p] = x;
			x >>= 1;
        }
        else if (x == y) {
			g[++p] = x;
			break;
        }
		else {
			g[++p] = y;
			y >>= 1;
		}
	}
	while (1) {
		if (u > v) {
			h[++q] = u;
			u >>= 1;
		}
		else if (u == v) {
			h[++q] = u;
			break;
		}
		else {
			h[++q] = v;
			v >>= 1;
		}
	}
	sort (g + 1, g + p + 1);
	sort (h + 1, h + q + 1);
	for (int i = 1, j = 1; i <= p && j <= q;) {
		if (g[i] < h[j]) i ++;
		else if (g[i] == h[j]) i ++, j ++, cnt ++;
		else j ++;
	}
	return max(cnt - 1, 0);
}

int main() {
	scanf("%d", &T);
	while (T --) {
		scanf("%d", &type);
		if (type == 1) {
			e ++;
			scanf("%I64d %I64d %I64d", &u[e], &v[e], &w[e]);
		}
		else {
			LL rlt = 0;
			scanf("%I64d %I64d", &x, &y);
			for (int i = 1; i <= e; i ++) {
				rlt += w[i] * func(x, y, u[i], v[i]);
			}
			printf("%I64d\n", rlt);
		}
	}
	return 0;
}