#include <bits/stdc++.h>
using namespace std;

int x, a[100100], n, m;
long long A, B;

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &x), a[x] = i;
	}
	scanf("%d", &m);
	while (m --) {
		scanf("%d", &x);
		A += a[x], B += n - a[x] + 1;
	}
	cout << A << ' ' << B << endl;
	return 0;
}