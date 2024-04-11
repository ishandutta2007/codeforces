#include <bits/stdc++.h>
using namespace std;
#define N 101

int c[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int a[N], ex[N], f[N], g[N], F[N], L, R;

int calc(int n) {
	if (!n) return 0;
	int m = 0;
	while (n) a[++m] = n % 10, n /= 10;
	int rlt = F[m-1], x = 0;
	for (int i = m; i >= 1; i --) {
		int st = (i == m) ? 1 : 0;
		for (int j = st; j < a[i]; j ++) rlt += (x + c[j]) * ex[i-1] + g[i-1];
		x += c[a[i]];
	}
	rlt += x;
	return rlt;
}

int main() {
//	freopen("b.in", "r", stdin);
	ex[0] =  1;
	for (int i = 1; i <= 9; i ++) ex[i] = ex[i-1] * 10;
	int sum = 0;
	for (int i = 1; i <= 9; i ++) sum += c[i];
	for (int i = 1; i <= 9; i ++) {
		f[i] = sum * ex[i-1] + 9 * g[i-1];
		g[i] = (sum + c[0]) * ex[i-1] + 10 * g[i-1];
	}
	for (int i = 1; i <= 9; i ++) F[i] = F[i-1] + f[i];
	scanf("%d %d", &L, &R);
	cout << calc(R) - calc(L - 1) << endl;
	return 0;
}