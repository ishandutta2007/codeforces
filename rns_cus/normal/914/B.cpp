#include <bits/stdc++.h>
using namespace std;

#define N 101010

int a[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	bool ans = 1;
	if (n % 2 == 1) ans = 0;
	for (int i = 1; i < n && ans; i += 2) if (a[i] != a[i+1]) ans = 0;
	if (!ans) puts("Conan");
	else puts("Agasa");

	return 0;
}