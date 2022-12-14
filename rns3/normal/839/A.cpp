#include <bits/stdc++.h>
using namespace std;

#define N 1010101

int n, k;

int a[N], s[N];

int cmp(int i, int j) {
	return i > j;
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		s[i] = s[i-1] + a[i];
	}
    int tot = 0, s = 0;
    for (int i = 1; i <= n; i ++) {
		s += a[i];
		tot += min(s, 8);
		s -= min(s, 8);
		if (tot >= k) {
			printf("%d\n", i);
			break;
		}
    }
    if (tot < k) {
		puts("-1");
		return 0;
    }

	return 0;
}