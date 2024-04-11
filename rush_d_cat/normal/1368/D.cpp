#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n; LL a[N], c[23];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%lld", &a[i]);
		for (int j = 0; j < 22; j ++) {
			if (a[i] >> j & 1) c[j] ++;
		}
	}
	LL sum = 0;
	for (int i = 1; i <= n; i ++) {
		LL cur = 0;
		for (int j = 0; j < 22; j ++) {
			if (c[j]) {
				c[j] --; cur += (1<<j);
			}
		}
		sum += cur * cur;
	}
	cout << sum << endl;
}