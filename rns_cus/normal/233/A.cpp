#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d", &n);
	if (n & 1) {
		puts("-1"); return 0;
	}
	for (int i = 1; i < n; i += 2) printf("%d %d ", i + 1, i);
	return puts(""), 0;
}