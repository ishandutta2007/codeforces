#include <bits/stdc++.h>
using namespace std;

#define N 100010

int n, m, x, k, w[N];

long long cons[N];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	cons[0] = 0;
	for (int i = 1; i < N; i ++) {
		cons[i] = 1ll * i * (i - 1) / 2 + 1;
		if (i % 2 == 0) cons[i] += i / 2 - 1;
	}
	scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i ++) scanf("%d %d", &x, &w[i]);
    int ans = 0;
    while (n >= cons[ans+1]) ans ++;
    ans = min(ans, m);
    sort (w + 1, w + m + 1, cmp);
    long long rlt = 0;
    for (int i = 1; i <= ans; i ++) rlt += w[i];
    printf("%I64d\n", rlt);
	return 0;
}