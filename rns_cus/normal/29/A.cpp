#include <bits/stdc++.h>
using namespace std;

#define N 111

int n, x[N], d[N];

int main() {
///	freopen("a.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d %d", &x[i], &d[i]);
	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			if (x[i] + d[i] == x[j] && x[j] + d[j] == x[i]) {
				puts("YES"); return 0;
			}
		}
	}
	puts("NO");
	return 0;
}