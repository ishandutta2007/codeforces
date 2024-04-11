#include <bits/stdc++.h>
using namespace std;

#define N 400010

typedef long long ll;
typedef long double ldb;

int n, a[N], brr[N], gas;
ll sum[N];

ldb f(int mid, int w) {
	return 1.0l * (sum[n] - sum[n-w] + sum[mid-1] - sum[mid-w-1] - 2ll * a[mid] * w) / (2 * w + 1);
}

int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", a + i);
	}

	sort(a + 1, a + n + 1);

	sum[0] = 0;
	for (int i = 1; i <= n; i ++) {
		sum[i] = sum[i-1] + a[i];
	}

	if (n <= 2) { printf("1\n%d\n", a[1]); return 0; }

	int vid = 1, cnt = 0;
	ldb tmp = 0;

	for (int id = 2; id < n; id ++) {
		int width = 0;
		for (int bit = (1 << 20); bit; bit >>= 1) {
			width += bit;
			if (width >= id || width > n - id) { width -= bit; continue; }
			if (f(id, width) < f(id, width - 1)) width -= bit;
		}
		ldb now = f(id, width);
		if (tmp < now) {
			tmp = now;
			vid = id;
			cnt = width;
		}
	}

	printf("%d\n", 2 * cnt + 1);
	for (int i = cnt; i >= 0; i --) {
		printf("%d ", a[vid - i]);
	}

	for (int i = cnt; i > 0; i --) {
		printf("%d ", a[n + 1 - i]);
	}
}