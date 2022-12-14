#include <bits/stdc++.h>
using namespace std;
#define M 100100

int n;
int f[M];

int main() {
	///freopen("335_A1.in", "r", stdin);
	scanf("%d", &n);
	for (int x, i = 1; i <= n; i++) {
		scanf("%d", &x);
		f[x] = f[x-1] + 1;
	}
	printf("%d\n", n - *max_element(f + 1, f + n + 1));
	return 0;
}