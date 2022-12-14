#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	for (int h = 0; h < T; ++h) {
		int a, b, n, ans = 0;
		scanf("%d %d %d", &a, &b, &n);
		if (a > b) swap(a, b);
		while (b <= n) {
			b += a;
			a = b - a;
			++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}