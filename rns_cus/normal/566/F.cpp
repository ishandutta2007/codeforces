#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define M 1000010
int a[M], f[M], id[M], n;

int main(){
//	freopen("F.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
//	int n = 1000000; for (int i = 1; i <= n; i++) a[i] = i;	random_shuffle(a + 1, a + n + 1);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) id[a[i]] = i;
    for (int i = 1; i <= n; i++) {
		int x = 2 * a[i];
		if (!f[i]) f[i] = 1;
		while (x <= a[n]) {
			int t = id[x];
			if (t) f[t] = max(f[i] + 1, f[t]);
			x += a[i];
		}
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) if (ans < f[i]) ans = f[i];
    printf("%d\n", ans);
    return 0;
}