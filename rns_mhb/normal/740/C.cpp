#include <bits/stdc++.h>
using namespace std;

#define N 100010

int n, m, l[N], r[N], mn;

int main() {
    scanf("%d%d", &n, &m);
    mn = n;
    for (int i = 1; i <= m; i ++) {
		scanf("%d%d", &l[i], &r[i]);
		mn = min(r[i] - l[i] + 1, mn);
    }
    printf("%d\n", mn);
	for (int i = 1; i <= n; i ++) printf("%d ", i % mn);
}