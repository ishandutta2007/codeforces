#include <bits/stdc++.h>
using namespace std;
#define N 100100

typedef unsigned long long LL;

LL b[N], f[N][12];
int n, k, a[N];

void  add(int k, LL val) {
	while(k < N) {
		b[k] += val;
		k += k & -k;
	}
}

LL calc(int k) {
	LL rlt = 0;
	while (k) {
		rlt += b[k];
		k -= k & -k;
	}
	return rlt;
}

void init() {
	for (int i = 0; i < N; i ++) b[i] = 0;
}

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i ++) f[i][0] = 1;
	for (int i = 1; i <= k; i ++) {
		init();
        for (int j = 1; j <= n; j ++) {
			f[j][i] = calc(a[j] - 1);
			add(a[j], f[j][i-1]);
        }
	}
	LL ans = 0;
	for (int i = 1; i <= n; i ++) ans += f[i][k];
	cout << ans << endl;
}