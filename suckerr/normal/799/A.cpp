#include <bits/stdc++.h>

using namespace std;

int n, k, d, t;

int main() {
	scanf("%d %d %d %d", &n, &t, &k, &d);
	int num = (n + k - 1) / k;
	int ans1 = num * t;
	int s = 0, ans2 = 0;
	while (num && s < d) {
		ans2 = (s += t);
		num--;
	}
	while (num) {
		ans2 = (d += t);
		if (--num > 0) {
			ans2 = (s += t);
			--num;
		}
	}
	if (ans1 > ans2) {
		puts("YES");
	} else {
		puts("NO");
	}
	return 0;
}