#include <bits/stdc++.h>
using namespace std;


#define N 111

int n, a[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
		scanf("%d", &n);
		int s = 0;
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), s += a[i];
		if (s & 1) {
			puts("T");
			continue;
		}
		if (2 * *max_element(a + 1, a + n + 1) <= s) puts("HL");
		else puts("T");
    }

    return 0;
}