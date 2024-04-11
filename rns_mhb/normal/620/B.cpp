#include <bits/stdc++.h>
using namespace std;

int f[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
	int L, R;
	scanf("%d %d", &L, &R);
	int ans = 0;
	for (int i = L; i <= R; i ++) {
		int x = i;
		while (x) {
			ans += f[x%10];
			x /= 10;
		}
	}
	printf("%d\n", ans);

	return 0;
}