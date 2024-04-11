#include <bits/stdc++.h>
using namespace std;
#define N 200005

int a[N], n;
const int inf = 1e9;

int func(int k) {
	return k < 0 ? -k : k;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    int mx = 1;
    for (int i = 1; i < n; i ++) {
		mx = max(mx, func(a[i] - a[i+1]));
        if (a[i] == a[i+1]) {puts("NO"); return 0;}
    }
	int x = (a[1] - 1) / mx, y = (a[1] - 1) % mx + 1, nx, ny;
	for (int i = 2; i <= n; i ++) {
		nx = (a[i] - 1) / mx, ny = (a[i] - 1) % mx + 1;
		if (func(nx - x) + func(ny - y) <= 1) {x = nx, y = ny;continue;}
        puts("NO");
        return 0;
	}
	printf("YES\n%d %d\n", inf, mx);
	return 0;
}