#include <cstdio>

using namespace std;

int N, K;

int main() {
	scanf("%d %d", &N, &K);

	int ans = 0;
	bool found = false;
	for(int i = 0; i < N; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		int joy = a;
		if (b > K) {
			joy -= (b - K);
		}
		if (!found) {
			found = true;
			ans = joy;
		} else if (joy > ans) ans = joy;
	}
	printf("%d\n", ans);
	return 0;
}