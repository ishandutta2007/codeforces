#include <stdio.h>
#include <algorithm>
using namespace std;

int a[300000];

int n, m, x;

int main() {
	///freopen("b.in", "r", stdin);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for(int j = 1; j <= m; j ++) {
        scanf("%d", &x);
		int y = upper_bound(a + 1, a + n + 1, x) - a;
        printf("%d ", y - 1);
    }
}