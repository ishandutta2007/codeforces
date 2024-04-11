#include <bits/stdc++.h>
using namespace std;
#define f1(i, a, b) for (int i = a; i <= b; i ++)
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define N 100005

int a[N], g[N<<2];
int n, k;

void func(int l, int r, int seg) {
    if (k >= 2 * (r - l - 1)) {
        k -= 2 * (r - l - 1);
        sort(a + l, a + r);
		return;
    }
    int mid = l + r >> 1;
    func(l, mid, seg << 1);
    func(mid, r, seg << 1 | 1);
    return;
}

int main() {
    scanf("%d %d", &n, &k);
    f0(i, 0, n) a[i] = n - i;
    if (!(k & 1) || k > 2 * n - 1) puts("-1");
    else {
        k = 2 * n - 1 - k;
		func(0, n, 1);
		f0(i, 0, n) printf("%d ", a[i]);
    }
	return 0;
}