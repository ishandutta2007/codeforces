#include <bits/stdc++.h>
using namespace std;

#define N 300030

int n, a[2][N], st[2], en[2], now[2], tag;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[0][i]);
	for (int i = 1; i < n; i ++) a[1][i] = min(a[0][i], a[0][i+1]);
	tag = n % 2;
    st[tag] = n / 2 + 1, en[tag] = st[tag] - 1;
    now[tag] = 0;
    st[1-tag] = en[1-tag] = (n + 1) / 2;
	now[1-tag] = a[1-tag][st[1-tag]];
	if (n == 1) printf("%d", a[0][1]);
	for (int k = 0; k < n - 1; k ++) {
        tag = (n - k) % 2;
        now[tag] = max(now[tag], a[tag][--st[tag]]);
        now[tag] = max(now[tag], a[tag][++en[tag]]);
        printf("%d ", now[tag]);
        if (k == n - 2) printf("%d\n", now[tag]);
	}
    return 0;
}