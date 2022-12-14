#include <bits/stdc++.h>
using namespace std;
#define M 200010
typedef long long LL;

LL a[M], f[M], g[M];
int n, m, x;

int main() {
//	freopen("B.in", "r", stdin);
	scanf("%d %d %d", &n, &m, &x);
	for (int i = 1; i <= n; i++) scanf("%I64d", a + i);
    sort(a + 1, a + n + 1);
    LL ans = 0, t = 1;
    for (int i = 0; i < m; i++) t = t * x;
    for (int i = 1; i <= n; i++) f[i] = (f[i-1] | a[i]);
    for (int i = n; i; i--) g[i] = (g[i+1] | a[i]);
    for (int i = 1; i <= n; i++) {
    	LL tmp = ((f[i-1] | g[i+1]) | (t * a[i]));
		if (ans < tmp) ans = tmp;
    }
    printf("%I64d\n", ans);
}