#include <bits/stdc++.h>

using namespace std;

int n;
bool a[105];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		a[x] = true;
	}
	int cnt = 0;
	for (int i = 1; i <= 100; ++i)
		if (a[i]) {
			++cnt;
			for (int j = i; j <= 100; j += i)
				a[j] = false;
		}
	printf("%d\n", cnt);
}