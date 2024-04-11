#include <bits/stdc++.h>
using namespace std;

#define N 100010
#define M 50

int n, a[M], b[M], c[M], d[M];
long long kkk[N];

int main() {
	scanf("%d", &n);
	for (int i = 1, j = 0; i <= n; i ++) {
		scanf("%I64d", &kkk[i]);
		if (kkk[i] == 1ll << j) a[j] ++;
		else if (kkk[i] < (1ll << (j + 1))) b[j+1] ++;
		else {
			while (kkk[i] >= (1ll << (j + 1))) j ++;
			if (kkk[i] == 1ll << j) a[j] ++;
			else b[j+1] ++;
		}
	}
	int bb = 0;
	for (int j = 1; j < M; j ++) bb += b[j];
	for (int i = 0; i < M - 1; i ++) {
		c[i] = a[i] - bb;
		bb -= b[i+1];
		if (c[i] < 0) {
			puts("-1");
			return 0;
		}
	}
    for (int i = 1, last = b[1]; i < M - 1; i ++) {
		d[i] = max(0, c[i] - last);
		last = c[i] - d[i] + b[i+1];
    }
    d[0] = c[0];
	int k;
	for (k = (d[0] + 1) / 2; k <= d[0]; k ++) {
		bool tag = 1;
		int now = d[0] - k, kk = k;
		for (int i = 1; i < M - 2 && tag; i ++) {
            if (d[i] > kk) {
                now += (d[i] - kk);
				if (now > kk) tag = 0;
            }
            else {
                now -= (d[i] - kk);
				if (now < 0) now = 0;
                kk = d[i];
            }
		}
		if (tag) {
			for (int i = a[0] - d[0] + k; i < a[0]; i ++) printf("%d ", i);
			printf("%d\n", a[0]);
			break;
		}
	}
	if (k > d[0]) puts("-1");
	return 0;
}